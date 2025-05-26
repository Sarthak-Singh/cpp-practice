#include <iostream>
using namespace std;

void printsecondlargest(int arr[], int size) {
    int first = arr[0], second = arr[1];
    for (int i = 2; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    cout << "The second largest element in the array is: " << second << endl;
}

int main() {
    int size;
    // Prompt user for the size of the array
    cout << "This program finds the second largest element in an array." << endl;
    // Prompt user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size]; // Declare an array of size 'size'
    // Prompt user to enter elements of the array
    cout << "Enter " << size << " elements of the array:" << endl;
    // Loop to input elements into the array
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    printsecondlargest(arr, size);
    return 0;
}