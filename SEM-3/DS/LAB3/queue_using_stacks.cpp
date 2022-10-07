//Program to find the fast transpose of a matrix using Sparse Row Method
#include <iostream>
using namespace std;
#define max 10

class Stack{
public:     
    int top;
    int arr[max];
    Stack(){
            top = -1;
    }
    
    void push(int ele);
    int pop();
    bool isFull();
    bool isEmpty();
    int topele();
    void display();
};

void Stack :: push(int ele){
    if(isFull())
        cout<<"Stack full";
    else
        arr[++top]=ele;
    
}

int Stack ::pop(){
    if(isEmpty()){
        cout<<"Stack empty";
        return (-999);}
    else
        return arr[top--];
}

bool Stack :: isFull(){
    if(top = max-1)
        return true;
    else
        return false;
}

bool Stack :: isEmpty(){
    if(top ==-1)
        return true;
    else
        return false;
}

int Stack :: topele(){
    if(isEmpty())
        return (-999);
    else
        return arr[top];
}

void Stack :: display(){
    int i = top;
    while(i>=0){
        cout<<arr[i];
        i--;
}
}
class Queue {
    Stack s1, s2;
public: 
    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.isEmpty()) {
            s2.push(s1.topele());
            s1.pop();
        }
 
        // Push item into s1
        s1.push(x);
 
        // Push everything back to s1
        while (!s2.isEmpty()) {
            s1.push(s2.topele());
            s2.pop();
        }
    }
 
    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.isEmpty()) {
            cout << "Q is Empty";
            exit(0);
        }
 
        // Return top of s1
        int x = s1.topele();
        s1.pop();
        return x;
    }
};
 
// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
 
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
 
    return 0;
}

// int main(){
//     Stack s;
//     int ele =0;
//     s.pop();
//     s.push(100);
//     s.push(50);
//     s.push(3);
    
//     s.display();

// return 0;
// }
