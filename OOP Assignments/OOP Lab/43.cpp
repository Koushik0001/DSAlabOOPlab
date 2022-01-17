/*43. Write class definitions for the following class hierarchy 
Circle ->  Shape2D  <- Rectangle
The Shape2D class represents two dimensional shapes that should have pure virtual functions area(), perimeter() 
etc. Implement these functions in Circle and Rectangle. Also write proper constructor(s) and other functions you 
think appropriate in the Circle and Rectangle class. Now create an array of 5 Shape2D pointers. Create 3 Circle 
and 2 Rectangles objects and place their addresses in that array. Use a loop to print area and perimeter of all 
shapes on this array. */
#include<iostream>
using namespace std;
#define PI 3.14
class shape2D
{
    public:
        virtual float area()=0;
        virtual float perimeter() = 0;
};
class circle: public shape2D
{
    float radius;
    public:
        circle(int r):radius(r){}
        ~circle(){}
        float area(){return PI*radius*radius;}
        float perimeter(){  return 2*PI*radius;}
};
class rectangle: public shape2D
{
    float length, width;
    public:
        rectangle(int l, int w):length(l),width(w){}
        ~rectangle(){}
        float area(){return length*width;}
        float perimeter(){  return 2*(length+width);}
};
int main()
{
    shape2D* shape2Dptr[5];
    circle c1(1), c2(2), c3(3);
    rectangle r1(5,2),r2(3,1);
    shape2Dptr[0] = &c1;
    shape2Dptr[1] = &c2;
    shape2Dptr[2] = &c3;
    shape2Dptr[3] = &r1;
    shape2Dptr[4] = &r2;

    for(int i=0; i<5; i++)
        cout << "Area of shape2D"<<i+1<<" = "<<shape2Dptr[i]->area()<<endl;
    cout << endl;
    for(int i=0; i<5; i++)
        cout << "Perimeter of shape2D"<<i+1<<" = "<<shape2Dptr[i]->perimeter()<<endl;
    return 0;
}