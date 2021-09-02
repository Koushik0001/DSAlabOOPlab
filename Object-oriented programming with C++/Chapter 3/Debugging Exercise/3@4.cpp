#include<iostream>
#define pi 3.14
using namespace std;

int squareArea(int &);
int circleArea(int &);

int main()
{
    int a = 10;
    cout << squareArea(a) << "\t";
    cout << circleArea(a) << "\t";
    cout << a << endl;
    return 0;
}

int squareArea(int &b)
{
    return(b *= b );
}

int circleArea(int &r)
{
    return (r *= pi * r/r);
}