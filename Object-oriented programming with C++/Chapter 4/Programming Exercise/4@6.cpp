#include<iostream>
using namespace std;
inline int max(int,int,int);
int main()
{
    int x,y,z;
    cout << "Enter the three numbers : ";
    cin >> x >> y >> z;
    cout << "max = " << max(x,y,z);;
    return 0;
}
int max(int a, int b, int c)
{
    int t = a;
    if(t<b)
        t=b;
    if(t<c)
        t=c;
    return(t);
}