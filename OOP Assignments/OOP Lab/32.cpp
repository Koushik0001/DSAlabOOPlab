/*32. Implement a class “Quadratic” that represents second-degree polynomial i.e. polynomial of float ax2+bx+c. The 
class will require three data members corresponding to a, b and c. Implement the following: 
a) A constructor (including a default constructor which create a null polynomial) 
b) Overload the addition operator to add two polynomials of degree 2. 
c) Overload << and >> operators to print and read polynomials. 
d) A function to compute the value of polynomial for a given x. 
e) A function to compute roots of the equation ax2+bx+c=0. Remember, root may be a complex number. 
You may implement “Complex” class to represent root of the quadratic equation.*/
#include<iostream>
#include<math.h>
using namespace std;
class complex
{
    float a,b;
    public:
        complex(float x=0, float y=0):a(x),b(y){}
        friend ostream &operator<<( ostream  &output, complex &z ) 
        { 
            output <<z.a << " + (" << z.b << "i)"; 
            return output;            
        }
};
class Quadratic
{
    float a,b,c;
    public:;
        Quadratic(){}
        Quadratic(float x, float y, float z):a(x),b(y),c(z){}
        Quadratic operator+(Quadratic f){return Quadratic(a+f.a,b+f.b,c+f.c);}
        friend istream &operator>>( istream  &input, Quadratic &Q ) 
        { 
            input >>Q.a>>Q.b>>Q.c;
            return input;            
        }
        friend ostream &operator<<( ostream  &output, Quadratic &Q ) 
        { 
            output << Q.a << "x^2 + ("<<Q.b<<"x) + ("<< Q.c <<")";
            return output;            
        }
        float fx(float x){return (a*x*x + b*x + c);}
        void root()
        {
            if(b*b < 4*a*c)
            {
                float p = pow((4*a*c - b*b),0.5)/(2*a);
                complex c1 = complex(-(b/2.0*a),p);
                complex c2 = complex(-(b/2.0*a),-p);
                cout << c1 << endl;
                cout << c2 << endl;
            }
            else
            {
                float r1 = pow((b*b - 4*a*c),0.5)/(2*a);

                cout <<-(b/(2.0*a)) + r1 << endl;
                cout << -(b/2.0*a)-r1 << endl;
            }
        }
};

int main()
{
    Quadratic q1(1,1,3);
    q1.root();
    return 0;
}