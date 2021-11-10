//1. Write an algorithm to count the length of a circular linked list.

#include<iostream>
using namespace std;

class node
{
        int i;
        node* next;
        static node* head;
        static node* ptr;
        static node* tail;
        static int j;
    public :
        node(int x){i =x ;}
        node(){i = 0;}
        void insert_At_end(node* &);
        ~node(){};
        void diaplay();
        int length_of_list();
        void insert(node* &);
};

node* node::head = NULL;
node* node::ptr = NULL;
node* node::tail = NULL;
int node::j = 0;
void node::insert_At_end(node* &ne)
{
    ne->i = j;
    j++;
    ptr = head;
    if(head == NULL)
    {
        head = ne;
        tail = ne;
    }
    else
    {
        tail->next = ne;
        tail = ne;
        tail->next = head;
    }
}
void node::diaplay()
{

    ptr =head;
    while (ptr->next != head)
    {
        cout << ptr->i << "  ";
        ptr = ptr->next;
    }
    cout << endl;
}

int node::length_of_list()
{
    ptr = head;
    int len = 0;
    while (ptr->next != head)
    {
        ptr = ptr->next;
        len++;
    }
    return len;    
}
void node::insert(node* & ne)
{
    ptr = head;
    if(head == NULL)
    {
        head = ne;
        tail = ne;
        ne->next = head;
    }
    else
    {
        tail->next = ne;
        tail = ne;
        tail->next = head;
    }
}
int main()
{
    node nel(50);
    node* n = &nel;
    nel.insert(n);
    for(int k=0;k<10; k++)
    {
        node* ne = new node;

        ne->insert_At_end(ne);
    }
    node* ne;
    ne->diaplay();
    cout << endl <<"Len = " << ne->length_of_list();
    return 0;
}