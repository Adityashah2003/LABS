#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        swap(arr[min_idx],arr[i]);
    }
}
int main(){
    int n=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    selectionSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
