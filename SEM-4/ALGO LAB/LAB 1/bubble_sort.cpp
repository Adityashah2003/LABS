#include<bits/stdc++.h>
using namespace std;

int counter=0;
void BubbleSort(int arr[],int n){
    for(int i=0; i<n; i++){
            counter++;  //i-loop
         for(int j=1; j<n; j++){
            counter++;  //j-loop
            counter++;  //if
            if(arr[j-1]>arr[j]){
                counter++; //swap
                swap(arr[j-1],arr[j]);
            }
        }
        counter++;  //j+1
    }
    counter++;  //i+1
}
int main(){
    int n=5;
    int arr[n] = {3,4,5,6,7};
    BubbleSort(arr,n);
    cout<<counter<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}