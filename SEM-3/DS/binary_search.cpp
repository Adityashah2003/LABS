#include<iostream>
using namespace std;

int main(){
    int a[100];
    int n,i,key,flag,high,low=0;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    cout<<"Enter the values"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the no. to be found"<<endl;
    cin>>key;
    high = 0;
    low = n-1;
    int mid = (high+low)/2;

    do{
        if(a[mid] == key){
            flag=1;
        }
        else if(a[mid]>key){
            high = a[mid]-1;
        }
        else if(a[mid]<key){
            low = a[mid]+1;
        }
    }while(key!=a[mid]&&low<=high);

    if(flag==1)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
}
