/*6. Write C program for implementing Selection sort methods to arrange a list 
of integers in ascending order */
#include<stdio.h>
#include<stdlib.h>
void selection_sort(int *,int);
int main()
{
    int *arr, n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    arr = (int*) malloc(n*sizeof(int));
    printf("Enter the elements : ");
    fflush(stdin);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    selection_sort(arr,n);
    printf("\nThe sorted array : ");
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    return 0;
}
void selection_sort(int *arr,int n)
{
    int no_swap = 0, no_comp = 0;
    for(int i=0; i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                no_swap++;
            }
            no_comp++;
        }
    }
    printf("\nNo of Comparison = %d",no_comp);
    printf("\nNo of Swapping = %d",no_swap);
}