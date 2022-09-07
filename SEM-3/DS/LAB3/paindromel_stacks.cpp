//Write a program to check whether a given string is a palindrome or not using stacks.
#include<iostream>
#define MAX 10
using namespace std;
class stk
{
    int top;
    char str[MAX];
public:
    stk()
    {
        top= -1;
    }
    void push(char c);
    char pop();
    void palindrome();

};

char stk:: pop()
{
    if(top==-1)
    {
        cout<<"stack underflow";
        return '$';
    }

    return str[top--];
}

void stk::push(char c)
{
    if (top==MAX-1)
    {
        cout<<"stack overflow";
        return;

    }
    str[++top]=c;
}



 void stk::palindrome()
    {
        char str1[10];
        cout<<"enter a word"<<endl;
        cin>>str1;
        for (int i=0; str1[i]!='\0'; i++){
        push(str1[i]);
        }

        for (int i=0; str1[i]!='\0';i++)
        {
            if (str1[i]!=pop())
            {
                cout<<"Not a palindrome";
                return;
            }
        }
        cout<<"It is a palindrome";


    }

int main()
{
    stk obj;
    obj.palindrome();
    return 0;
}
