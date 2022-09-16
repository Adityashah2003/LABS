#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define Maxsize 100

class mstack{
    int top[20],bottom[20];
    int ns,maxsize=0;
    int s[50];
public:
    mstack()
    {
        ns=2;
        maxsize=10;
    }
    mstack(int n,int ms)
    {
        ns=n;
        maxsize=ms;
    }
    void push(int, int);
    int pop(int);
    void display(int);

};
void mstack::push(int i,int ele){
    if(top[i]==bottom[i+1]||top[i]==maxsize-1)
    {
        cout<<"ith stack is full";
        return;
    }
    else{
        ++top[i];
        s[top[i]]=ele;
    }
}
int mstack:: pop(int i){
    int ele;
    if (top[i]==bottom[i]){
        cout<<i<<"th stack is empty";
        return(-999);
    }
    else{
        ele=s[top[i]];
        top[i]--;
        return(ele);
    }
}
void mstack::display(int i){
    int index = top[i];
    if(top[i]==bottom[i])
        cout<<i<<"th stack is empty";
    else{
        while(index>bottom[i]){
              cout<<s[index];
              index = index-1;
    }
}
}

int main()
{
    mstack s;
    int ele;
    s.push(10,15);
    s.push(20,25);
    s.push(30,35);
    s.pop(15);
    s.display(10);
return 0;
}
