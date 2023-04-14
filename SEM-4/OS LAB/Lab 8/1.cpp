#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the number of processes(m): ";
    cin>>m;
    cout<<"Enter the number of resources(n): ";
    cin>>n;

    int allocation[m][n], max[m][n], need[m][n], available[n];
    cout<<"Enter the Max matrix :\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>max[i][j];
        }
    }
    cout<<"Enter the Allocation matrix :\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>allocation[i][j];
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    cout<<"Enter the available vector:\n";
    for(int i=0;i<n;i++)
        cin>>available[i];

    int work[n], finish[m], safestate[m];
    memcpy(work, available, sizeof(available));

    int i=0, idx = 0;
    while(i<m){
        int inside = 0;
        int success = 1;
        for(int j=0;j<n;j++){
            if(need[i][j]>work[j]){
                success = 0;
                break;
            }
        }
        if(success){
            inside = 1;
            safestate[idx++] = i;
            for(int k = 0;k<n; k++)
                work[k] += allocation[i][k];
            finish[i]=1;
        }
        i++;
    }
    if(idx==m){
        cout<<"System is in safe state.\nSafe sequence is: ";
        for(int i=0;i<m;i++)
            cout<<safestate[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<"System is in unsafe state.\n";
    }
    return 0;
}
