
#include <iostream>
#define SIZE 5 

using namespace std;

class Queue {
   private:
  int items[SIZE], front, rear;

   public:
  Queue() {
    front = -1;
    rear = -1;
  }
  bool isFull() {
    if (rear = SIZE-1) {
      return true;
    }
    return false;
  }
  bool isEmpty() {
    if (front == rear)
      return true;
    else
      return false;
  }
  void enQueue(int element) {
    if (isFull()) {
      cout << "Queue is full";
    } 
    else {
      items[++rear] = element;
    }
  }
  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
        items[++front] = element;
      return (element);
      }
  }

  void display() {
    int i;
      for (i = front; i != rear; i = (i + 1) % SIZE)
        cout << items[i];
      cout << items[i];
    }
  };

int main() {
  Queue q;

q.enQueue(5);
q.enQueue(1);
q.enQueue(2);
q.display();
q.deQueue();
  return 0;
}
