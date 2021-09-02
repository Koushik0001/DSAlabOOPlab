#include<iostream>

using namespace std;
void swap(int &, int &);

int main()
{
    int a=10, b=9;
    cout << "a = " << a << '\t' << "b = " << b;
    swap(a,b);
    cout << endl << "a = " << a << '\t' << "b = " << b;
    return 0;
}

void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t; 
}