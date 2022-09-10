#include <iostream>
using namespace std;

int main() {
    char str1[100],str2[100];
    int i=0,j=0;
    cout<<"Enter the first string: "<<endl;
    cin>>str1;
    cout<<"Enter the second string: "<<endl;
    cin>>str2;
    while(str1[i]!='\0')
        i++;
    while(str2[j]!='\0'){
            str1[i]=str2[j];
            j++;
            i++;
    }
    str1[i]='\0';
    cout<<"Concatenated is: "<<str1;
return 0;
}
