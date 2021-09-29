#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int m,n;
	cout << "Enter the order of the matrix (row * column) : ";
	cin >> m >> n;
	int matrix[m][n];
	cout << "Enter the elements of the matrix : " << endl;
	for(int i = 0; i<m; i++)
	{
		for(int j=0; j<n ; j++)
			cin >> matrix[i][j];
	}
	for(int i = 0; i<m; i++)
	{
		for(int j=0; j<n ; j++)
			cout << setw(5) << matrix[i][j];
		cout << endl;
	}
	
    return 0;
}