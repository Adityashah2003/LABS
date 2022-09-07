//implement stack using array
#include<iostream>
#define MAX 10
using namespace std;
class stk
{
    int top;
    int item;
    int s[10];
public:
    stk()
    {
        top=-1;
    }
    int pop();
    void push();
    void display();
};
void stk:: push()
{
    if(top==MAX-1)
    {
        cout<<"stack overflow";
        return;
    }
    str[++top]


}


