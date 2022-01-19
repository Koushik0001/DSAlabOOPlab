/*6. Write a C program to reverse a string using a stack (Using Linked List). */
#include<stdio.h>
#include <stdlib.h>
struct stack
{
    struct stack* next;
    int data;
}*top=NULL;

int stack_isempty();
int pop();
void push(int);
void reverse(char* string);

int main() 
{
    char string[100];
    printf("Enter the string : \n\t");
    gets(string);

    reverse(string);

    printf("The revesed string is : \n\t");
    puts(string);
        
    return 0;
}
int stack_isempty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
int pop()
{
    if(stack_isempty())
        printf("Nothig to POP, Stack is empty...\n");
    else
    {
        int num = top->data;
        top =  top->next;
        return num;
    }
}
void push(int d)
{
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    new->data = d;
    new->next = top;
    top = new;    
}
void reverse(char* string)
{
    char ch = 'a';
    int i,j;

    push('\0');
    i = 0;
    while (ch != '\0')
    {
        ch = string[i];
        push(ch);
        i++; 
    }

    ch = pop();//to pop the last '\0' character
    j = 0;
    while(j != i-1)
    {
        string[j] = pop(); 
        j++;
    }
}