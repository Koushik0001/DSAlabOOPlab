/*6. Write a menu driven C program to create a doubly linked list and do the 
following operations on it:
a. Write a function to insert a node at a specified position.
b. Write a function to delete a node from a specified position.
c. Write a function to count the number of nodes in the linked list.
d. Write a function to reverse the linked list. 
e. Write a function to traverse the list. */

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next, *prev;
};
struct node* Traversal(struct node**);
void InsertionAtend(struct node**);
void InsertionAtposition(struct node**,int);
void DeletionAtposition(struct node**,int);
int number_of_nodes(struct node**);
void Rev_list(struct node**);
void display(struct node**);
int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node **ptrheadptr = (struct node**)malloc(sizeof(struct node*));
    head = NULL;
    ptrheadptr = &head;
    for(int i=0; i<5; i++)
        InsertionAtend(ptrheadptr);
    display(ptrheadptr);
    printf("\nEnter the position number where you want insrt the node(index starts from 1) : ");
    int position;
    scanf("%d",&position);
    InsertionAtposition(ptrheadptr,position);
    display(ptrheadptr);
    printf("\nDelete n th node(index starts from 1) where n =  ");
    scanf("%d",&position);
    DeletionAtposition(ptrheadptr,position);
    display(ptrheadptr);
    printf("\nThe number of nodes in linked list is %d\n",number_of_nodes(ptrheadptr));
    printf("The reversed linked list is : ");
    Rev_list(ptrheadptr);
}
struct node* Traversal(struct node** ptrheadptr)
{    
    struct node *temp = *ptrheadptr;

    if(temp == NULL)
        return temp;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        return temp;
    }
}
void InsertionAtend(struct node** ptrheadptr)
{
    struct node* a = (struct node*)malloc(sizeof(struct node)), *head = *ptrheadptr;
    printf("Enter Integer : ");
    scanf("%d",&a->data);

    if(*ptrheadptr == NULL)
    {
        *ptrheadptr = a;
        a->next = NULL;
        a->prev = head;
    }
    else
    {
        struct node* lastNode = Traversal(ptrheadptr);
        lastNode->next = a;
        a->prev = lastNode;
        a->next = NULL;
    }
}
void InsertionAtposition(struct node** ptrheadptr,int n)//inserts a node at nth position...position number starts from 0
{
    int position_counter=1;
    struct node* head = *ptrheadptr, *temp = head;
    struct node* a = (struct node*)malloc(sizeof(struct node));
    printf("Enter Integer : ");
    scanf("%d",&a->data);

    if(n <= number_of_nodes(ptrheadptr))
    {
        while(position_counter < n && temp != NULL)
        {
            temp = temp->next;
            position_counter++;
        }
        if(n != 1)
        {
            a->next = temp;
            a->prev = temp->prev;
            a->prev->next = a;
            a->next->prev = a;
        }
        else
        {
            a->next = head;
            *ptrheadptr = a;
            a->next->prev = a;
            a->prev = *ptrheadptr;
        }
    }
    else if(n == number_of_nodes(ptrheadptr)+1)
    {
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = a;
        a->next = NULL;
        a->prev = temp;
    }
}
void DeletionAtposition(struct node** ptrheadptr,int n)
{
    int position_counter=0;
    struct node* head = *ptrheadptr, *temp = head;
    if(n == 1)
    {
        *ptrheadptr = head->next;
        head->next->prev = *ptrheadptr;

    }
    else
    {
        while(position_counter < n-1 && temp != NULL)
        {
            temp = temp->next;
            position_counter++;
        }
        temp->prev->next = temp->next;
        if(temp->next != NULL)
            temp->next->prev = temp->prev;
    }
}
int number_of_nodes(struct node** ptrheadptr)
{
    struct node *temp = *ptrheadptr;
    int no_of_nodes = 0;
    while(temp != NULL)
    {        
        no_of_nodes++;
        temp = temp->next;
    }
    return no_of_nodes;
}
void Rev_list(struct node** ptrheadptr)
{
    struct node *temp = Traversal(ptrheadptr);
    if(*ptrheadptr == NULL)
        printf("List is Empty...\n");
    while(temp != *ptrheadptr)
    {
        printf("%d  ",temp->data);
        temp = temp->prev;        
    }
    printf("%d  ",temp->data);
}
void display(struct node** ptrheadptr)
{
    struct node *temp = *ptrheadptr;

    if(*ptrheadptr == NULL)
        printf("List is Empty...\n");
    else
    {
        printf("\n");
        while(temp != NULL)
        {
            printf("%d  ",temp->data);
            temp = temp->next;
        }
    }
}