#include<iostream>

using namespace std;
class temp
{
    float f, c;
    public :
        void teperature_conversion(void);
};

void temp :: teperature_conversion(void)
{
    cout << "Enter farenheit : ";
    cin >> f;
    c = (5.0/9)*(f-32);
    cout << "Celsius : " << c; 
}

int main()
{
    temp a;
    a.teperature_conversion();
}