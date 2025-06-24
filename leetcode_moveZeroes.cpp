#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& arr){
    // Using standard 2-pointer method
    int L = 0;
    for (int R = 0; R < arr.size(); R++) {
        if (arr[R] != 0) {
            if (L != R) {
                arr[L] = arr[R];
                arr[R] = 0;
            }
            L += 1;
        }
    }
}

void printArray(vector<int>& arr){
    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    int size, num;
    cout << "Enter the number of elements in the array: ";
    cin >> size;
    vector<int> arr;
    for (int i = 0; i < size; i++){
        cout << "Enter element number " << i+1 << ": ";
        cin >> num;
        arr.push_back(num);
    }
    printArray(arr);
    moveZeroes(arr);
    printArray(arr);
}