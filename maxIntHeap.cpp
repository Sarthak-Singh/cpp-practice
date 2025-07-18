#include <iostream>
#include <vector>
using namespace std;

class maxIntHeap{
    private:
        int capacity;
        int size;
        vector<int> items;  // Vector representation of the Heap
    
    public:
        maxIntHeap(){
            this->capacity = 10;
            this->size = 0;
            items.reserve(capacity);
        }
        maxIntHeap(int capacity){
            this->capacity = capacity;
            this->size = 0;
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
        
        // Swapping two values in the heap, used in bubbling up and down.
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
            cout << "Peek value of the heap is: " << items[0] << endl;
            return items[0];
        }

        // Removes and return the root or the first element of the heap
        int poll(){
            if (size == 0){
                cout << "There are no elements in the heap." << endl;
                return -1;
            }
            int index = 0;
            int item = items[index];
            items[index] = items[size - 1];
            size--;
            bubbleDown(index);
            cout << "Polled out value from the heap is: " << item << endl;
            return item;
        }

        // Function to find and delete a particular value in the given heap
        void remove(int item){
            int index = find(item);
            if (index != -1){
                items[index] = items[size-1];
                size--;
                bubbleDown(index);
            }
        }

        // Adds the element to the end of the heap
        void add(int item){
            ensureExtraCapacity();
            int index = size;
            items.push_back(item);
            size++;
            bubbleUp(index);
        }

        // To print the heap's corresponding vector
        void print(){
            for (int i = 0; i < size; i++){
                cout << items[i] << " ";
            }
            cout << endl;
        }

        // To check if an element exists in the heap, and if it does, return its index
        int find(int item){
            for (int index = 0; index < size; index++){
                if (items[index] == item){
                    cout << "The element '" << item << "' was found at index '" << index << "' in the heap." << endl;
                    return index;
                }
            }
            cout << "The element '" << item << "' was not found in the heap." << endl;
            return -1;
        }
    
    
    private:
        // Heapify or Bubble methods to maintain the property of the min heap
        void bubbleDown(int index){
            while (hasLeftChild(index)){
                int greaterChildIndex = getLeftChildIndex(index);
                if (hasRightChild(index) && rightChild(index) > leftChild(index)){
                    greaterChildIndex = getRightChildIndex(index);
                }
                
                if (items[index] < items[greaterChildIndex]){
                    swap(index, greaterChildIndex);
                }
                else{
                    break;
                }
                index = greaterChildIndex;
            }
        }
        void bubbleUp(int index){
            while (hasParent(index) && parent(index) < items[index]){
                swap(index, getParentIndex(index));
                index = getParentIndex(index);
            }
        }
};

int main(){
    cout << "Enter the number of elements in the heap: ";
    int size;
    cin >> size;
    maxIntHeap* heap = new maxIntHeap();
    for (int i = 0; i < size; i++){
        cout << "Enter the element number " << i+1 << ": ";
        int value;
        cin >> value;
        heap->add(value);
    }
    cout << "================================" << endl;
    heap->print();
    heap->peek();
    heap->poll();
    heap->print();
    heap->find(6);
    heap->remove(11);
    heap->print();
}
