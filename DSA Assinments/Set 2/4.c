/*4. Write a C program to implement stack and queue using link list. */
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    struct stack* next;
    int data;
}*top=NULL;
int stack_isempty();
int pop();
void push(int);

struct queue
{
    struct queue* next;
    int data;
}*front = NULL;
int queue_isEmpty();
void enqueue(int);
int dequeue();

int main()
{
    printf("\nPushih 5 items into the stack...\n");
    //pushih 5 items into the stack
    for(int i=0; i<5; i++)
        push(i);
    printf("Popping 5 items from the stack...\n");
    //popping 5 items from the stack
    for(int i=0; i<5; i++)
        printf("%d\n",pop());
    //attempting to pop another item from the stack...
    pop();

    printf("\n\nEnqueuing 5 items...\n");
    //Enqueuing 5 items
    for(int i=0; i<5; i++)
        enqueue(i);
    printf("Dequeing 5 items...\n");
    //Dequeing 5 items
    for(int i=0; i<5; i++)
        printf("%d\n",dequeue());
    //attempting to dequeue another item...
    dequeue();
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
void enqueue(int d)
{
    struct queue* new = (struct queue*)malloc(sizeof(struct queue));
    new->data = d;
    new->next = NULL;
    if(queue_isEmpty())
        front = new;
    else
    {
        struct queue* temp = front;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}
int dequeue()
{
    if(queue_isEmpty())
        printf("Nothig to DEQUEUE, Queue is empty...\n");
    else
    {
        int num = front->data;
        front = front->next;
        return num;
    }
}
int queue_isEmpty()
{
    if(front == NULL)
        return 1;
    else
        return 0;
}