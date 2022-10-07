#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 0; i < n; i++)
	{
	key = arr[i];
		for(j=i;j >= 0 && arr[j] > key;j--){
		arr[j + 1] = arr[j];
		j = j - 1;
		}
	arr[j + 1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
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
	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
