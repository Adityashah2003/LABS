#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int i,j,status,n,s;
    cout<<"Enter n";
    cin>>n;
    char a[5][20],temp[20],sm[20];
    cout<<"Enter the strings\n";
    for(i=0;i<n;i++)
        cin>>a[i];

    pid_t pid1, pid2;
    pid1 = fork();

    if (pid1 == 0) {
        for(i=0;i<n;i++){
            for(j=0;j<n-i;j++){
                if(strcmp(a[j],a[j+1]) >0 ){
                    strcpy(temp,a[j]);
                    strcpy(a[j],a[j+1]);
                    strcpy(a[j+1],temp);
                }
            }
        }
        cout<<"\nThe list in sorted order are \n";
        for(i=0;i<=n;i++)
            cout<<a[i];
        cout<<endl;
    }
    else if (pid1 > 0) {
        pid2 = fork();
        if (pid2 == 0) {
            for(i=0;i<n-1;i++){
                s=i;
                strcpy(sm,a[i]);
                for(j=i+1;j<n;j++){
                    if(strcmp(sm,a[j]) > 0){
                        strcpy(sm,a[j]);
                        s=j;
                    }
                }
                strcpy(a[s],a[i]);
                strcpy(a[i],sm);
            }
            cout<<"The list in sorted order are \n";
            for(i=0;i<n;i++)
                cout<<a[i];
            cout<<endl;
        }
        else if (pid2 > 0 || pid1 >0) {
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);
            cout << "Both child processes have completed.\n";
        }
    }
return 0;
}