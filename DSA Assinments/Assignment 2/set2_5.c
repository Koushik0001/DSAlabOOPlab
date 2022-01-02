/*5. Write a C program to implement circular queue using array.*/
#include <stdio.h>  
# define max 13

int queue[max];  // array declaration  
int front=-1;  
int rear=-1;  
// function to insert an element in a circular queue  
void enqueue(int element)  
{  
    if(front==-1 && rear==-1)   // condition to check queue is empty  
    {  
        front=0;  
        rear=0;  
        queue[rear]=element;  
    }  
    else if((rear+1)%max==front)  // condition to check queue is full  
        printf("Queue is overflow(Max = 13)...\n");  
    else  
    {  
        rear=(rear+1)%max;       // rear is incremented  
        queue[rear]=element;     // assigning a value to the queue at the rear position.  
    }  
}  
  
// function to delete the element from the queue  
int dequeue()  
{  
    if((front==-1) && (rear==-1))  // condition to check queue is empty  
        printf("\nQueue is underflow..");  
    else if(front==rear)  
    {  
       printf("\nThe dequeued element is %d", queue[front]);  
       front=-1;  
       rear=-1;  
    }   
    else  
    {  
        printf("\nThe dequeued element is %d", queue[front]);  
       front=(front+1)%max;  
    }  
}  
int main()  
{  
    printf("\nEnqueuing 15 elements...\n");
    for(int x=0; x<15; x++)    
        enqueue(x);  
    printf("\nDequeuing 5 elements...");
    for(int x=0; x<5; x++)    
        dequeue(x);
    printf("\nEnqueuing 5 elements...");
    for(int x=25; x<30; x++)    
        enqueue(x);
    printf("\nDequeuing 15 elements...");
    for(int x=0; x<15; x++)
        dequeue();     

  
 return 0;  
}  