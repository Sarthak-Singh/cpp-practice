#include <iostream>
using namespace std;

void removeDuplicatesInSortedArrayWithSameArray(int arr[], int size){
    int j = 0;
    for (int i = 1; i < size; i++){
        if (arr[j] != arr[i]){
            j += 1;
            arr[j] = arr[i];
        }
    }
    cout << "The formatted array is :" << endl;
    for (int k = 0; k < j+1; k++){
        cout << arr[k] << " ";
    }
}

int main(){
    cout << "Enter the number of elements in the array: ";
    int size;
    cin >> size;
    cout << "Enter " << size << " elements of the array: " << endl;
    int arr[size];
    for (int i = 0; i < size; i++){
        cout << "Enter element number " << i+1 << ": ";
        cin >> arr[i];
    }
    removeDuplicatesInSortedArrayWithSameArray (arr, size);
    return 0;
}