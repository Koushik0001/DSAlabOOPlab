//13. Write an inline function add() that takes three integer arguments and returns the sum of these arguments. 
#include<iostream>
using namespace std;
inline int add(int a, int b, int c)
{
    return(a+b+c);
} 
int main()
{
    cout << "2 + 3 + 5 = " << add(2,3,5); 
    return 0;
}