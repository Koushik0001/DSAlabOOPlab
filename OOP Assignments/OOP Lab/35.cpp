/*35. You are given a main program: 
int main() { 
 Integer a = 4, b = a, c; 
 c = a+b++; 
 int i = a; 
 cout << a << b << c; 
 return 0; 
} */
#include<iostream>
using namespace std;
class Integer
{
    int num;
    public:
        Integer(){}
        Integer(int a):num(a){}
        ~Integer(){}
        friend ostream &operator <<( ostream &output, const Integer &I ) 
        { 
            output << I.num << endl;
            return output;            
        }
        Integer operator++(int) {return num++;}
        int operator+(Integer a){return (a.num+num);}
        operator int(){return num;}
};

int main() { 
 Integer a = 4, b = a, c; 
 c = a+b++; 
 int i = a; 
 cout << a << b << c; 
 return 0; 
}