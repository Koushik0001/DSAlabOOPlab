/*9. Now write another function swap() that takes two strings (character array) and interchanges them without 
reference parameters. Test this function using some arguments. Rewrite the function using reference parameters. 
Again test this function with some arguments.*/
#include<iostream>
using namespace std;

void swapp(char[], char[]);
void swap(char &, char &);
void swap3(char[], char[]);
int main()
{
    char str1[] = "I am koushik. ", str2[] = "I read in JU.";
    cout << str1 << endl << str2 << endl << endl;
    swapp(str1,str2);
    cout << str1 << endl << str2 << endl << endl;
    swap(str1, str2);
    cout << str1 << endl << str2 << endl << endl;
    return 0;
}
void swapp(char s1[], char s2[])
{
    char* p;
    p = s1;
    s1 = s2;
    s2 = p;
}
void swap(char & p1, char & p2)
{
    cout << p1 <<  "**" << endl ;
}