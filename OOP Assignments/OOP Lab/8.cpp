/*8. Write a function swap() that takes two integer arguments and interchanges the values of those arguments using 
reference. Now in the main function, instantiate two integer variables with some values. Print their values. Call 
the swap function with these variables. Finally print the values of those variables. Check the result. */
#include<iostream>
using namespace std;

void swap(int &, int &);
int main()
{
    int a = 5, b = 6;
    cout << "a = " << a << '\t' <<"b = " << b << endl;
    swap(a,b);
    cout << "a = " << a << '\t' <<"b = " << b << endl;
    return 0;
}

void swap(int & x, int & y)
{
    int t;
    t = x;
    x = y;
    y = t; 
}