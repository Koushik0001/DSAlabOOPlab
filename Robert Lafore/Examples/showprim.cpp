//displays prime number distribution
#include<iostream>
#include<conio.h> //for getche()
using namespace std;


int main()
{
    const unsigned char WHITE = 219; //solid color (primes)
    const unsigned GRAY = 176;       //gray (non primes)
    unsigned char ch;
                                    //for each screen position
    for(int count=0; count<80*25-1; count++)
    {
        ch = WHITE;                  //assume it's prime
        for(int j=2; j<count; j++)
        {
            if(count%j == 0)
            {
                ch = GRAY;
                break;
            }
        }
        cout << ch;
    }
    getche();
    return 0;
}