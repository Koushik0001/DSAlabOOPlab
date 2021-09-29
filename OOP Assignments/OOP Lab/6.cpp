/*6. Write a program that defines a constant PI and takes radius of a circle from keyboard and prints area of that 
circle. */
#include<iostream>
#define PI 3.141592654
using namespace std;

int main()
{
    cout << "Enter the radius of the circle : ";
    float r;
    cin >> r;
    cout << "Area = " << PI * r * r << endl;  
    return 0;
}