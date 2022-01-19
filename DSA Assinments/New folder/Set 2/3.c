/*3. Write a C program to perform basic operations of a queue: 
a. Write a function to construct a linear queue. 
b. Write a function to insert an item in the queue. 
c. Write a function to delete an item from the queue. 
d. Write a function to count the number of item in the queue. 
e. Write a function to check overflow and underflow conditions.*/
#include<stdio.h>
#include<stdlib.h>
int *queueArray;
int maxSize;
int front;
int rear;
int numItems;

void Queue(int);
void enqueue(int);
int dequeue(void);
int isEmpty(void);
int isFull(void);
int NumberOfItems();
void main(void)
{

    Queue(5);
    printf("Enqueuing 5 items...\n");
    // Enqueue 5 items.
    for (int x = 0; x < 5; x++)
        enqueue(x);
    // Attempt to enqueue a 6th item.
    printf("Now attempting to enqueue again...\n");
    enqueue(5);
    // Deqeue and retrieve all items in the queue
    printf("The values in the queue were:\n");
    while (!isEmpty())
    {
        int value;
        value=dequeue();
        printf("%d\n",value);
    }
}
int NumberOfItems()
{
    return numItems;
}
void Queue(int s)
{
    queueArray =(int*)  malloc(s * sizeof(int));
    maxSize = s;
    front = -1;
    rear = -1;
    numItems = 0;
}
void enqueue(int num)
{
    if (isFull())
        printf("The queue is full.\n");
    else
    {
        // Calculate the new rear position
        rear = rear + 1;
        // Insert new item
        queueArray[rear] = num;
        // Update item count
        numItems++;
        // if first item set front=0
        if (numItems==1)
            front=0;
    }
}
int dequeue(void)
{
    if (isEmpty())
        printf("The queue is empty.\n");
    else
    {
        // Retrieve the front item
        int num = queueArray[front];
        // Shift remaining items left
        for(int i=front;i<rear;i++)
            queueArray[i]=queueArray[i+1];
        // Update rear and item count, and return
        rear=rear-1; numItems--;
        if (numItems==0)
            front=-1;
        return(num);
        //If last item deleted, set front=-1
    }
}
int isEmpty()
{
    int status;
    if (numItems==0) //or, if (front==-1)
        status = 1;
    else
        status = 0;
    return status;
}
int isFull()
{
    int status;
    if (numItems == maxSize) // or, if (rear==maxSize-1)
        status = 1;
    else
        status = 0;
    return status;
}
void clear()
{
    front = -1;
    rear = -1;
    numItems = 0;
}
