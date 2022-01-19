/*5. Write a menu driven C program to create a singly connected linked list and 
do the following operations on it: 
a. Write a function to insert a node at the beginning. 
b. Write a function to insert a node at the end. 
c. Write a function to insert a node at a specified position. 
d. Write a function to delete a node from a specified position. 
e. Write a function to count the number of nodes in linked list. 
f. Write a function to display the reverse linked list. */

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* Traversal(struct node**);
void InsertionAtbeginning(struct node**);
void InsertionAtend(struct node**);
void InsertionAtposition(struct node**,int);
void DeletionAtposition(struct node**,int);
int number_of_nodes(struct node**);
void Rev_list(struct node**,struct node*);
void display(struct node**);
void insert_befoe_last(struct node** head,struct node* new);
void print_common(struct node* head1, struct node* head2);
int main()
{
    struct node *head1 = (struct node*)malloc(sizeof(struct node));
    struct node *head2 = (struct node*)malloc(sizeof(struct node));
    struct node **ptrheadptr1 = (struct node**)malloc(sizeof(struct node*));
    struct node **ptrheadptr2 = (struct node**)malloc(sizeof(struct node*));
    head1 = NULL;
    head2 = NULL;
    ptrheadptr1 = &head1;
    ptrheadptr2 = &head2;
    char ch;
    do
    {
        printf("enter number of nodes : ");
        int num;
        scanf("%d",&num);
        for(int i=0; i<num; i++)
            InsertionAtend(ptrheadptr1);
        printf("enter next list : ");
        for(int i=0; i<num+2; i++)
            InsertionAtend(ptrheadptr2);
        print_common(head1,head2);
        /*display(ptrheadptr);
        InsertionAtbeginning(ptrheadptr);
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
        Rev_list(ptrheadptr,NULL);*/
        free(head1);
        free(head2);
        head1 = NULL;
        head2 = NULL;
    }while(ch != '\n');
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
void InsertionAtbeginning(struct node** ptrheadptr)
{
    struct node* a = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter Integer : ");
    scanf("%d",&a->data);
    struct node* head = *ptrheadptr;
    a->next = head;
    *ptrheadptr = a;
}
void InsertionAtend(struct node** ptrheadptr)
{
    struct node* a = (struct node*)malloc(sizeof(struct node));
    printf("Enter Integer : ");
    scanf("%d",&a->data);
    if(*ptrheadptr == NULL)
    {
        *ptrheadptr = a;
        a->next = NULL;
    }
    else
    {
        struct node* lastNode = Traversal(ptrheadptr);
        lastNode->next = a;
        a->next = NULL;
    }
}
void InsertionAtposition(struct node** ptrheadptr,int n)//inserts a node at nth position...position number starts from 0
{
    int position_counter=1;
    struct node* head = *ptrheadptr, *temp = head, *temp2 = head;
    struct node* a = (struct node*)malloc(sizeof(struct node));
    printf("Enter Integer : ");
    scanf("%d",&a->data);
    while(position_counter < n && temp != NULL)
    {
        temp2 = temp;
        temp = temp->next;
        position_counter++;
    }
    a->next = temp;
    if(n != 1)
        temp2->next = a;
    else
        *ptrheadptr = a;
}
void DeletionAtposition(struct node** ptrheadptr,int n)
{
    int position_counter=0;
    struct node* head = *ptrheadptr, *temp = head, *temp2 = head;
    if(n == 1)
        *ptrheadptr = head->next;
    else
    {
        while(position_counter < n-1 && temp != NULL)
        {
            temp2 = temp;
            temp = temp->next;
            position_counter++;
        }
        temp2->next = temp->next;
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
void Rev_list(struct node** ptrheadptr, struct node* current)
{
    struct node *temp = *ptrheadptr;
    if(*ptrheadptr == NULL)
        printf("List is Empty...\n");
    else
    {
        if(current != *ptrheadptr)
        {
            while(temp->next != current )
                temp = temp->next;
            printf("%d  ",temp->data);
            Rev_list(ptrheadptr,temp);
        }
    }
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
/*1. Write an algorithm to inset a new node before the last node of a linked list 
using a single additional pointer. (10)*/
void insert_befoe_last(struct node** head,struct node* new)
{
    struct node* temp = *head;
    if(temp->next == NULL )
    {
        new->next = temp; 
        *head = new;
    }
    else
    {
        while(temp->next->next != NULL)
            temp = temp->next;
        new->next = temp->next;
        temp->next = new;
    }
}
void print_common(struct node* head1, struct node* head2)
{
    struct node* temp1 = head1, *temp2 = head2;
     int key = temp1->data;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp2->data == key)
        {
            printf("%d ",key);
            while(key == temp2->data)
                temp2 = temp2->next;
            while (key == temp1->data)
                temp1 = temp1->next;
            key = temp1->data;
        }
        while(key < temp2->data)
        {
            temp1 = temp1->next;
            key = temp1->data;
        }
        while(key > temp2->data)
            temp2 = temp2->next;
    }
}