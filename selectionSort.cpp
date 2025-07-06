# include <iostream>
using namespace std;

void SelectionSort(int A[], int n){
    for (int i = 0; i < n-1; i++){
        int k = i, j = 0;
        for (j = i; j < n; j++){
            if (A[j] < A[k]){
                k = j;
            }
        }
        swap(A[i], A[k]);
    }
}

void printArr(int A[], int n){
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
}

int main(){
    cout << "Enter the number of elements in the array:";
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++){
        cout << "Enter element number " << i+1 << " :";
        cin >> A[i];
    }
    cout << "The sorted Array is:" << endl;
    SelectionSort(A,n);
    printArr(A,n);
}
