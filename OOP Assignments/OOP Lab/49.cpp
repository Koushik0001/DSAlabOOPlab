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
template<>
char* fmax (char* str1, char* str2)
{
    int stri1=0,stri2=0;
    char ch = str1[stri1] ;
    while(ch != '\0')
    {
        ch = str1[stri1];
        stri1++;
    }
    ch = str2[stri2] ;
    while(ch != '\0')
    {
        ch = str2[stri2];
        stri2++;
    }
    if(stri1 > stri2)
        return str1;
    else
        return str2;
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

    char const *str1,* str2, *str3;
    str1 = new char[50];
    str2 = new char[50];
    str3 = new char[50];
    str1 = "I study in ju";
    str2 = "I study in IT Dept.";
    str3 = fmax(str1,str2);
    cout <<endl<< str3;
}

