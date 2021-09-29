#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
void enterf(int ** ,int,int);
void show(int **,int,int);
int main()
{
	int m,n, **matrix;
	cout << "Enter the order of the matrix (row * column) : ";
	cin >> m >> n;
	matrix = (int**)calloc(sizeof(int*),m);
	for (int i=0; i<n; i++)
		matrix[i] = (int*)calloc(sizeof(int),n);
	
	enterf(matrix,m,n);
	show(matrix,m,n);
	return 0;
}

void enterf(int ** matrix,int m, int n)
{
	cout << "Enter the elements of the matrix : " << endl;
	for(int i = 0; i<m; i++)
	{
		for(int j=0; j<n ; j++)
			cin >> matrix[i][j];
	}
}

void show(int ** matrix,int m, int n)
{
	for(int i = 0; i<m; i++)
	{
		for(int j=0; j<n ; j++)
			cout << setw(5) << matrix[i][j];
		cout << endl;
	}
}