#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char a[50], b[50];
    cout<<"Enter the main string:"<<endl;
    cin>>a;
    cout<<"Enter the sub string:"<<endl;
    cin>>b;
    int al=strlen(a),bl=strlen(b);
    bool flag=false;
    int loc=-1;
    int i=0;
    for (int i=0;i<al-bl;i++){
        for(int j=i;j<i+bl;j++){
            flag=true;
            if(a[j]!=b[j-i]){
                flag=false;
                break;
            }
        }
    if(flag==true){
        loc=i;
        break;
        }
    }
    if (loc==-1){
        cout<<"Substring not found in string";
        return 0;
    }
    for(int i=0;i<al-loc;i++){
        a[loc+i]=a[loc+bl+i];
    }
    cout<<a;
}
