//31. Design a class Complex that includes all the necessary functions and operators like =, +, -, *, /. 
#include<iostream>
#include<math.h>
using namespace std;
class complex
{
    float real, img;
    public :
        complex(float x=0, float y=0){real=x; img=y;}
        ~complex(){}
        void setdata();
        float getReal() {return real;}
        float getImg()  {return img;}
        void disp()     {cout << real << " + " << img << "i" << endl;}

        void operator=(complex c)                   {real = c.real; img = c.img;}
        friend complex operator+(complex c, float a){return complex(c.real+a, c.img);}
        friend complex operator+(float a, complex c){return complex(c.real+a, c.img);}
        complex operator+(complex c)                {return complex(real+c.real, img+c.img);}
        friend complex operator-(complex c, float a){return complex(c.real-a, c.img);}
        friend complex operator-(float a, complex c){return complex(a-c.real, c.img);}
        friend complex operator-(complex c1, complex c2){return complex(c1.real-c2.real, c1.img-c2.img);}
        friend void operator-(complex & c){ c.real = -c.real; c.img = -c.img;}
        friend complex operator*(complex c, float a){return complex(c.real*a, c.img*a);}
        friend complex operator*(float a, complex c){return complex(c.real*a, c.img*a);}
        friend complex operator*(complex c1, complex c2)
        {
            return complex((c1.real*c2.real - c1.img*c2.img), (c1.real*c2.img + c2.real*c1.img));
        }
        friend complex operator/(complex c, float a){return complex(c.real/a, c.img/a);}
        friend complex operator/(float a, complex c)
        {
            float r,i;
            r = (a*c.real)/(pow(c.real, 2)+pow(c.img, 2));
            i = -(a*c.img)/(pow(c.real, 2)+pow(c.img, 2));
            return complex(r, i);
        }
        friend complex operator/(complex c1, complex c2)
        {
            float r, i;
            r = (c1.real*c2.real + c1.img*c2.img)/(pow(c2.real, 2)+pow(c2.img, 2));
            i = (c1.img*c2.real - c1.real*c2.img)/(pow(c2.real, 2)+pow(c2.img, 2));
            return complex(r,i);
        }
        

};
int main()
{
    complex a,b;
    a.setdata();
    b.setdata();

    cout << "\n\n";
    a.disp();
    b.disp();

    cout << "a+b = ";
    (a+b).disp();

    cout << "\n2+a = ";
    (2+a).disp();

    cout << "\na-b = ";
    (a-b).disp();

    cout << "\n2-a = ";
    (2-a).disp();

    cout << "\na*b = ";
    (a*b).disp();

    cout << "\n2*a = ";
    (2*a).disp();

    cout << "\na/b = ";
    (a/b).disp();

    cout << "\n16/a = ";
    (16/a).disp();

    cout << "\na/2 = ";
    (a/2).disp();

    -a;
    cout << "-a = ";
    a.disp();
}
void complex::setdata()
{
    cout << "Enter the real part : ";
    cin >> real;
    cout << "Enter the imaginary part : ";
    cin >> img;
}
