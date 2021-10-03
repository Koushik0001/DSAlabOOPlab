#include<iostream>
using namespace std;
void get_str(char* & x)
{
    int i=0;
    do
    {
        x[i] = getchar();
        i++;
    }while(x[i-1] != '\n');
    x[i] = '\0';
}

int main()
{
    cout <<"Enter : ";
    char* str = new char[15];
    get_str(str);
    cout << str;
    return 0;
}