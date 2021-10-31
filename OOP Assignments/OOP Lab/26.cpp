/*26. Complete the class with all function definitions for a stack 
class Stack { 
 int *buffer, top; 
public : 
 Stack(int); //create a stack with specified size 
 void push(int); //push the specified item 
 int pop(); //return the top element 
 void disp(); //displays elements in the stack in top to bottom order 
}
Now, create a stack with size 10, push 2, 3, 4 and 5 in that order and finally pop one element. Display elements 
present in the stack. */
#include<iostream>
using namespace std;
class Stack 
{ 
        int *buffer, top; 
    public : 
        Stack(int);             //create a stack with specified size 
        void push(int);         //push the specified item 
        int pop();              //return the top element 
        void disp();            //displays elements in the stack in top to bottom order 
};

int main()
{
    Stack a(10);
    a.push(2);
    a.push(3);
    a.push(4);
    a.disp();
    a.push(5);
    a.disp();
    int v = a.pop();
    cout << "popped result = " << v << endl;
    a.disp();    
    return 0;
}
Stack::Stack(int x)
{
    buffer = new int[x];
    top = 0;
}
void Stack::push(int x)
{
    buffer[top] = x;
    top++;
}
int Stack::pop()
{
    if(top == 0)
    {
        cout << "Stack Underflow"<< endl;
        cout << "top = " << top <<endl;
    }
    else
    {
        top--;
        return (buffer[top]);
    }

}
void Stack::disp()
{
    for(int i=0; i<top;i++)
        cout << buffer[i] << " ";
    cout << endl;
}