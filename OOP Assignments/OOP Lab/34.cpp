/*34. Design and implement class(es) to support the following main program. 
int main() { 
 IntArray i(10); 
 for(int k = 0; k < 10; k++) 
 i[k] = k; 
 cout << i; 
 return 0; 
} */
#include<iostream>
using namespace std;
class IntArray
{
    int* x, num;
    public:
        IntArray(int a):num(a){x = new int[num];}
        ~IntArray(){}
        friend ostream &operator <<( ostream &output, const IntArray &I ) 
        { 
            for(int i=0;i<I.num;i++)
                output << I.x[i] << "  ";
            return output;            
        }
        int & operator[](int index) 
        {
            return x[index];
        }

};

int main() 
{ 
    IntArray i(10); 
    for(int k = 0; k < 10; k++) 
    i[k] = k; 
    cout << i; 
    return 0; 
} 