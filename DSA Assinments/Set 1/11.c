/*11. Write a program that will create a link list of integer numbers and when you ask to 
split the list, it will split the list into two different lists of odd and even numbers and display 
the resultant lists. */

#include<stdio.h>
#include<stdlib.h>
struct node* insert(struct node* head, int d);
struct node* create(struct node* head);
void print(struct node* head);
struct node* split(struct node* head1,struct node* head2);
struct node
{
    int data;
    struct node* next;
};
int main()
{
    struct node* head1 = NULL, *head2 = NULL;

    printf("Enter the Linked list:\n\t");
    head1 = create(head1);
    struct node* h1 = head1,*trace = h1,*h2 = head2 = NULL;
    while(h1 != NULL)
    {
        printf("%d\n",h1->data);
        if((h1->data)%2 == 0)
        {
            if(head2 = NULL)
            {
                head2 = h1;
                h2 = head2;
                h2->next = NULL;
                trace->next = h1->next;
                h1 = h1->next;
            }
            else
            {
                h2->next = h1;
                h2 = h2->next;
                h2->next = NULL;
                trace->next = h1->next;
                if(h1->next == NULL)
                    trace->next == NULL;
                h1 = h1->next;
            }
        }
        else
        {
            trace = h1;
            h1 = h1->next;
        }

    }
    printf("First Half of the Linked list in: ");
    print(head1);
    printf("\nSecond Half of the Linked list in: ");
    print(head2);
   return 0;
}
struct node* insert(struct node* head, int d)
{
    struct node*  temp;
    struct node* newp = malloc(sizeof(struct node));
    newp->data = d;
    newp->next = NULL;

    if(head == NULL)
    {
        newp->next = head;
        head = newp;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
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
    printf("Enter the data: ");
    for (int i=0; i<n; i++)
    {
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
/*struct node* split(struct node* head1,struct node* head2)
{
    struct node* h1 = head1,*trace = h1,*h2 = head2 = NULL;
    while(h1 !=NULL)
    {
        if((h1->data)%2 == 0)
        {
            if(head2 = NULL)
            {
                printf("***********************\n");
                head2 = h1;
                h2 = head2;
                h2->next = NULL;
                trace->next = h1->next;
                h1 = h1->next;
            }
            else
            {
                printf("####################\n");
                h2->next = h1;
                h2 = h2->next;
                h2->next = NULL;
                trace->next = h1->next;
                h1 = h1->next;
            }
        }
        else
        {
            printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
            trace = h1;
            h1 = h1->next;
        }

    }
    return head2;
}*/