/*44.Implement the Shape hierarchy as shown in the figure. Each TwoDShape should contain function getArea to 
calculate the area of two-dimensional shape. Each ThreeDShape should have member functions getArea and 
getVolume to calculate the surface area and volume of the three-dimensional shape respectively. Create a 
program that uses Vector of Shape pointers to objects of each concrete class in the hierarchy. Now write a 
program that processes all the shapes in the Vector such that if the shape is a TwoDShape it prints name of shape 
and its area while it prints name of shape, its area and volume if the shape is a ThreeDShape.*/

/////////////A concrete class is an ordinary class which has no purely virtual functions and hence can be instantiated.
#include<iostream>
#include<math.h>
#define PI 3.14
using namespace std;
class shape
{
    public:
        virtual void display()=0
};
class TwoDshape : public shape
{
    public:
        virtual void name()=0;
        virtual float area()=0;
        virtual display()=0;
};
class ThreeDshape : public shape
{
    public:
        virtual void name()=0;
        virtual float area()=0;
        virtual float volume()=0;
        virtual display()=0;
};
class circle: public TwoDshape
{
    float radius;
    public:
        circle(int r):radius(r){}
        ~circle(){}
        void name(){ cout << "Shape : Circle" << endl;}
        float area(){return PI*radius*radius;}
        void display(){cout << name() << "Area = "<< area() << endl;}
};
class triangle: public TwoDshape
{
    float a,b,c;
    public:
        triangle(float x, float y, float z):a(x),b(y),c(z){}
        void name(){ cout << "Shape : Triangle" << endl;}
        float area()
        {
            float s = (a+b+c)/2;
            return pow((s*(s-a)*(s-b)*(s-c)),0.5);
        }
        void display(){cout << name() << "Area = "<< area() << endl;}
};
class ellipse: public TwoDshape
{
    float semi_major_axis,semi_minor_axis;
    public:
        ellipse(float major, float minor):semi_major_axis(major),semi_minor_axis(minor){}
        ~ellipse(){}
        void name(){ cout << "Shape : Ellipse" << endl;}
        float area(){return PI*semi_major_axis*semi_minor_axis;}
        void display(){cout << name() << "Area = "<< area() << endl;}
};
class sphere : public ThreeDshape
{
    float radius;
    public :
        sphere(float r):radius(r){}
        ~sphere(){}
        void name(){cout << "Shape : Sphere" << endl;}
        float area(){return 4*PI*radius*radius;}
        float volume(){return 4.0*PI*radius*radius*radius/3.0;}
        void display(){cout << name() << "Area = "<< area() << endl<< "Volume = " << volume();}
};
class cube : public ThreeDshape
{
    float edge;
    public :
        cube(float e):edge(e){}
        ~cube(){}
        void name(){cout << "Shape : Cube" << endl;}
        float area(){return 6*edge*edge;}
        float volume(){return edge*edge*edge;}
        void display(){cout << name() << "Area = "<< area() << endl<< "Volume = " << volume();}
};

int main()
{
    shape* shapeptr[5];
    circle c(2);
    triangle t(3,4,5);
    ellipse e(2,3);
    cube cu(1);
    sphere s(2);
    shapeptr[0] = &c;
    shapeptr[1] = &t;
    shapeptr[2] = &e;
    shapeptr[3] = &cu;
    shapeptr[4] = &s;
    for(int i=0; i<5; i++)
        shapeptr[i]->display();
    return 0;
} 