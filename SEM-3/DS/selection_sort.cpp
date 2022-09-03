// C++ program for implementation of
// selection sort
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
	int i, j, min_idx,temp=0;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
		if(min_idx!=i){
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;}
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
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
	selectionSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
