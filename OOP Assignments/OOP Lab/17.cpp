/*17. Consider function add() in 13. Specify the default values for second and third parameters to 0 (zero). Now call this 
function with three, two and one arguments and see the result.*/
#include<iostream>
using namespace std;
inline int add(int a, int b =0, int c =0)
{
    return(a+b+c);
} 

int main()
{
    cout << "Called with three arguments, (4,5,6) , output :  " << add(4,5,6) << endl;
    cout << "Called with two arguments, (4,5) , output :  " << add(4,5) << endl;
    cout << "Called with one argument, (4) , output :  " << add(4) << endl;
    return 0;
}