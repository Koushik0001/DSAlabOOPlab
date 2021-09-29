#include<iostream>
using namespace std;

class addition
{
        int p, q, r, s;
    public :
        void input(void)
        {
            cout << "Enter the three numbers \n";
            cin >> p >> q >> r;
        }
        int add(void)
        {
            s = p+q+r;
            return (s);
        }
        void show(void)
        {
            cout << "The addition of three numbers is :" << add() << endl;
        }
};
int main()
{
    addition x;
    x.input();
    x.show();
    return 0;
}