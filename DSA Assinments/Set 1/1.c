//Write a C program to read array elements using pointers and print with addresses.
#include<stdio.h>
#include<stdlib.h>
void read_n_print(int*, int);
int main()
{
    int n, *array;
    printf("Enter the numbers of elements : ");
    scanf("%d",&n);
    array = (int*)malloc(n * sizeof(int));
    printf("Enter the elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",(array+i));
    read_n_print(array,n);
    return 0;
} 
void read_n_print(int* arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",*(arr+i));
    }
}