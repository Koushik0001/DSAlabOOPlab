#include<iostream>
using namespace std;
#define max(x,y,z)  t=x;\
                    if(t < y)\
                        t = y;\
                    if(t < z)\
                        t = z;\
using namespace std;

int main()
{
    int t,x,y,z;
    cout << "Enter the three numbers : ";
    cin >> x >> y >> z;
    max(x,y,z);
    cout << "max = " << t;
    return 0;
}