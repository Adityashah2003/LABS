/* LAB-1:
    2)Binary Search - Elements of the given array must be
        sorted either in ascending or descending order */

#include<iostream>
using namespace std;
#define MAXSIZE 100

int binarysearch(int a[], int key, int low, int high){
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==key){
        return mid;
        }
        if(key>a[mid]){
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}

int main(){
        int n, a[MAXSIZE];
        int i, key;
        int result;

//INPUT FROM USER:
    cout<<"Enter the size of the array:";
    cin>>n;

    cout<<"Enter the elements of the array:";
    for(i=1; i<n+1; i++)
    cin>>a[i];

    cout<<"Enter the element to be found:";
    cin>>key;

//OPERATION:
    result = binarysearch(a, key, 0, n-1);

//OUTPUT:
    if(result==-1){
        cout<<"Element not found"<<endl;
    }
    else
        cout<<"Element found at position "<<result<<endl;

    return 0;    }



