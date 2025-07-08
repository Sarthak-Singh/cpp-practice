# include <iostream>
using namespace std;

void BubbleSort(int A[], int n){
	int flag;
	for (int i = 0; i < n-1; i++){
		flag = 0;
		for (int j = 0; j < n-1-i; j++){
			if (A[j] > A[j+1]){
				swap(A[j],A[j+1]);
				flag = 1;
			}
		}
		if (flag == 0){
			break;
		}
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
    BubbleSort(A,n);
    printArr(A,n);
}
