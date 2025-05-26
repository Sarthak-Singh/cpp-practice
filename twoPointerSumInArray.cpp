#include <iostream>
using namespace std;

int sumIndicesFinder(int arr[], int size, int Sum){
    int smaller = 0;
    int larger = size - 1;
    for (int i = 0; i < size; i++){
        if (arr[smaller] + arr[larger] == Sum){
            cout << "The indices of the elements in the array are: " << smaller << " and " << larger << endl;
            cout << "And the elements at those positions are: " << arr[smaller] << " and " << arr[larger] << endl;
            return 0;
        }
        else if (arr[smaller] + arr[larger] > Sum){
            larger = larger - 1;
        }
        else if (arr[smaller] + arr[larger] < Sum){
            smaller = smaller + 1;
        }
        else if (smaller == larger){
            break;
        }
    }
    cout << "No 2 elements are making the sum = " << Sum << endl;
    return 0;
}

int main(){
    cout << "Enter the size of the array:" << endl;
    int size;
    cin >> size;
    cout << "Enter " << size << " elements of the array:" << endl;
    int arr[size];
    for (int i = 0; i < size; i++){
        cout << "Enter element " << i+1 << " : ";
        cin >> arr[i];
    }
    cout << "Enter the required sum: ";
    int Sum;
    cin >> Sum;
    sumIndicesFinder(arr, size, Sum);
    return 0;
}