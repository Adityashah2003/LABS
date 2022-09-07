//Define a class time with data members hour, min, sec .Write the user defined functions to (i) Add (ii) To find difference between two objects of class time.
#include <iostream>
#include <stdio.h>
using namespace std;

class time
{
    int hour, Min,sec;
public:
    void add(Time t[], int n);
    void diff(Time t[], int n);
    void Insert(Time t[], int n)
    {
        cout<<"enter a time";
        cin>>n;
        int hour, Min,sec;
        Min=sec/60;
        hour= Min/60;
        cout<<"time is:\n"<<hour;

    }
};
void main:: add(Time t[], int n)
{
    int hour,t1, Min, sec, sum=0;
    cout<<"enter time1:\n";
    cin>>t1;
    cout<<"enter time2:\n";
    cin>>t2;
    cout<<" "<<void Insert();
    sum= t1+t2;
    cout<<"sum is:\n"<<sum;
}
void main:: diff(Time t[], int n)
{
    int t1,t2, diff=0;
    cout<<"enter t1:\n";
    cin>>t1;
    cout<<"enter t2:\n";
    cin>>t2;
    cout<<" "<<void Insert();
    if (t2>t1)
    {
        diff= t2-t1;
    }
    else
    {
        diff= t1-t2;
    }
    cout<<"diff is:\n"<<diff;
}
int main()
{
    Time t;
    t.Insert(t,n);
    t.add(t,n);
    t.diff(t,n);
    return 0;
}
