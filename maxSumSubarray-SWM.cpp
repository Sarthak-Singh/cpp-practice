#include <iostream>
using namespace std;

void maxSumSubarraySWM(int arr[], int size, int Ssize){
    int maxSum = 0, currentSum = 0;
    for (int i = 0; i < Ssize; i++){
        currentSum += arr[i];
    }
    maxSum = currentSum;
    for (int j = 1; j < size - Ssize + 1; j++){
        currentSum = currentSum - arr[j-1] + arr[j+Ssize-1];
        if (currentSum > maxSum){
            maxSum = currentSum;
        }
    }
    cout << "The maximum sum of the subarrays is: " << maxSum << endl;
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
    cout << "Now enter the size of the subarray needed: ";
    int Ssize;
    cin >> Ssize;
    maxSumSubarraySWM(arr, size, Ssize);
    return 0;
}