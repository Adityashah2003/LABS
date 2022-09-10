#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string s1, s2;

    int i=0, chk=0;
    cout<<"Enter the First String: ";
    cin>>s1;
    cout<<"Enter the Second String: ";
    cin>>s2;
    while(s1[i]!='\0' || s2[i]!='\0'){
        if(s1[i]!=s2[i]){
            chk = 1;
            break;
        }
    i++;
    }
    if(chk==0)
        cout<<"\nStrings are Equal";
    else
        cout<<"\nStrings are not Equal";
    cout<<endl;
    return 0;
}
