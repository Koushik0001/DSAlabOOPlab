#include<iostream>
#include<stdlib.h>

using namespace std;
int siz(int *);
int main()
{
    int num[] = {1,2,3,4,5,6};
    siz(num);
    num[1] == num[1] ? cout << "success" : cout << "Error";
}
int siz(int * x)
{
    cout << sizeof(x)/sizeof(int);
}