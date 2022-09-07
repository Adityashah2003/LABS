//define a class student with the data members to store name, roll no and grade of the student
#include<iostream>
#include<stdio.h>
using namespace std;


class Student
    {
        int rollno;
        char name[20];
        char grade;
    public:
        void Sort(Student s[], int n);
        void Print(Student s[], int n);
        void Insert (Student s[], int n)
        {


        for (int i=0;i<n;i++)
        {
             cout<<"enter name:\n";
             cin>>s[i].name;
             cout<<"enter roll no\n";
             cin>>s[i].rollno;
             cout<<"enter grade\n";
             cin>>s[i].grade;
             cout<<endl;
        }
    }
    };
void Student::Sort(Student s[], int n)
{
    //int i,j;

    Student temp;

    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (s[j].rollno>s[j+1].rollno)
            {
                temp=s[j+1];
                s[j+1]=s[j];
                s[j]=temp;

            }
        }
    }
    //cout<<"sorted list is"<<s[i];

}
void Student::Print(Student s[], int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"roll no:\n"<<s[i].rollno;
        cout<<"name:\n"<<s[i].name;
        cout<<"grade:\n"<<s[i].grade;
    }
}
int main()
{
    int n;
    cout<<"enter total no of students:\n";
    cin>>n;
    Student s, s1[100];
    s.Insert(s1,n);
    s.Sort(s1,n);
    s.Print(s1,n);
    return 0;
}
