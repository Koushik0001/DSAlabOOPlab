#include<stdio.h>
#include<stdlib.h>
float **sparce_matrix,**triplet;
int row,column,non_Zero = 0;
void Enter_matrix();
void convert_to_triplet();
void display_triplet();
void display_sparce();
int main()
{
    Enter_matrix();
    display_sparce();
    convert_to_triplet();
    display_triplet();
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
void convert_to_triplet()
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<column; j++)
        {
            if(sparce_matrix[i][j] != 0)
                non_Zero++;
        }
    }
    
    triplet = (float**)malloc((non_Zero+1) * sizeof(float*));
    for(int i=0; i<(non_Zero+1); i++)
        triplet[i] = (float*)malloc(3*sizeof(float));

    triplet[0][0] = (float)row;
    triplet[0][1] = (float)column;
    triplet[0][2] = non_Zero;
    int temp = 1;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<column; j++)
        {
            if(sparce_matrix[i][j])
            {
                triplet[temp][0] = i;
                triplet[temp][1] = j;
                triplet[temp][2] = sparce_matrix[i][j];
                temp++;
            }
        }
    }   
}
void display_triplet()
{
    printf("\nValues of Triplet matrix are : \n");
    for (int i=0; i<non_Zero+1; i++)
    {
        for (int j=0; j<3; j++)
            printf("%f  ",triplet[i][j]);
        printf("\n");
    }
    printf("\n");
}
void display_sparce()
{
    printf("\nValues of Entered matrix are : \n");
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<column; j++)
            printf("%f  ",sparce_matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}