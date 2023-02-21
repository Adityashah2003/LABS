#include<bits/stdc++.h>
using namespace std;

int counter=0;
void insertionSort(int arr[], int n)
{
    int i, key, j;
    counter++;
    for (i = 1; i < n; i++){
        counter++;
        key = arr[i];
        j = i - 1;
        counter++;
        while (j >= 0 && arr[j] > key){
            counter++;
            swap(arr[j + 1],arr[j]);
            j = j - 1;
            counter++;
            counter++;
        }
        counter++;
        counter++;
        arr[j + 1] = key;
    }
    counter++;
}
int main(){
    int n=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    insertionSort(arr,n);
    cout<<"Total steps are: "<<counter;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

