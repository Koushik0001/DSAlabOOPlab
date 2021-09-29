4/*1. Take 2 numbers and swap their values by using a third variable.*/

#include<iostream>

using namespace std;
int main()
{
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	swap(x, y);
	cout << "x = " << x << endl << "y = " << y;
	return 0;
}

