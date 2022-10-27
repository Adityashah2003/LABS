#include <iostream>
using namespace std;
const int SIZE=100;

class Queue{
    private:
    int front;
    int rear;
    int arr[SIZE];
    public:
    Queue(){
        rear=front=-1;
    }
    bool isEmpty(){
        return front==-1 && rear==-1;
    }
    bool isFull(){
        return rear==SIZE-1;
    }
    void enQ(int elem){
        if(isFull())
            return;
        if(isEmpty())
            front++;
        arr[++rear]=elem;

    }
        int deQ(){
        if(isEmpty()){
            cout<<"Empty Queue";
            return -1;    
        }
        else{
            return arr[front++];
        }
    }
  
};
class Stack {
    Queue q, q1, q2;
public:
    void pop()
	{
		if (q1.isEmpty())
			return;
		q1.deQ();
	}
    void push(int x)
	{
		q2.enQ(x);
		while (!q1.isEmpty()) {
			q2.enQ(q1.deQ());
			q1.deQ();
		}
		q = q1;
		q1 = q2;
		q2 = q;
	}
    int top()
	{
		if (q1.isEmpty())
			return -1;
		return q1.deQ();
	}
};
 
// Driver code
int main()
{
    Stack s;
    s.push(13);
    cout<<s.top();
    s.push(1);
    cout<<s.top();
    s.pop();
    cout<<s.top();
    return 0;
}
