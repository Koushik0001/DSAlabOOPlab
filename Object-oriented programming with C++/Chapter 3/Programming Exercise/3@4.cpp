#include<iostream>
#include<iomanip>

using namespace std;

float fv(int,float,int);

int main()
{
    int p = 1000, n;
    float r , v;
    cout << setw(7) << "p" << setw(7) << "n" << setw(7) << "r" << setw(10) << "v" << endl;
    while(p<=10000)
    {
        n = 1;
        while(n<=10)
        {
            r = 0.10;
            while (r<=0.20)
            {
                v = fv(p,r,n);
                cout << setw(7) << p << setw(7) << n << setw(7) << r << setw(10) << v << endl;
                r += 0.01;
            }
            n++;
        }
        p += 1000;
    }
    return 0;
}

float fv(int p, float r, int n)
{
    float v = p;
    for(int i=0; i<n; i++)
        v *= (1+r);    
    return(v);
}