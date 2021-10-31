/*27. Complete the class with all function definitions for a circular queue 
class Queue { 
 int *data; 
 int front, rear; 
public : 
 Queue(int ); //create queue with specified size 
 void add(int); //add specified element to the queue 
 int remove();//delete element from the queue 
 void disp(); //displays all elements in the queue(front to rear order) 
} 
Now, create a queue with size 10 add 2, 3, 4 and 5 in that order and finally delete two elements. Display 
elements present in the stack. */
#include<iostream>
using namespace std;
class Queue 
{ 
        int *data; 
        int front, rear; 
    public : 
        Queue(int ); //create queue with specified size 
        void add(int); //add specified element to the queue 
        int remove();//delete element from the queue 
        void disp(); //displays all elements in the queue(front to rear order) 
};

int main()
{
    Queue a(10);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);
    a.disp();
    a.remove();
    a.disp();
    a.remove();
    a.disp();
    return 0;
}
Queue::Queue(int x)
{
    data = new int[x];
    front = 0;
    rear = 0;
}
void Queue::add(int x)
{
    data[rear] = x;
    rear++;
}

int Queue::remove()
{
    int x = data[front];
    if(front == rear)
    {
        front = 0;
        rear = 0;
        delete []data;
    }
    else 
        front++;
    return x;
}
void Queue::disp()
{
    for(int i=front; i<rear; i++)
        cout << data[i] << " ";
    cout << endl;
}