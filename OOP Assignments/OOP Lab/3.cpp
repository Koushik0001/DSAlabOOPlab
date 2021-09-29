/*3. Create a factorial table using cout as follows: 
1! = 1 
2! = 2 
3! = 6 
… 
6! = 720 */
#include<iostream>
using namespace std;

int main()
{
    int n = 1;
    for(int i=1; i<=6; i++)
    {
        n = n*i;
        cout << i << "! = " <<  n << endl;
    }
    return 0;
}