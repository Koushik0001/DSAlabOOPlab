#include<stdio.h>
#include<stdlib.h>
float **sparce_matrix;
int row,column;
struct node
{
    int row, column;
    float value;
    struct node* next;
}*head = NULL,*tail = NULL;
void Enter_matrix();
void create_linked_list();
void display_LinkedList_sparce();
void insert_node(int r,int c,float v);
int main()
{
    Enter_matrix();
    create_linked_list();
    display_LinkedList_sparce(); 
    return 0;
}
void Enter_matrix()
{
    printf("\nEnter the number of Rows : ");
    scanf("%d",&row);
    printf("Enter the number of Columns : ");
    scanf("%d",&column);
    sparce_matrix = (float**)malloc(row * sizeof(float*));
    for(int i=0; i<row; i++)
        sparce_matrix[i] = (float*)malloc(column * sizeof(float));
    printf("\nEnter the elements : \n");
    for (int i = 0; i<row; i++)
    {
        for (int j=0; j<column; j++)
            scanf("%f",&sparce_matrix[i][j]);
    }
    printf("\n");
}
void create_linked_list()
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<column; j++)
        {
            if(sparce_matrix[i][j] != 0 )
                insert_node(i,j,sparce_matrix[i][j]);
        }
    }   
}
void insert_node(int r,int c,float v)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->row = r;
    new->column = c;
    new->value = v;
    new->next = NULL;
    if(head == NULL)
    {
        head = new;
        tail = new;
    }
    else
    {
        tail->next = new;
        tail = tail->next; 
    }
}
void display_LinkedList_sparce()
{
    struct node* temp;
    temp = head;
    printf("Linked list representation of sparse matrix is : \n");
    while(temp != NULL)
    {
        printf("%d  %d  %f\n",temp->row,temp->column,temp->value);
        temp = temp->next;
    }
}