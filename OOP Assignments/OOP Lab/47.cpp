/*47. Design a class Stack with necessary exception handling.*/
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class error
{
    int err_number;
    char *err_message;
    public:
        error(int en,const char *ch)
        {
            err_number = en;
            err_message = new char[strlen(ch)];
            strcpy(err_message,ch);
        }
        void display()
        {
            cout << "Err. No. "<< err_number << ", "
            << err_message << endl;
        }
};
int size = 0;
int maax = 2;
class stack
{
    int data;
    stack* previous;
    static int size;
    public:
        stack(int d=0,stack* p=NULL):data(d),previous(p){}
        ~stack(){};
        void push(int a);
        int pop();
};
stack *top,*temp;
int stack:: size = 0;
void stack:: push(int a)
{
    try
    {
        if(size <= maax)
        {
            stack *neew = new stack(a);
            if(top == NULL)
                top = neew;
            else 
            {
                neew->previous = top;
                top = neew;
            }
            size++;
        }
        else
            throw error(1,"Stack Overflow, maaximum capacity 100 ...");
    }
    catch(error Over)
    {
        Over.display();
        throw;
    }
}
int stack :: pop()
{
    try
    {
        if(top == NULL)
            throw error(0,"Stack Underflow, Stack is empty...");
        else
        {
            temp = top;
            top = top->previous;
            size--;
            return temp->data;
        }
    }
    catch(error Under)
    {
        Under.display();
        throw;
    }
}
int main()
{
    stack st;
    st.push(101);
    st.push(201);
    st.push(301);
    cout << st.pop();
}