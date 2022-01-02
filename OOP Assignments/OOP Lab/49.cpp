/*49. Write a template function max() that is capable of finding maximum of two things (that can be compared). Used 
this function to find (i) maximum of two integers, (ii) maximum of two complex numbers (previous code may be 
reused). Now write a specialized template function for strings (i.e. char *). Also find the maximum of two strings 
using this template function. */
#include<iostream>
using namespace std;

template<class type>
type fmax(type t1, type t2)
{
    return t1>t2 ? t1:t2;
}
template<class type>
class complex
{
    type a,b;
    public:
        complex(type x=0, type y=0):a(x),b(y){}
        bool operator >(complex c)
        {
            if((a+b)>(c.a+c.b))
                return true;
            else 
                return false;
        }
        void display()
        {
            cout << a << " + (" << b << "i)"; 
        }
};
int main()
{
    int a=10,b=5,c;
    c = fmax(a,b);
    cout << c << endl;
    
    complex <float> c1(25,-10),c2(15,-20),c3;
    c3 = fmax(c1,c2);
    c3.display();
}

