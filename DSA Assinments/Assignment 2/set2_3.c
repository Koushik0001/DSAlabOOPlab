/*3.  Write a C program to perform basic operations of a queue:
a.  Write a function to construct a linear queue.
b.  Write a function to  insert an item in the queue.
c.  Write a function to delete an item from the queue.
d.  Write a function to count the number of item in the queue.
e.  Write a function to check overflow and underflow conditions.*/
#include<stdio.h>
#include <stdlib.h>
struct Queue
{
    int value;
    struct Queue *next;
};

struct Queue *front;
struct Queue *rear;
int numItems;
int NumOfItems(){   return numItems;}
int isEmpty(void)
{
    int status;

    if (numItems==0) // or, if (front==NULL)
        status = 1;
    else
        status = 0;

    return status;
}

void enqueue(int num)
{
    struct Queue *newNode =(struct Queue*) malloc(sizeof(struct Queue));
    newNode->value = num;
    newNode->next = NULL;
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}
int dequeue()
{
    struct Queue *temp;
    if (isEmpty())
        printf("Queue underflow...\n");
    else
    {
        int num = front->value;
        temp = front->next;
        free(front);
        front = temp;
        numItems--;
        return(num);
    }
}

int main()
{
    struct Queue queue;
    dequeue();
    printf("Enqueuing 5 items...\n");
    // Enqueue 5 items.
    for (int x = 0; x < 5; ++x)
        enqueue(x);
    // Deqeue and retrieve all items in the queue
    printf("The values in the queue were:\n");
    while (!isEmpty())
    {
        int value;
        value = dequeue();
        printf("%d\n",value);
    }
    return 0;
}