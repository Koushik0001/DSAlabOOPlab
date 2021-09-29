/*5. Write a program to display Celsius to Fahrenheit conversion table using a for loop. Consider only 0˚ to 100˚ 
Celsius. Declare variables when they are used for the first time.*/
#include<iostream>
#include "iomanip"
using namespace std;

int main()
{
    cout << setw(10) << "celsius" << setw(15) << "Farenheit" << endl;
    for(float c=0,f; c<=100; c++)
    {
        f = (9.0/5.0)*c + 32;
        cout << setw(10) << c << setw(15) << f << endl;
    }
    return 0;
}