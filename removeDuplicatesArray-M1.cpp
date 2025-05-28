#include <iostream>
using namespace std;

void removeDuplicatesInSortedArrayWithNewArray(int arr[], int size){
    int new_arr[size];
    new_arr[0] = arr[0];
    int j = 0;
    for (int i = 1; i < size; i++){
        if (arr[i] != new_arr[j]){
            j += 1;
            new_arr[j] = arr[i];
        }
    }
    cout << "The formatted array is: " << endl;
    for (int k = 0; k < j + 1; k++){
        cout << new_arr[k] << " ";
    }
}

int main(){
    cout << "Enter the number of elements in the array: ";
    int size;
    cin >> size;
    cout << "Enter " << size << " elements of the array:" << endl;
    int arr[size];
    for (int i = 0; i < size; i++){
        cout << "Enter element number " << i+1 << ": ";
        cin >> arr[i];
    }
    removeDuplicatesInSortedArrayWithNewArray (arr, size);
    return 0;
}