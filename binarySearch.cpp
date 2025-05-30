#include <iostream>
#include <cmath>
using namespace std;

void binarySearchArray(int arr[], int size, int item){
    int B = 0;
    int E = size - 1;
    int mid = -1;
    while (B + 1 != E){
        mid = floor((B+E)/2);
        if (arr[mid] < item){
            B = mid;
        }
        else if (arr[mid] > item){
            E = mid;
        }
        else if (arr[mid] == item){
            cout << "Item " << item << " found at index " << mid << endl;
            break;
        }
    }
    if (arr[mid] != item){
        cout << "Item " << item << " was not found in the array." << endl;
    }
}

int main(){
    cout << "Enter the number of elements in the array: ";
    int size;
    cin >> size;
    cout << "Enter " << size << " elements:" << endl;
    int arr[size]; //array should be sorted
    for (int i = 0; i < size; i++){
        cout << "Enter element number " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Now enter the item being searched: ";
    int item;
    cin >> item;
    binarySearchArray(arr, size, item);
}