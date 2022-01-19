/*8. Write a Program to check an array of parenthesis “( )” whether it is well formed 
or not using stack. 
((( )) (( ))) -> It is well formed 
((( ))) -> It is well formed 
(()))((()) -> It is not well formed 
(((( )) () -> It is not well formed */
#include<stdio.h>
#include <stdlib.h>
struct stack
{
    struct stack* next;
    int data;
}*top=NULL;

void array_of_parenthesis();
int stack_isempty();
int pop();
void push(int);
int main()
{
    array_of_parenthesis();
    return 0;
}
void array_of_parenthesis()
{
    char ch;
    printf("Enter the array of parenthesis : \n\t");
    do
    {
        ch = getchar();
        if(ch == '(')
            push(ch);
        else if(ch == ')')
        {
            char c;
            c = pop();
            if(c != ')')
                printf("Not Well formed\n");
            exit(0);
        }
    } while (ch  != '\n');
    stack_isempty()? printf("Well formed\n"):printf("Not Well formed\n");
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
        return 0;
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