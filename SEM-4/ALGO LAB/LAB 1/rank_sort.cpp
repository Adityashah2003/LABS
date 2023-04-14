#include <bits/stdc++.h>
using namespace std;

int r[20];
void rank1(int arr[],int n){  
    int i=0;
    for(i=0;i<n;i++)
        r[i]=0;
    for(i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>=arr[j])
                r[i]++;
            else
                r[j]++;
        }
    }
}
void rank_sort(int a[],int n){
    rank1(a,n);
    int u[20];
    int i=0;
    for(i=0;i<n;i++){
        u[r[i]]=a[i];
    }
    for(i=0;i<n;i++){
        a[i]=u[i];
    }
    for(i=0;i<n;i++){
        cout<<a[i];
    }
}

int main(){
    int a[10];
    int n=0;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    rank_sort(a,n);
}