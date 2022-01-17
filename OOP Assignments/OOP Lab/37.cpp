/*37. Design and implement class(es) to support the following code segment. 
Index in(4), out(10); 
int x = in; 
int y = in + out; 
in = 2; 
Integer i; 
i = in; 
*/
#include<iostream>
using namespace std;
class Index
{
    int x;
    public:
        int getx(){return x;}
        Index(int a):x(a){}
        Index operator+(Index i){return (i.x+x);}
        operator int(){return x;}
        void operator=(int a){x = a;}
        friend ostream &operator<<( ostream  &output, Index &I ) 
        { 
            output << I.x;
            return output;            
        }
};
class Integer
{
    int y;
    public:
        Integer(){}
        Integer(int a):y(a){}
        void operator=(Index a){y = a.getx();}
        friend ostream &operator<<( ostream  &output, Integer &I ) 
        { 
            output << I.y;
            return output;            
        }
};
int main()
{
    Index in(4), out(10); 
    int x = in; 
    int y = in + out; 
    cout << "y = "<< y << endl;
    in = 2; 
    cout << "in = "<< in << endl;
    Integer i; 
    i = in;
    cout << "i = "<< i << endl;
    return 0;
}