/*16. Write two overloaded functions print() such that one prints the elements of a vector and the other prints elements 
of a matrix. Note that a vector and a matrix may be represented as a one-dimensional array and a two-dimensional array respectively.*/
#include<iostream>
using namespace std;
void print(int* &, int);
void print(int** &, int, int);

int main()
{
    int *vector, **matrix;
    int n = 10, r = 3, c = 4;
    vector = new int[n]{1,2,3,4,5,6,7,8,9,0};
    matrix = new int*[3];
    matrix[0] = new int[c]{1,2,3,4};
    matrix[1] = new int[c]{5,6,7,8};
    matrix[2] = new int[c]{9,8,5,6};
    cout << "The vector is : ";
    print(vector, n);
    cout << "The matrix is : "<<endl;
    print(matrix,r,c);
    return 0;
}
void print(int* & v, int n)
{
    for(int i=0; i<n; i++)
        cout << v[i] <<' ';
    cout << endl;
}
void print(int** & m, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout << m[i][j] << '\t';
        cout << endl;
    }
}

