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
    Stack s;
public: 
    void enQueue(int x)
    {
        s.push(x);
    }
 
    // Dequeue an item from the queue
    int deQueue()
    {
        if (s.isEmpty()) {
            cout << "Q is empty";
            exit(0);
        }
 
        // pop an item from the stack
        int x = s.topele();
        s.pop();
 
        // if stack becomes empty, return
        // the popped item
        if (s.isEmpty())
            return x;
 
        // recursive call
        int item = deQueue();
 
        // push popped item back to the stack
        s.push(x);
 
        // return the result of deQueue() call
        return item;
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
