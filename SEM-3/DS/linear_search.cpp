#include<iostream>
using namespace std;
#define MAXSIZE 100

int main(){
    int a[MAXSIZE];
    int i,n,key,flag=0;

    cout<<"Enter the size of array: "<<endl;
    cin>>n;

    cout<<"Enter the values"<<endl;
    for (i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the number to be found"<<endl;
    cin>>key;
    for(i=0;i<=n;i++){
        if(a[i]==key)
            flag=1;
    }
    if(flag==1)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
}
