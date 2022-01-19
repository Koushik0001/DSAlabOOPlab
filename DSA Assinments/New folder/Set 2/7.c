/*7. Write a Program to evaluate the following postfix expression using stack and show 
the intermediate contents of stack. X = 6 2 3 + - 3 8 2 / + * 2 ^ 3 + 
*/
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
struct stack
{
    struct stack* next;
    int data;
}*top=NULL;

int array_of_parenthesis();
int stack_isempty();
int pop();
void push(int);
int main()
{
    printf("Result = %d",array_of_parenthesis());
    
    return 0;
}
int array_of_parenthesis()
{
    char ch;
    printf("Enter the expression : \n\t");
    do
    {
        ch = getchar();
        int a,b;
        if(ch >=48 && ch<= 57)
        {
            push(ch-48);
        }
        else if(ch == '*')
        {
            a = pop();
            b = pop();
            push(b*a);
        }
        else if(ch == '+')
        {
            a = pop();
            b = pop();
            push(b+a);
        }
        else if(ch == '-')
        {
            a = pop();
            b = pop();
            push(b-a);
        }
        else if(ch == '/')
        {
            a = pop();
            b = pop();
            push(b/a);
        }
        else if(ch == '^')
        {
            a = pop();
            b = pop();
            push(pow(b,a));
        }
    } while (ch  != '\n');
    int result = pop();
    if(!stack_isempty())
    {
        printf("Invalid Expression...\n");
        exit(1);
    }
    else
        return result;
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
    {
        printf("\nInvalid Expression...\n");
        exit(2);
    }
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