#include<iostream>
using namespace std;

class matrix;
class node
{
    private:
        int data;
        node *next,*down;
    public:
        node(int x=0):data(x),next(NULL),down(NULL){}
        ~node(){}
        friend class matrix;
};
class matrix
{
    private:
        node* head;
        int row, column;
    public:
        matrix(int, int);
        ~matrix(){};
        void diplay_matrix();
        void new_matrix();
        void insert_data(int,int,int);
        int get_row_number(){ return row;}
        int get_column_number(){ return column;}
};
matrix::matrix(int r,int c)
{
    head = NULL;
    row = r;
    column = c;
}
void matrix::new_matrix()
{
    node* temp1, *temp2, *temp3;
    node* ne = new node;
    head = ne;
    temp1 = ne;
    for(int i=0; i<column-1; i++)
    {
        node *c = new node;
        temp1->next = c;
        temp1 = temp1->next;
    }
    temp1 = head;
    for(int i=0; i<column; i++)
    {   
        temp2 = temp1;
        for(int j=0; j<row-1; j++)
        {
            node* r = new node;
            r->data = 5;
            r->next = NULL;
            r->down = NULL;
            temp2->down = r;
            temp2 = temp2->down;
        }
        temp1 = temp1->next;
    }
    temp1 = head;
    while(temp1->down != NULL)
    {
        temp2 = temp1;
        temp3 = temp2->next;
        while(temp3 != NULL)
        {
            (temp2->down)->next = temp3->down;
            temp2 = temp3;
            temp3 = temp3->next;
        }
        temp1 = temp1->down;
    }
}
void matrix::insert_data(int d,int r, int c)
{
    node* temp = head;
    int i=0, j=0;
    node *rptr = head;
    node *cptr;
    while(i<r)
    {
        i++;
        rptr = rptr->down;
    }
    cptr = rptr;
    while(j<c)
    {
        j++;
        cptr = cptr->next;        
    }
    cptr->data = d;
}

void matrix::diplay_matrix()
{
    node *temp1,*temp2;
    temp1 = head;
    while(temp1 != NULL)
    {
        temp2 = temp1;
        while(temp2 != NULL)
        {
            cout << temp2->data << " ";
            temp2 = temp2->next;
        }
        cout << endl;
        temp1 = temp1->down;
    }
}
int main()
{
    int r,c;
    cout << "Enter number of Rows : ";
    cin >> r;
    cout << "Enter number of columns : ";  
    cin >> c;
    matrix a(r,c);
    a.new_matrix();
    int data;
    for(int i=0; i<r; i++)
    {
        for(int j=0;j<c; j++)
        {
            cin >> data;
            a.insert_data(data,i,j);//insert k at i,j location of the matrix...
        }
        cout << endl;
    }
    cout << "The matrix is : "<< endl;
    a.diplay_matrix();
    return 0;
}