/*8. Write a program that will create two link lists and lists are in sorted order and 
when you ask to merge them, it will merge the lists and generate a sorted list and 
display the resultant list. */

#include<stdio.h>
#include<stdlib.h>
struct node* insert(struct node* head, int d);
struct node* create(struct node* head);
void print(struct node* head);
struct node* merge(struct node* head1, struct node* head2,struct node* merged);
struct node
{
    int data;
    struct node* next;
};

int main()
{
    struct node* head1 = NULL, *head2 = NULL, *merged;

    printf("Enter the first Linked list:\n\t");
    head1 = create(head1);
    printf("Enter the second Linked list:\n\t");
    head2 = create(head2);
    printf("First Linked list in sorted order : ");
    print(head1);
    printf("\nSecond Linked list in sorted order : ");
    print(head2);
    printf("\nThe Merged Linked list is : ");
    merged = merge(head1,head2,merged);
    print(merged);
   return 0;
}
struct node* insert(struct node* head, int d)
{
    struct node*  temp;
    struct node* newp = malloc(sizeof(struct node));
    newp->data = d;
    newp->next = NULL;

    if(head == NULL || d< head->data)
    {
        newp->next = head;
        head = newp;
    }
    else
    {
        temp = head;
        while(temp->next != NULL && temp->next->data <= d)
            temp = temp->next;
        newp->next = temp->next;
        temp->next = newp;
    }
    return head;
}
struct node* create(struct node* head)
{
    int n;
    int data;

    printf("enter the number of elements: ");
    scanf("%d",&n);

    for (int i=0; i<n; i++)
    {
        printf("Enter the data: ");
        scanf("%d",&data);

        head = insert(head,data);
    }
    return head;    
}
void print(struct node* head)
{
    if(head == NULL)
        printf("List is empty...");
    else
    {
        struct node* temp = head;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
struct node* merge(struct node* head1, struct node* head2,struct node * merged)
{
    if(head1 == NULL)
        merged = head2;
    else if(head2 == NULL)
        merged = head2;
    else
    {
        struct node *h1 = head1, *h2 = head2;
        while (h1 != NULL && h2 != NULL)
        {
            if(h1->data <= h2->data)
            {
                merged = insert(merged,h1->data);
                h1 = h1->next; 
            }
            else if(h2->data <= h1->data)
            {
                merged = insert(merged,h2->data);
                h2 = h2->next;
            }
        }
        if(h1==NULL)
        {
            while(h2 != NULL)
            {
                merged = insert(merged,h2->data);
                h2 = h2->next;
            }
        }
        else if(h2 == NULL)
        {
            while(h1 != NULL)
            {
                merged = insert(merged,h1->data);
                h1 = h1->next;
            }
        } 
    }
    return merged;
}
