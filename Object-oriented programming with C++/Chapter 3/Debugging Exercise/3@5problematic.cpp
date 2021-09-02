#include<iostream>
#include<malloc.h>

using namespace std;
char *allocateMemory();
int main()
{
    char *str;
    str = allocateMemory();
    cout << str;
    delete str;
    str = {"  "};
    cout << str; 
    return 0;
}

char *allocateMemory()
{
    char *str;
    str = {"allocate"};
    return str;
}