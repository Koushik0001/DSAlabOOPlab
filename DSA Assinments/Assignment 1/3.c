/*3. Write a C program to 
Create an array of 15 data. 
-> Inset an element after 6th Data. 
-> Delete an element after 6th Data*/

#include<stdio.h>
#include<stdlib.h>
void get_data(int*);
void insert(int*,int);
void delete(int*,int);
void display(int*);
int size;
int main()
{
    int *array = (int*)malloc(15 * sizeof(int));
    get_data(array);
    display(array);
    insert(array,6);
    display(array);
    delete(array,6);    
    display(array);
    return 0;
}
void get_data(int* ar)
{
    printf("Enter the number of elements you want to enter : ");
    scanf("%d",&size);
    printf("Enter the elements : ");
    for (int i=0; i<size; i++)
        scanf("%d",&ar[i]);
}
void insert(int* ar,int x)
{
    if(x==14)
        printf("Array overflow...\n");
    else
    {
        for(int i=size-1; i>x; i--)
        {
            ar[i+1] = ar[i];
        }    
        printf("Enter the element : ");
        scanf("%d",&ar[x+1]);
        size++;
    }
}
void delete(int* ar, int x)
{
    for(int i=x+2; i<size; i++)
        ar[i-1] = ar[i];
    size--;
}
void display(int *ar)
{
    printf("The elements of the array are : ");
    for(int i=0; i<size; i++)
        printf("%d  ",ar[i]);
    printf("\n");
}