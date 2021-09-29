#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
void enterf(int ** & ,int,int m = 3);
void show(int ** &,int,int m = 3);
int main()
{
	int m,n, **matrix;
	cout << "Enter the order of the matrix (column) : ";
	cin >> n;
	matrix = (int**)calloc(sizeof(int*),m);
	for (int i=0; i<n; i++)
		matrix[i] = (int*)calloc(sizeof(int),n);
	
	enterf(matrix,n);
	show(matrix,n);
	return 0;
}

void enterf(int ** & matrix,int n, int m)
{
	cout << "Enter the elements of the matrix : " << endl;
	for(int i = 0; i<m; i++)
	{
		for(int j=0; j<n ; j++)
			cin >> matrix[i][j];
	}
}

void show(int ** & matrix,int n, int m)
{
	for(int i = 0; i<m; i++)
	{
		for(int j=0; j<n ; j++)
			cout << setw(5) << matrix[i][j];
		cout << endl;
	}
}