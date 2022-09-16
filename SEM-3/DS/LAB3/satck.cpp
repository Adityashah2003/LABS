#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define Maxsize 100

class stack{
    int top;
    int arr[Maxsize];
    public :
        stack(){
            top = -1;
        }
        void push(int ele);
        int pop();
        int isEmpty();
        int isFull();
        int topele();
        void display();
};
void stack :: push (int ele){
    if(isFull())
        cout<<"Stack is full";
    else{
        top+=1;
        arr[top]=ele;
    }
}
int stack :: pop(){
    if(isEmpty()){
        cout<<"Stack is empty";
        return (-999);
    }
    else
        return(arr[top--]);
}
int stack::isEmpty(){
    if(top==-1)
        return(1);
    else
        return(0);
}
int stack :: isFull(){
    if(top==Maxsize-1)
        return(1);
    else
        return(0);
}
int stack::topele(){
    if(isEmpty())
        return (-999);
    else
        return (arr[top]);
}
void stack :: display(){
    int i = top;
    while(i>=0){
        cout<<arr[i];
        i--;
    }
}

int main(){
    stack s;
    int ele;
    s.push(10);
    s.push(15);
    s.push(30);
    s.pop();
    if(ele != -999){
        cout<<"Popped ele is "<<endl;
    }
    else{
        cout<<"Top ele: "<<s.topele();
    }
    s.display();
return 0;
}