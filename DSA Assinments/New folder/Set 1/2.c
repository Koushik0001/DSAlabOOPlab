/*2. Write a C program to create a structure which will store the information 
about the students (Roll No, Name, and Percentage of Marks). 
a. Write a function to add a new record. 
b. Write a function to display all existing record. 
c. Write a function to search a record for any condition. 
d. Write a function to modify a record. 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void add();
void display();
void con_display();
void modify();
struct student
{
    char* name;
    int roll;
    float percent_marks;

};
struct node
{
    struct student s_data;
    struct node *next;
};
struct node* getdata(); 
struct node *head = NULL, *curr, *temp;
int main()
{
    int n =0;
    printf("Enter number of students : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        add();
    char c = 'y';
    do
    {
        printf("Enter what do you want to do :\n\t1)Add Student\n\t2)Display all existing record\n\t3)Display specific student\n\t4)Modify record\n\t5)exit");
        int op;
        fflush(stdin);
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            con_display();
            break;
        case 4:
            modify();
            break;
        case 5:
            exit(0);
        }
        printf("Do you want to do anythig agin...(y/n) :");
        fflush(stdin);
        c = getchar();
    }while(c == 'y');
    return 0;
}
void add()
{
    struct node* a = getdata();
    a->next = NULL;
    if(head == NULL)
        head = a;
    else
    {
        curr = head;
        temp = head;
        while(curr != NULL)
        {
            temp = curr;
            curr = curr->next;
        }
        temp->next = a;
    }
}
void display()
{
    printf("Showing all existing records : \n");
    if(head == NULL)
        printf("No record exists...\n");
    else
    {
        curr = head;
        while(curr != NULL)
        {
            printf("Name : ");
            puts(curr->s_data.name);
            printf("Roll No. %d\n",curr->s_data.roll);
            printf("Percentage marks : %f\n\n\n",curr->s_data.percent_marks);
            curr = curr->next;
        }
    }
}

void con_display()
{
    int r;
    printf("Enter the roll no. you want to see : ");
    scanf("%d",&r);
    if(head == NULL)
        printf("No record exists...\n");
    else
    {
        curr = head;
        while (curr != NULL && curr->s_data.roll != r)
            curr = curr->next;
        
        if(curr == NULL)
            printf("Entered roll no. does not exist...\n");
        else
        {
            puts(curr->s_data.name);
            printf("Roll No. %d\n",curr->s_data.roll);
            printf("Percentage marks : %f\n\n\n",curr->s_data.percent_marks);
        }
    }
}

void modify()
{
    int r;
    printf("Enter the roll no. you want to update : ");
    scanf("%d",&r);
    if(head == NULL)
        printf("No record exists...\n");
    else
    {
        curr = head;
        while (curr != NULL && curr->s_data.roll != r)
            curr = curr->next;
        
        if(curr == NULL)
            printf("Entered roll no. does not exist...\n");
        else
        {
            int op = 3;
            printf("What do you want to update\n\t1)Name\n\t2)Marks\n\t3)Cancel\nEnter option : ");
            scanf("%d",&op);
            switch (op)
            {
            case 1:
                printf("Enter new name : ");
                char *nam = (char*)malloc(16 * sizeof(char));
                fflush(stdin);
                gets(nam);
                strcpy(curr->s_data.name, nam);
                free(nam);
                break;

            case 2:
                printf("Enter new persantage marks : ");
                scanf("%f",&curr->s_data.percent_marks);
                break;
            case 3:
                ;
            }
        }
    }
}
struct node* getdata()
{   
    struct node* a = (struct node*)malloc(sizeof(struct node));
    a->s_data.name = (char*)malloc(16 * sizeof(char));
    printf("Enter the name : ");
    fflush(stdin);
    gets(a->s_data.name);
    printf("Enter Roll No. ");
    fflush(stdin);
    scanf("%d",&a->s_data.roll);
    printf("Enter percentage : ");
    fflush(stdin);
    scanf("%f",&a->s_data.percent_marks);
    printf("\n\n");
    return a;
}

