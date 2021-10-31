/*4. Create a Linked list of 10 nodes. (Write a function InsertionAtend() and a 
function Traversal() to create this) */
#include<iostream>
using namespace std;
class node
{
    int data;
    node* next;

    public :
        friend node* & Traversal(node* &);
        friend void InsertionAtend(node*, node*);
        friend void display(node *);
};
int main()
{
    node *head;
    head = NULL;
    for(int i=0; i<10; i++)
    {
        node* a = new node;
        InsertionAtend(head, a);
    }
    display(head);
}
node* & Traversal(node* &temp)
{    
    if(temp == NULL)
        return temp;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        return temp->next;
    }
}
void InsertionAtend(node* head,node* a)
{
    node *temp = head;
    cout << "Enter data : ";
    cin >> a->data;
    Traversal(temp) = a;
}
void display(node* head)
{
    node* temp = head;
    if(temp == NULL)
        printf("\nEmpty....\n");
    while(temp->next != NULL)
        printf("%d  ",temp->data);
    printf("\n");
}