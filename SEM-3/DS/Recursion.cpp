
#include<iostream>
using namespace std;
#define MAXSIZE 100

int binarysearch(int a[], int key, int low, int high){
    int mid;
    mid=(low+high)/2;
    if(low>=high)
        return mid;
else{
    if(a[mid]==key)
        return binarysearch(a, key, mid, mid);
    else if(key>a[mid])
        return binarysearch(a, key, mid+1, high);
    else
        return binarysearch(a, key, low, mid-1);
    }
}

int MinIndex(int a[], int i, int j){
    if(i==j)
        return i;
    int k = MinIndex(a, i+1, j);
    return(a[i]<a[k])?i:k;
}

int selection_sort(int a[], int n, int index=0){
    int i, j, loc, min, temp;
    if(index==n)
        return n;
    int k= MinIndex(a, index, n-1);

    if(k!=index)
        swap(a[k], a[index]);
    selection_sort(a, n, index+1);
}

int Multiply_using_addition(int m, int n){
    if(m<n)
        return Multiply_using_addition(n,m);
    else if(n!=0)
        return(m+Multiply_using_addition(m, n-1));
    else
        return 0;
}

int main(){
        int m, n, a[MAXSIZE];
        int i, j, key;
        int result;
        int user_select;
        int product=0;// switch

    cout<<"Menu:"<<endl;
    cout<<"1.Binary search using recursion:"<<endl;
    cout<<"2.Selection sort using recursion:"<<endl;
    cout<<"3.Multiplication of two numbers with repeated addition:"<<endl;
    cin>>user_select;

    switch(user_select){
    case 1:{
    cout<<"Enter the size of the array.";
    cin>>n;

    cout<<"Enter the elements of the array.";
    for(i=1; i<n+1; i++)
    cin>>a[i];

    cout<<"Enter the element to be found.";
    cin>>key;
    result = binarysearch(a, key, 1, n);

    if(result==-1){
        cout<<"Element not found"<<endl;
    }
    else
        cout<<"Element found at position "<<result<<endl;
        break;
    }


    case 2:{
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    cout<<"Enter the elements of the array"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Sorted array is:"<<endl;
    result = selection_sort(a, n);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    break;
        }

    case 3:{
        cout<<"Enter two numbers:";
        cin>>m>>n;

        result = Multiply_using_addition(m, n);
        cout<<"Product: "<<result<<endl;
        break;

    }
    default:{
        cout<<"Invalid input"<<endl;
        break;
    }

    }

    return 0;
}


