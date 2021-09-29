/*19. Write a class for the geometrical shape rectangle. Write suitable constructors and member functions. Add a 
member function area() that calculates the area of a rectangle. Create 4 rectangles and print their respective area.*/
#include<iostream>
using namespace std;
class rectangle
{
        float length, width;
    public:
        rectangle(float l=1,float w=1){length = l; width = w;}
        ~rectangle(){};
        float area();        
};
float rectangle::area()
{
    return length*width;
}
int main()
{
    rectangle r1(10,5),r2(10),r3,r4(6,5);
    cout << " area of r1 = " << r1.area() <<endl; 
    cout << " area of r2 = " << r2.area() << endl;
    cout << " area of r3 = " << r3.area() << endl;
    cout << " area of r4 = " << r4.area() << endl;
    return 0;
}