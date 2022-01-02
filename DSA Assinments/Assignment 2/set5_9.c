/*9.Write a program to arrange an array of integer in following order:Odd indexed sub array (1, 3, etc) will be sorted in ascending order.
Even indexed sub array (0, 2, etc.) will be sorted in descending order .*/
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
    for(int i=0; i<n-1;i=i+2)
    {
        for(int j=i+2;j<n;j=j+2)
        {
            if(arr[j]>arr[i])
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    for(int i=1; i<n-1;i=i+2)
    {
        for(int j=i+2;j<n;j=j+2)
        {
            if(arr[j]<arr[i])
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}