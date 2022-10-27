#include <iostream>
using namespace std;
#define max 100

class queue{
public:
    int rear;
    int front;
    int arr[max];
    int i =0;
    queue(){
        rear=-1;
        front=-1;
    }
    bool isEmpty(){
        if(front ==-1)
            return true;
        else
            return false;
    }
    bool isFull(){
        if(rear == max-1)
            return true;
        else 
            return false;
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
        else if(front==rear){
            int temp=arr[rear];
            front=rear=-1;
            return temp;
        }
        else{
            return arr[front++];
        }
    }
    int size(){
        return (rear-front);
    }
    void display(){
    for(i=front;i<=rear;i ++){
        cout<<arr[i]<<endl;
        }
    }
};

class stack{
    queue q,q1,q2;
public: 
    void push(int x){
        q2.enQ(x);
        while(!q1.isEmpty()){
            q2.enQ(q1.deQ());
        }
        q = q1;
		q1 = q2;
		q2 = q;
    }
    void pop(){
        if(q1.isEmpty())
            cout<<"Stack is empty";
        else
            q1.deQ();
    }
    int top()
	{
		if (q1.isEmpty())
			return -1;
        else
		    return q1.rear;
	}
    void disp(){
        q1.display();
    }
    
};
// Driver code
int main()
{
    stack s;
    s.push(5);
    s.push(1);
    s.push(78);
    s.disp();

    return 0;
}
