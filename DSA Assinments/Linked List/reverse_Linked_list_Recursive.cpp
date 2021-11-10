#include<iostream>
using namespace std;

class node
{
        char i;
        node* next;

    public :
        static node* head;
        static node* curr;
        static node* previous;
        static node* following;
        static char j;
        node(int x){i =x ;}
        node(){i = 0;}
        void insert_At_end(node* &);
        ~node(){};
        void diaplay();
        void rev(node*);
};

node* node::head = NULL;
node* node::curr = NULL;
node* node::previous = NULL;
node* node::following = NULL;
char node::j = 'A';


void node::insert_At_end(node* &ne)
{
    ne->i = j;
    j++;
    curr = head;
    if(head == NULL)
    {
        head = ne;
        ne->next = NULL;
    }
    else
    {
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = ne;
        ne->next = NULL;
    }
}
void node::diaplay()
{

    curr = head;
    while(curr != NULL)
    {
        cout << curr->i << "  ";
        curr = curr->next;
    }
    cout << endl;
}
void node::rev(node* h)
{
    if(h->next == NULL)
    {
        head = h;
        return;
    }
    h->rev(h->next);
    following = h->next;
    following->next = h;
    h->next = NULL;
}
int main()
{
    for(int k=0;k<=10; k++)
    {
        node* ne = new node;
        ne->insert_At_end(ne);
    }
    node* ne;
    ne->diaplay();  
    ne->rev(node::head); 
    cout << endl << "After reversing the linked list..." << endl << endl;
    ne->diaplay(); 
    return 0;
}