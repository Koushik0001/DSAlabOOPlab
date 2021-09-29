/*2. Now perform the swapping without using a third variable.*/

#include<iostream>

using namespace std;
int main()
{
	char op = 'n';
	do
	{
		int x, y;
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		x = x + y;
		y = x - y;
		x = x - y;
		cout << "x = " << x << endl << "y = " << y;
		cout << "Do you want to run again (y/n) : ";
		cin >> op;
	}while(op == 'y');
	return 0;
}
//int a = 10, b = 20;4
//printf("Before swap a=%d b=%d", a, b);
//a = a + b;//a=30 (10+20)
//b = a - b;//b=10 (30-20)
//a = a - b;//a=20 (30-10)