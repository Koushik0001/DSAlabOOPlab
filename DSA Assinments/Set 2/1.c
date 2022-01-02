/*1. Write a C program to implement the following operations of stack (Using 
array): 
a. Write a function to creating the stack. 
b. Write a function to push an item to stack. 
c. Write a function to check the stack is Empty or not. 
d. Write a function to check the stack is Full or not. 
e. Write a function to pop an item to stack. 
*/
#include<stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isempty() 
{
    if(top == -1)
        return 1;
    else
        return 0;
}
int isfull() 
{
    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}
int pop() 
{
    int data;
    if(!isempty()) 
    {
        data = stack[top];
        top = top - 1;
        return data;
    } 
    else 
    {
        printf("Could not retrieve data,Stack is empty.\n");
    }
}
void push(int data) 
{
    if(!isfull()) 
    {
        top = top + 1;
        stack[top] = data;
    }
   else 
    {
        printf("Could not insert data, Stackis full.\n");
    }
}
int main() 
{
    // push items on to the stack
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);
    printf("Elements: \n");
    // print stack data
    while(!isempty()) 
    {
        int data = pop();
        printf("%d\n",data);
    }
    printf("Stack full: %s\n" ,isfull()?"true":"false");
    printf("Stack empty: %s\n" ,isempty()?"true":"false");
    return 0;
}