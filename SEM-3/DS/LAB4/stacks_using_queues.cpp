#include <iostream>
using namespace std;
#define max 10

class Queue{
public:     
    int rear;
    int front;
    int arr[max];
    Queue(){
        rear = -1;
        front = -1;
    }
    
    void enQ(int ele);
    int deQ();
    bool isFull();
    bool isEmpty();
    int size();
    void display();
    int front1();
};

void Queue :: enQ(int ele){
    if(isFull())
        cout<<"Queue full";
    else
        arr[++rear]=ele;
    
}
int Queue :: front1(){
    return arr[front];
}
int Queue ::deQ(){
    if(isEmpty()){
        cout<<"Queue empty";
        return (-999);}
    else
        return arr[++front];
}

bool Queue :: isFull(){
    if(rear = max -1)
        return true;
    else
        return false;
}

bool Queue :: isEmpty(){
    if(front=rear)
        return true;
    else
        return false;
}

int Queue :: size(){
    if(isEmpty())
        return (-999);
    else
        return (rear-front);
}

void Queue :: display(){
    for(int i=front;i!=rear;i = (i+1)%max){
        cout<<arr[i];
}
}

class Stack {
    Queue q1, q2;
 
public:
    void pop()
    {
        if (q1.isEmpty())
            return;
        while (q1.size() != 1) {
            q2.enQ(q1.front1());
            q1.deQ();
        }
        q1.deQ();
 
        Queue q = q1;
        q1 = q2;
        q2 = q;
    }
    void push(int x)
    {
        q1.enQ(x);
    }
    int top()
    {
        if (q1.isEmpty())
            return -1;
 
        while (q1.size() != 1) {
            q2.enQ(q1.front1());
            q1.deQ();
        }
 
        // last pushed element
        int temp = q1.front1();
 
        // to empty the auxiliary queue after
        // last operation
        q1.deQ();
 
        // push last element to q2
        q2.enQ(temp);
 
        // swap the two queues names
        Queue q = q1;
        q1 = q2;
        q2 = q;
        return temp;
    }
 
    int size()
    {
        return q1.size();
    }
};
 
// Driver code
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
 
    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "current size: " << s.size()
         << endl;
    return 0;
}
