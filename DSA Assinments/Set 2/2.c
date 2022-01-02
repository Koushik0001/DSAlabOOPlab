/*2. Write a C program to reverse a string using a stack (Using Array). */
#include<stdio.h>
#include<string.h>

int MAXSIZE = 100;
char stack[100];
int top = -1;

int isempty();
int isfull();
char pop();
void push(char);
void reverse(char *);

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
char pop() 
{
    char c;
    if(!isempty()) 
    {
        c = stack[top];
        top = top - 1;
        return c;
    } 
    else 
    {
        printf("Could not retrieve data,Stack is empty.\n");
    }
}
void push(char c) 
{
    if(!isfull()) 
    {
        top = top + 1;
        stack[top] = c;
    }
   else 
    {
        printf("Could not insert data, Stackis full.\n");
    }
}