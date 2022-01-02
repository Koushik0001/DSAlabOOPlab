/*4. Create a Linked list of 10 nodes. (Write a function InsertionAtend() and a 
function Traversal() to create this) */
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* Traversal(struct node**);
void InsertionAtend(struct node**);
void display(struct node**);
int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node **headptr = &head;
    head = NULL;
    for(int i=0; i<10; i++)
    {
        InsertionAtend(headptr);
    }
    display(headptr);
}
struct node* Traversal(struct node** headptr)
{    
    struct node *temp = *headptr;

    if(temp == NULL)
        return temp;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        return temp;
    }
}
void InsertionAtend(struct node** headptr)
{
    struct node* a = (struct node*)malloc(sizeof(struct node));
    printf("Enter Integer : ");
    scanf("%d",&a->data);
    if(*headptr == NULL)
    {
        *headptr = a;
        a->next = NULL;
    }
    else
    {
        struct node* lastNode = Traversal(headptr);
        lastNode->next = a;
        a->next = NULL;
    }
}
void display(struct node** headptr)
{
    struct node *temp = *headptr;

    if(*headptr == NULL)
        printf("List is Empty...\n");
    else
    {
        while(temp->next != NULL)
        {
            printf("%d  ",temp->data);
            temp = temp->next;
        }
    }
}