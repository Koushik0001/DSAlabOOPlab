/*20. Write a class that represents a class of wireless device. A device has a location (point object may be used), a 
fixed unique id, and a fixed circular transmission range. Write suitable constructors and member functions for 
this class. Instantiates 10 such devices. Choose location (coordinates) and transmission range of the devices 
randomly. Now, for each of these devices, find the neighbor devices (i.e. devices that belong to the transmission 
range). Suppose, all of these devices have moved to a new location (randomly chosen). Find out the new set of 
neighbors for each of these devices. */
#include<iostream>
#include "math.h"

using namespace std;
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

class point
{
        float x, y;
    public :
        point(float a=0, float b=0){x=a; y=b;}
        float distance(point &);
        ~point(){};
};
float point::distance(point & b)
{
    return pow(pow(x-b.x,2)+pow(y-b.y,2),0.5);
}

class device
{
        point p;
        char *id;
        float rad;
    public:
        device(char a[3] = "000", float r = 0.00)
        { 
            id = new char[3];
            fstrcpy(id,a);
            rad = r;
        }
        void data(point temp, char a[3], float r)
        { 
            p = temp; 
            id = new char[3];
            fstrcpy(id,a);
            rad = r;
        }
        ~device(){}
        void neighbors(device *);
};
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
int main()
{
    device d[10];
    d[0].data(point(1,5),"A0",2);
    d[1].data(point(0,3),"A1",3);
    d[2].data(point(2,16),"A2",4);
    d[3].data(point(5,10),"A3",5);
    d[4].data(point(3,5),"A4",6);
    d[5].data(point(6,9),"A5",7);
    d[6].data(point(9,21),"A6",8);
    d[7].data(point(8,14),"A7",9);
    d[8].data(point(3,0),"A8",10);
    d[9].data(point(2,15),"A9",11);
    for(int i=0; i<10; i++)
    {
        cout << "neighbours of device of device A" << i <<" is : ";
        d[i].neighbors(d);
    }
    return 0;
}