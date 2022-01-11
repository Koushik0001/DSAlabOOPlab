/*4. Write C program for implementing Merge sort methods to arrange a list of 
integers in ascending order*/
#include<stdio.h>
#include<stdlib.h>
 void merge_sort(int*,int,int);
 void merge(int* ,int, int, int );

int main()
{
    int *A,i,j,nn,k;
    printf("How many numbrs you wnat to sort : ");
    scanf("%d",&nn);

    A=(int*) malloc(nn*sizeof(int));
    
    printf("Enter the integers.\n");
    for(i=0;i<nn;i++)
        scanf("%d",&A[i]);
    merge_sort(A,0,nn-1);

    for(i=0;i<nn;i++)
        printf("%d ",A[i]);
    return 0;
}

void merge_sort(int*A,int p, int r)
{
    int q;
    if(p<r)
    {
        q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

void merge(int*A,int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1],R[n2+1];
    for(int i= 0;i<n1;i++)
        L[i] = *(A+p+i);
    for(int j = 0; j<n2; j++)
        R[j] = *(A+q+j+1);
    L[n1]=2147483647;
    R[n2]=2147483647;

    int i=0, j=0;
    for (int k = p;k <= r;k++)
    {
        if(L[i]<=R[j])
        {
            *(A+k) = L[i];
            i++;
        }
        else
        {
            *(A+k) = R[j];
            j++;
        }
    }   
}