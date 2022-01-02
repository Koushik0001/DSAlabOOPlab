/*5. Write a C program to implement circular queue using array.*/
#include <stdio.h>  
# define max 5

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
        printf("Queue overflow(Max = %d)...\n",max);  
    else  
    {  
        rear=(rear+1)%max;       // rear is incremented
        queue[rear]=element;        // assigning a value to the queue at the rear position.  
    }  
}  
  
// function to delete the element from the queue  
int dequeue()  
{  
    if((front==-1) && (rear==-1))  // condition to check queue is empty  
        printf("\nNothig to dequeue, Queue is empty...");  
    else if(front==rear)  
    {    
        int num = queue[front];
        front=-1;  
        rear=-1;  
        return num;
    }   
    else  
    {  
        int num = queue[front];
        front=(front+1)%max; 
        return  num;
    }  
}  
int main()  
{  
    printf("\nEnqueuing 5 elements...\n");
    for(int x=1; x<6; x++)    
        enqueue(x); 
    printf("Attempting to enqueue another elemenr...\n");
        enqueue(10);
    printf("\nDequeuing 3 elements...\n");
    for(int x=0; x<3; x++) 
    {   
        printf("%d\n",dequeue());
    }
    printf("\nAttempting to Enqueue 5 elements...\n");
    for(int x=10; x<15; x++)    
        enqueue(x);
    printf("\nDequeuing 2 elements...\n");
    for(int x=0; x<2; x++)
    {   
        printf("%d\n",dequeue());
    }     
    printf("\nDequeuing 3 elements...\n");
    for(int x=0; x<3; x++) 
    {   
        printf("%d\n",dequeue());
    }
    return 0;  
}  