/*20. Write a class that represents a class of wireless device. A device has a location (point object may be used), a 
fixed unique id, and a fixed circular transmission range. Write suitable constructors and member functions for 
this class. Instantiates 10 such devices. Choose location (coordinates) and transmission range of the devices 
randomly. Now, for each of these devices, find the neighbor devices (i.e. devices that belong to the transmission 
range). Suppose, all of these devices have moved to a new location (randomly chosen). Find out the new set of 
neighbors for each of these devices. */
#include<iostream>
#include "math.h"

using namespace std;
void fstrcpy(char * const , char const * const );
class point
{
        float x, y;
    public :
        point(float a=0, float b=0){x=a; y=b;}
        float distance(point &);
        ~point(){}
};
class device
{
        point p;
        char *id;
        float rad;
    public:
        device(const char a[3] = "000", float r = 0.00)/*I put const keyword to remove 
                                                        the warning: ISO C++ forbids converting a string constant 
                                                        to 'char*' [-Wwrite-strings]*/
        {
            p = point(0,0);
            id = new char[3];
            fstrcpy(id,a);
            rad = r;
        }
        void data(point temp,const char a[3], float r)
        { 
            p = temp; 
            fstrcpy(id,a);
            rad = r;
        }
        void loc(const point & temp){p = temp;}/*if i don't use const here and call the funtion using temporary 
                                                object (such as point(1,1)) it will through an error saying that
                                                cannot bind non-const lvalue reference of type 'point&' to an 
                                                rvalue of type 'point'. I can just remove both const and & 
                                                (as void data() function )or I need to do it like this here...*/
        ~device(){}
        void neighbors(device *);
};

int main()
{
    device d[10];
    d[0].data(point(0,0),"A0",2);
    d[1].data(point(-1,1),"A1",3);
    d[2].data(point(1,-1),"A2",4);
    d[3].data(point(-10,1),"A3",5);
    d[4].data(point(1,-10),"A4",6);
    d[5].data(point(-5,1),"A5",7);
    d[6].data(point(4,1),"A6",8);
    d[7].data(point(1,-8),"A7",9);
    d[8].data(point(2,1),"A8",10);
    d[9].data(point(5,1),"A9",11);
    for(int i=0; i<10; i++)
    {
        cout << "neighbours of device of device A" << i <<" is : ";
        d[i].neighbors(d);
    }
    cout << "\nMoved to new locations....\n\n";  
    d[0].loc(point(1,0));
    d[1].loc(point(0,1));
    d[2].loc(point(10,1));
    d[3].loc(point(7,1));
    d[4].loc(point(1,5));
    d[5].loc(point(6,1));
    d[6].loc(point(4,4));
    d[7].loc(point(3,1));
    d[8].loc(point(1,9));
    d[9].loc(point(2,1));
    for(int i=0; i<10; i++)
    {
        cout << "new neighbours of device of device A" << i <<" is : ";
        d[i].neighbors(d);
    }
    return 0;
}

void fstrcpy(char * const t, char const * const s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}
float point::distance(point & b)
{
    return pow(pow(x-b.x,2)+pow(y-b.y,2),0.5);
}
void device::neighbors(device*d)
{
    for(int i=0; i<10; i++)
    {
        if(d[i].id != id)
        {
            if(p.distance(d[i].p) <= rad)
                cout << d[i].id << ' ';
        }
    }
    cout << endl;
}