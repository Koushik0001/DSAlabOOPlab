#include<iostream>
using namespace std;

int main()
{
    float f, c;
    cout << "Enter the temprature in farenheit : ";
    cin >> f;
    c = (f-32)*(5.0/9);
    cout << "The temprature in celsius is : " << c;
    return 0;
}
