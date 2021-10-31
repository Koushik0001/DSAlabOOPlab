/*30. Write a class “Point” which stores coordinates in (x, y) form. Define necessary constructor, destructor and other 
reader/writer functions. Now overload ‘-’ operator to calculate the distance between two points. */
#include<iostream>
#include<math.h>
using namespace std;
class point
{
    float x, y;
    public :
        point(float a=0, float b=0)
        {
            x = a;
            y = b;
        }
        ~point(){};
        void setdata();
        void display(){ cout << "( " << x << ", " << y << " )"; }
        friend float operator-(point, point);
};

int main()
{
    point a;
    point b;
    b.setdata();
    cout << "a-b = " << a-b;
    return 0;
}
void point::setdata()
{
    cout << "Enter the values of X and Y : ";
    cin >> x >> y;
}
float operator-(point a, point b)
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}