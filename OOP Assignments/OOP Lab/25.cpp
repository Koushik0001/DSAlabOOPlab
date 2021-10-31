/*25. Write the definition for a class called Complex that has private floating point data members for storing real and 
imaginary parts. The class has the following public member functions: 
setReal() and setImg() to set the real and imaginary part respectively. 
getReal() and getImg() to get the real and imaginary part respectively. 
disp() to display complex number object 
sum() to sum two complex numbers & return a complex number 
Write main function to create three complex number objects. Set the value in two objects and call sum() to 
calculate sum and assign it in third object. Display all complex numbers. */
#include<iostream>
using namespace std;
class complex
{
    float real, img;
    public :
        void setReal();
        void setImg();
        float getReal() {return real;}
        float getImg()  {return img;}
        void disp()     {cout << real << " + " << img << "i" << endl;}
        complex sum(complex &);
};

int main()
{
    complex a,b,c;
    a.setReal();
    a.setImg();
    b.setReal();
    b.setImg();
    c = a.sum(b);
    a.disp();
    b.disp();
    c.disp();
    return 0;
}
void complex::setReal()
{
    cout << "Enter the real part : ";
    cin >> real;
}
void complex::setImg()
{
    cout << "Enter the imaginary part : ";
    cin >> img;
}
complex complex::sum(complex & a)
{
    complex result;
    result.real = real + a.real;
    result.img = img + a.img;
    return result;
}