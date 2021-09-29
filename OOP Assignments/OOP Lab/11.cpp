/*11. Write a function that takes an integer and returns the factorial of that number. Declare function parameter as read
only reference. Call the function with some argument from main function, store the result and print it. */
#include<iostream>
using namespace std;

float facto(const int & );
int main()
{
    cout << "Enter the integer :";
    int num;
    cin >> num;
    float f = facto(num);
    cout << num << "! = " << f;
    return 0;
}
float facto(const int & x)
{
    if(x == 1)
        return 1;
    else
        return(x*facto(x-1));
}