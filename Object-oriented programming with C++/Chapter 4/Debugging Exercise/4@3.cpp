#include<iostream>
using namespace std;
void fun(int);
int main()
{
	int n;
	cout << "Enter the value of n : ";
	cin >> n;
	fun(n);
    return 0;
}

void fun(int n)
{
	if(n == 0)
		cout << n;
	else
	{
		cout << n <<endl;
		fun(--n);
	}
}