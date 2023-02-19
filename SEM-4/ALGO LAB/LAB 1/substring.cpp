#include <bits/stdc++.h>
using namespace std;

void substr(char str1[],char str2[]){
    int i=0,temp=0;

    for(i=0;str1[i]!='\0';i++){
        int j=0;

        if(str1[i]==str2[j]){
            //temp=i+1;
            while(str1[i]==str2[j]){
                i++;
                j++;
            }
            if(str2[j]=='\0'){
                cout<<"yes";
            }
            else{
            //    i=temp;
                cout<<"No";
            }
        }
    }   
}

int main(){

    char str1[50];
    char str2[50];
    
    cout<<"Enter string 1:" ;
    cin>>str1;

    cout<<"Enter string 2:" ;
    cin>>str2;

    substr(str1,str2);
}