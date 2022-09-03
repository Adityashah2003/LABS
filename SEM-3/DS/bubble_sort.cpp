#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
	int i, j,temp;
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1]){
                temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;}
		}
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
    int n=0;
    int arr[100];
	cout<<"Enter the size of array"<<endl;
    cin>>n;
    cout<<"Enter the values"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	bubbleSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

