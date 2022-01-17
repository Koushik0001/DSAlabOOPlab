/*50. Write a template function swap() that is capable of interchanging the values of two variables. Used this function 
to swap (i) two integers, (ii) two complex numbers (previous code may be reused). Now write a specialized 
template function for the class Stack (previous code may be reused). Also swap two stacks using this template 
function. */
#include<iostream>
using namespace std;
class Stack 
{ 
        int *buffer, top,size; 
    public : 
        Stack(int s):size(s)
        {
            buffer = new int[size];
            top = 0;
        }             //create a stack with specified size 
        void push(int);         //push the specified item 
        int pop();              //return the top element 
        void disp();            //displays elements in the stack in top to bottom order 
        void operator=(Stack x)
        {
            if(top !=0)
            for(int i=0; i<size; i++)
                pop();
            Stack s(x.size);
            for(int i=0; i<x.size; i++)
                s.push(x.pop());
            for(int i=0; i<x.size; i++)
                push(s.pop());
        }
};
void Stack::push(int x)
{
    buffer[top] = x;
    top++;
}
int Stack::pop()
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

}
void Stack::disp()
{
    for(int i=0; i<top;i++)
        cout << buffer[i] << " ";
    cout << endl;
}
template<class T>
void swapf(T & a, T & b)
{
    T temp = a;
    a = b;
    b = temp; 
}
template<>
void swapf(Stack & a,Stack & b)
{
    Stack temp(10);
    temp = a;
    a = b;
    b = temp;
}
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
                output << z.a << " + " << z.b<<"i";
            else
                output << z.a << " + " << z.b<<"i";
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
    int a = 10, b=20;
    cout << " a = "<< a << " b = " << b << endl;
    swapf<int>(a,b);
    cout << " a = "<< a << " b = " << b << endl;
    complex z1(2.3,1.5), z2(1.9,6.2);
    cout << " z1 = "<< z1 << "     z2 = " << z2 << endl;
    swapf<complex>(z1,z2);
    cout << " z1 = "<< z1 << "     z2 = " << z2 << endl;
    Stack s1(10),s2(10);
    for(int i=0; i<10; i++)
        s1.push(i);
    for(int i=10; i<20; i++)
        s2.push(i);
    s1.disp();
    s2.disp();
    swapf(s1,s2);
    s1.disp();
    s2.disp();
    return 0;
}