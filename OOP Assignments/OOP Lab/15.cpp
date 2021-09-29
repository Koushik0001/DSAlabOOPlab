/*15. Consider the following two scenarios: 
a) We want to find out the maximum between three integers. 
b) We also want to find out the maximum element of an array of integers. 
Write two overloaded functions for these two scenarios. */
#include<iostream>
using namespace std;
int max(int,int,int);
int max(int* &, int);
int main()
{
    int *a;
    a = new int[10]{1,2,3,4,4,5,6,9,8,7};
    int m = max(58,18,9);
    cout << "max among 58, 18, 9 is " << m << endl;
    m = max(a,10);
    cout << "max in the array {1,2,3,4,4,5,6,9,8,7} is " << m;
    return 0;
}
int max(int a, int b, int c)
{
    if(a>b)
    {
        if(a>c)
            return a;
        else
            return c;
    }
    else if(b>c)
        return b;
    else 
        return c; 
}
int max(int* & x, int n)
{
    int temp = x[0]; 
    for(int i=0; i<n; i++)
    {
        if(x[i] > temp)
        {
            temp  = x[i];
            continue;
        }
    }
    return temp;
}