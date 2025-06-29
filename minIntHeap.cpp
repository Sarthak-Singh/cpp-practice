#include <iostream>
#include <vector>
using namespace std;

class minIntHeap{
    private:
        int size;
        int capacity;
        vector<int> items;  // Vector representation of the Heap
    public:
        minIntHeap(){
            this->size = 0;
            this->capacity = 10;
            items.reserve(capacity);
        }
        minIntHeap(int capacity){
            this->size = 0;
            this->capacity = capacity;
            items.reserve(capacity);
        }
    private:
        // Getting the index of child or parent
        int getLeftChildIndex(int parentIndex){return parentIndex*2 + 1; }
        int getRightChildIndex(int parentIndex){return parentIndex*2 + 2; }
        int getParentIndex(int childIndex){return (childIndex-1)/2; }

        // Checking if a child or parent exists
        bool hasLeftChild(int index){return getLeftChildIndex(index) < size; }
        bool hasRightChild(int index){return getRightChildIndex(index) < size; }
        bool hasParent(int index){return getParentIndex(index) >= 0; }

        // Getting the value of the child or parent
        int leftChild(int index){return items[getLeftChildIndex(index)]; }
        int rightChild(int index){return items[getRightChildIndex(index)]; }
        int parent(int index){return items[getParentIndex(index)]; }
        
        // Swapping two indices; used when deleting nodes from the Heap
        void swap(int indexOne, int indexTwo){
            int temp = items[indexOne];
            items[indexOne] = items[indexTwo];
            items[indexTwo] = temp;
        }
        // If the size of the heap reaches the capacity of the array, the capacity of array is doubled
        void ensureExtraCapacity(){
            if (size == capacity){
                capacity *= 2;
                items.reserve(capacity);
            }
        }
        
        public:
        // Return the first element or the root element of the heap, i.e. the first element in the vector
        int peek(){
            if (size == 0){
                cout << "There are no elements in the heap." << endl;
                return -1;
            }
            return items[0];
        }
        // Removes and return the root or the first element of the heap
        int poll(){
            if (size == 0){
                cout << "There are no elements in the heap." << endl;
                return -1;
            }
            int item = items[0];
            items[0] = items[size - 1];
            size --;
            bubbleDown();
            return item;
        }

        // Adds the element to the end of the heap
        void add(int item){
            ensureExtraCapacity();
            items[size] = item;
            size ++;
            bubbleUp();
        }

        // Heapify or Bubble methods to maintain the property of the min heap
        void bubbleDown(){
            int index = 0;
            while (hasLeftChild(index)){
                int smallerChildIndex = getLeftChildIndex(index);
                if (hasRightChild(index) && rightChild(index) < leftChild(index)){
                    smallerChildIndex = getRightChildIndex(index);
                }

                if (items[index] > items[smallerChildIndex]){
                    swap(smallerChildIndex, index);
                }
                else{
                    break;
                }
                index = smallerChildIndex;
            }
        }
        void bubbleUp(){
            int index = size - 1;
            while (hasParent(index) && parent(index) > items[index]){
                swap(index,getParentIndex(index));
                index = getParentIndex(index);
            }
        }

        // To print the heap's corresponding vector
        void print(){
            for (int i = 0; i < size; i++){
                cout << items[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    cout << "Enter the number of elements in the heap: ";
    int size;
    cin >> size;
    minIntHeap* heap = new minIntHeap();
    for (int i = 0; i < size; i++){
        cout << "Enter element number " << i+1 << " :";
        int item;
        cin >> item;
        heap->add(item);
    }
    heap->print();
    cout << "Peek value of the heap is: " << heap->peek() << endl;
    heap->print();
    cout << "Polling out from the heap. Value returned is: " << heap->poll() << endl;
    heap->print();
}