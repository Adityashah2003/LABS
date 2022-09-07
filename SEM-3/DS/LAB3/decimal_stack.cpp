//Write a program to convert a given decimal number to a number in any base using stack.
//Step 1 − Divide the decimal number to be converted by the value of the new base.

//Step 2 − Get the remainder from Step 1 as the rightmost digit (least significant digit) of new base number.

//Step 3 − Divide the quotient of the previous divide by the new base.
#include<iostream>
#define MAX 10
using namespace std;
class stk
{
    int top;
    int n;
    int a[MAX];
public:
    stk()
    {
        top=-1;
    }
    void push(int c);
    int pop();
    void conversion();
};

void stk::push(int c)
{
    if(top==MAX-1)
    {
        cout<<"stack overflow";
        return;
    }
    a[++top]=c;
}

int stk::pop()
{
    if (top==-1)
    {
        cout<<"stack underflow";
        return -1;
    }
    return a[top--];

}
int main()
{
    int no,n,conv=0,base,temp;
    stk o1;
    cout<<"enter a number\n";
    cin>>n;
    cout<<"enter the base for required conversion:"<<endl;
    cin>>base;
    temp=n;
    while(temp>0)
    {
        no=temp%base;
        o1.push(no);
    //temp=n;
        temp/=base;
    }

    while(true)
    {
        //no=n%base;
        no=o1.pop();
        if(no==-1)
        {
            break;
        }
       conv= (conv*10)+no;

    }
    cout<<conv<<endl;
    return 0;

}
