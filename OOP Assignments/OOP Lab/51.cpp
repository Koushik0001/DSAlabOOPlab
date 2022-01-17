/*51. Create a C++ template class for implementation of Stack data structure. Create a Stack of integers and a Stack of 
complex numbers created earlier (code may be reused). Perform some push and pop operations on these stacks. 
Finally print the elements remained in those stacks.*/
#include<iostream>
using namespace std;
class complex;
template<class T>
class Stack 
{ 
        T *buffer;
        int top; 
    public : 
        Stack(int x)
        {
            buffer = new T[x];
            top = 0;
        }             //create a stack with specified size 
        void push(T x)
        {
            buffer[top] = x;
            top++;
        }         //push the specified item 
        T pop()
        {
            if(top == 0)
            {
                cout << "Stack Underflow"<< endl;
                cout << "top = " << top <<endl;
            }
            else
            {
                top--;
                return (buffer[top]);
            }

        }              //return the top element 
        void disp()
        {
            for(int i=0; i<top;i++)
                cout << buffer[i] << " ";
            cout << endl;
        }            //displays elements in the stack in top to bottom order 
};
class complex
{
    float a,b;
    public:
        complex(float x=0, float y=0):a(x),b(y){}
        bool operator >(complex c)
        {
            if((a+b)>(c.a+c.b))
                return true;
            else 
                return false;
        }
        friend ostream &operator <<( ostream &output, const complex &z ) 
        { 
            if(z.b>0)
                output << z.a << " + " << z.b << "i";
            else
                output << z.a << " + " << z.b << "i";
            return output;            
        }
        void operator=(complex x)
        {
            a = x.a;
            b = x.b;
        }
};
int main()
{
    Stack<int> a(10);
    a.push(2);
    a.push(3);
    a.push(4);
    a.disp();
    a.push(5);
    a.disp();
    int v = a.pop();
    cout << "popped result = " << v << endl;
    a.disp();
    Stack<complex> z(10);
    z.push(complex(6,9));
    z.push(complex(3,4));
    z.push(complex(4,5));
    z.disp();
    z.pop();
    z.push(complex(6,5));
    z.disp();
    return 0;
}