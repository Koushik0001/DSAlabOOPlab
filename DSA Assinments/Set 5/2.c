/*2. Write C program for implementing Bubble sort methods to arrange a list of 
integers in ascending order.  */
#include<stdio.h>
#include<stdlib.h>
void Bubble_sort(int *,int);
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
    Bubble_sort(arr,n);
    printf("\nThe sorted array : ");
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    return 0;
}

void Bubble_sort(int *arr,int n)
{
    int iteration = 0,no_shifting = 0, no_comp = 0;
    while(iteration<n-1)
    {
        for(int i=0; i<n-iteration; i++)
        {
            if(arr[i]>arr[i+1])
            {
                int t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
                no_shifting++;
            }
            no_comp++;
        }
        iteration++;
    }
    printf("\nNo of Comparison = %d",no_comp);
    printf("\nNo of Shifting = %d",no_shifting);
}