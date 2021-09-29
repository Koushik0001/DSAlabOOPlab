#include<iostream>
using namespace std;
int sub(int a, int b=20);
int main()
{
	int a = 100, b = 400, result;
	result = sub(b,a);
	cout << "Value 1 : " << result << endl;
	result = sub(a);
	cout << "value 2 : " << result<< endl;
	return 0;
}

int sub(int a, int b)
{
	int result;
	result = a-b;
	return result;
}