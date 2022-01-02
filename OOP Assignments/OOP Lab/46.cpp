/*46. Two integers are taken from keyboard. Then perform division operation. Write a try block to throw an exception 
when division by zero occurs and appropriate catch block to handle the exception thrown. */
#include<iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout<<"Enter the numbers : ";
    cin >> num1 >> num2;

    try
    {
        if(num2!=0)
        {
            float result = num1/static_cast<float>(num2);
            cout << num1 << '/'<< num2 << " = "<< result;
        }
        else 
            throw 0;
    }
    catch(int a)
    {
        cout << "Exception thrown : Division by Zero";
    }
    return 0;
}