# include <iostream>
using namespace std;

void InsertionSort (int A[], int n){
	for (int i = 1; i < n; i++){			// This loop runs the passes or iteration
		int j = i - 1;						// Another pointer to check elements from the end of sorted part
		int x = A[i];						// Variable to store the element taken out for insertion from unsorted part
		while (j > -1 && A[j] > x){			// Loop to compare elements in the sorted part with the insertion element
			A[j+1] = A[j];					// Shifting of sorted elements when they are greater than the insertion element
			j--;							// To move back in the sorted part of the array, since we are checking from the end
		}
		A[j+1] = x;							// Inserting the taken out element to the sorted part of the array
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
    InsertionSort(A,n);
    printArr(A,n);
}