#include<bits/stdc++.h>
using namespace std;

int counter=0;

bool BinarySearch(int arr[], int low, int high, int target){
    int mid = (low+high)/2;
    counter++; //mid
    counter++; //if
    if(low>high){
        cout<<"Not Found";
        counter++; //return
        return -1;
    }
    counter++; //if
    if(arr[mid]==target){
        counter++; //return
        cout<<"Found";
        return true;
    }

    counter++;  //if
    if(arr[mid]<target){
        counter++; //recursion
        return BinarySearch(arr,mid+1,high,target);
    }
    counter++; //if
    if(arr[mid]>target){
        counter++; //recursion
        return BinarySearch(arr,low,mid-1,target);
    }
}

int main(){
    int arr[20] = {4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    BinarySearch(arr,0,19,23);
    cout<<"Steps:"<<counter;
}

