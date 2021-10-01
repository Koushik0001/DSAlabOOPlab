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
        point(float a=0, float b=0){cout << "*******inside constructor"<<endl;x=a; y=b;}
        void pdata(float a, float b){x=a; y=b;}
        float distance(point &);
        ~point(){cout << "inside destructor..."<<endl;};
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
        void data(point & temp, char a[3], float r)
        { 
            p = temp; 
            id = new char[3];
            fstrcpy(id,a);
            rad = r;
        }
        void loc(point & temp){p = temp;}
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
    point p;
    p.pdata(1,1);
    d[0].data(p,"A0",2);//or could have supplied the point as : d[i].data(point(1,1),"A0",2), then you had to declaire the data() as data(point temp,char a[3],float r). this would then initialised several more point objects.
    p.pdata(0,3);
    d[1].data(p,"A1",3);
    p.pdata(2,16);
    d[2].data(p,"A2",4);
    p.pdata(5,10);
    d[3].data(p,"A3",5);
    p.pdata(3,5);
    d[4].data(p,"A4",6);
    p.pdata(6,9);
    d[5].data(p,"A5",7);
    p.pdata(9,21);
    d[6].data(p,"A6",8);
    p.pdata(8,14);
    d[7].data(p,"A7",9);
    p.pdata(3,0);
    d[8].data(p,"A8",10);
    p.pdata(2,15);
    d[9].data(p,"A9",11);
    for(int i=0; i<10; i++)
    {
        cout << "neighbours of device of device A" << i <<" is : ";
        d[i].neighbors(d);
    }
    cout << "\nMoved to new locations....\n\n";
    p.pdata(0,0);
    d[0].loc(p);
    p.pdata(1,3);
    d[1].loc(p);
    p.pdata(2,8);
    d[2].loc(p);
    p.pdata(4,1);
    d[3].loc(p);
    p.pdata(0,4);
    d[4].loc(p);
    p.pdata(3,9);
    d[5].loc(p);
    p.pdata(2,5);
    d[6].loc(p);
    p.pdata(6,5);
    d[7].loc(p);
    p.pdata(5,5);
    d[8].loc(p);
    p.pdata(7,-8);
    d[9].loc(p);
    for(int i=0; i<10; i++)
    {
        cout << "new neighbours of device of device A" << i <<" is : ";
        d[i].neighbors(d);
    }
    return 0;
}