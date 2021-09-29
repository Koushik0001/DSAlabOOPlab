/*12. Write a function Strcpy to copy one string to another with suitable formal parameters declarations. Following 
points must be considered. 
a) Source string must not get modified 
b) Target string is allowed to get modified 
c) The Pointers must be constant pointers. 
Use it to copy some strings. */

#include<iostream>
using namespace std;

void strcpy(char * const, char const * const);
int main()
{
    char *target;
    char source[] = "It's the source string.";
    int length = 0;
    while(source[length] != '\0')
        length++;
    target = new char[length];
    cout << source << endl << target << endl << endl;
    strcpy(target,source);
    cout << source << endl << target << endl;  
    delete []target;
    delete []source;
    return 0;
}
void strcpy(char * const t, char const * const s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}