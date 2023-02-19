#include<bits/stdc++.h>
using namespace std;

int counter=0;
int flag=0;

void BinarySearch(int arr[], int start, int last, int target){
    while(start<=last){
        counter++; //while loop
        int mid = (start+last)/2;
        counter++; //mid
        counter++; //if
        if(arr[mid]==target){
            counter++; //counter
            flag = 1;
            break;
        }
        else if(arr[mid]<target){
                counter++; //else-if
                counter++; //start
            start = mid+1;
        }
        else if (arr[mid]>target){
            // else if is false & last
            counter+=3;
            last = mid-1;
        }
    }
    if(flag ==1)
        cout<<"found";
    else
        cout<<"Not found";
    counter++; //for a extra while condition check
}

int main(){

    int arr[20] = {4,5,6,7,8,9,10};
    BinarySearch(arr,0,6,10);
    cout<<"Steps:"<<counter;
}
