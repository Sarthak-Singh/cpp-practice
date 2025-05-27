#include <iostream>
using namespace std;

void maxSumSubarrayBFM(int arr[], int size, int Ssize){
    int maxSum = 0;
    for (int i = 0; i < size - Ssize + 1; i++){
        int currentSum = 0;
        for (int j = i; j < i + Ssize; j++){
            currentSum += arr[j];
        }
        if (currentSum > maxSum){
            maxSum = currentSum;
        }
    }
    cout << "The maximum sum in the subarrays = " << maxSum << endl;
}

int main(){
    cout << "Enter the number of elements in the array: ";
    int size;
    cin >> size;
    cout << "Enter " << size << " elements:" << endl;
    int arr[size];
    for (int i = 0; i < size; i++){
        cout << "Enter element number " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Now enter the size of the required subarray: ";
    int Ssize;
    cin >> Ssize;
    maxSumSubarrayBFM(arr, size, Ssize); 
    return 0;
}