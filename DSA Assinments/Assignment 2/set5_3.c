#include<stdio.h>
#include<stdlib.h>
void Insertion_sort(int *,int);
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
    Insertion_sort(arr,n);
    printf("\nThe sorted array : ");
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    return 0;
}

void Insertion_sort(int *arr,int n)
{
    int no_shifting = 0, no_comp = 0;
    for(int i=1; i<n;i++)
    {
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
            no_shifting++;
        }
        no_comp++;
        arr[j+1] = current;
    }
    printf("\nNo of Comparison = %d",no_comp);
    printf("\nNo of Shifting = %d",no_shifting);
}