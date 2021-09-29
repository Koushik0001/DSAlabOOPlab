/*18. Write a simple class that represents a class of geometrical points each of which has three coordinates. The class 
should have appropriate constructor(s). Also add a m:!ember function distance() that calculates Euclidian 
distance between two points. Now create two points, find the distance between them and print it. */
#include<iostream>
#include"math.h"
using namespace std;
class point
{
        float x, y, z;
    public :
        point(float a=0, float b=0, float c=0){ x=a; y=b; z=c;}
        float distance(point &);
        ~point(){};
};
float point::distance(point & b)
{
    return pow(pow(x-b.x,2)+pow(y-b.y,2)+pow(z-b.z,2),0.5);
}

int main()
{
    point a, b(1,1,1);
    cout << "distance = " << a.distance(b) << endl;
    return 0;
}