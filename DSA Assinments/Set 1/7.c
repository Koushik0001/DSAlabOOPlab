/*7. Write a program to add two polynomials using nexted List. for example, your
program will ask to input two polynomials. If you Input: 
 1st polynomial = 5x^3 + 4x^2 + 2x^0
 2nd polynomial = 5x^1 + 5x^0
Output: 
 5x^3 + 4x^2 + 5x^1 + 7x^0 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
    float coeff;
    int expo;
    struct node* next;
};
struct node* insert(struct node* head, float co, int ex)
{
    struct node*  temp;
    struct node* newp = malloc(sizeof(struct node));
    newp->coeff = co;
    newp->expo = ex;
    newp->next = NULL;

    if(head == NULL || ex> head->expo)
    {
        newp->next = head;
        head = newp;
    }
    else
    {
        temp = head;
        while(temp->next != NULL && temp->next->expo >= ex)
            temp = temp->next;
        newp->next = temp->next;
        temp->next = newp;
    }
    return head;
}
struct node* create(struct node* head)
{
    int n;
    float coeff;
    int expo;

    printf("enter the number of terms: ");
    scanf("%d",&n);

    for (int i=0; i<n; i++)
    {
        printf("Enter the coefficient for term %d: ",i+1);
        scanf("%f",&coeff);

        printf("Enter the exponent for term %d: ",i+1);
        scanf("%d",&expo);

        head = insert(head, coeff, expo);
    }
    return head;    
}
void print(struct node* head)
{
    if(head == NULL)
        printf("No polynomial...");
    else
    {
        struct node* temp = head;
        while(temp != NULL)
        {
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp = temp->next;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
            
        }
    }
}
void polyAdd(struct node* head1, struct node* head2)
{
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    while(ptr1!=NULL && ptr2!= NULL)
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff+ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if(ptr2->expo > ptr1->expo)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
    printf("Added polynomial is: ");
    print(head3);
}
int main()
{
    struct node* head1 = NULL, *head2 = NULL;

    printf("Enter the first polynomial:\n\t");
    head1 = create(head1);
    printf("Enter the second polynomial:\n\t");
    head2 = create(head2);

    polyAdd(head1,head2);
   return 0;
}