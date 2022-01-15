#include<stdio.h>
#include<stdlib.h>
struct node
{
    char key;
    struct node *left, *right, *parent; 
}*Root = NULL;
void insert(char key);
void Inorder_Tree_walk(struct node* Root);
int main()
{
    for(int i=0; i<9; i++)
    {
        insert('A'+i);
    }
    Inorder_Tree_walk(Root);
    return 0;
}
void insert(char key)
{
    struct node* temp = Root,*tracer = Root,*temp2;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;
    if(Root == NULL)
        Root = new;
    else
    {
        while (temp != NULL)
        {
            if(key <= tracer->key)
            {
                temp = tracer->left;
            }
            else
            {
                temp = tracer->right;
            }
        }
        printf("################\n");
        if(key <= tracer->key)
        {
            tracer->left = new;
            new->parent = tracer;
        }
        else
        {
            tracer->right = new;
            new->parent = tracer;
        }
    }
}
void Inorder_Tree_walk(struct node* Root)
{
    struct node* temp = Root;
    if(temp != NULL)
    {
        Inorder_Tree_walk(temp->left);
        printf("%c  ",temp->key);
        Inorder_Tree_walk(temp->right);
    }
}