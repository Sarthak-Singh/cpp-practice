#include <iostream>
using namespace std;

void linearSearchArray(int arr[], int size, int item){
    int index = -1;
    for (int i = 0; i < size; i++){
        if (arr[i] == item){
            index = i;
            break;
        }
    }
    if (index == -1){
        cout << "The item " << item << " was not found in the given array." << endl;
    }
    else{
        cout << "The item " << item << " is at position " << index << " in the given array." << endl;
    }
}

int main(){
    cout << "Enter the number of elements in the array: ";
    int size;
    cin >> size;
    cout << "Enter " << size << " elements:" << endl;
    int arr[size];
    for (int i = 0; i < size; i++){
        cout << "Enter element number " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Now enter the item being searched: ";
    int item;
    cin >> item;
    linearSearchArray(arr, size, item);
}