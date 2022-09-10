#include <iostream>
using namespace std;

int main() {
    char a[100],b[100],c[100];
    int i=0,j=0,k=0,p=0,x=0,tot_size=0,o=0;
    cout<<"Enter the first string: "<<endl;
    cin>>a;
    cout<<"Enter the second string: "<<endl;
    cin>>b;
    cout<<"Enter the n+1 position"<<endl;
    cin>>p;
    while(i<=p){
        c[k++]=a[i];
        i++;
    }
    while(b[j]!='\0'){
        c[k++] = b[j++];
    }
    while(a[i]!='\0'){
        c[k++] = a[i++];
    }
    c[k]='\0';
    cout<<"Concatenated is: "<<c;
return 0;
}
