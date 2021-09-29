#include<iostream>
using namespace std;
double power(double,int n = 2);
int main()
{
    int n;
    double m;
    cout << "Enter the value of m and n (m^n) : ";
    cin >> m >> n;
    cout << m << "^" << n << " = " << power(m,n) << endl;
    cout << m << "^2" << " = " << power(m) << endl;
    return 0;
}

double power(double m, int n)
{
    double result = m;
    for(int i=1; i<n; i++)
        result *= m;
    return result;
}