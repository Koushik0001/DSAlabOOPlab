/*48. Vehicles may be either stopped of running in a lane. If two vehicles are running in opposite direction in a single 
lane there is a chance of collision. Write a C++ program using exception handling to avoid collisions. You are 
free to make necessary assumptions. */
#include<iostream>
using namespace std;
class vehicle
{
    int vehicle_no,lane_no;
    int vehicle_status;//running = 1 , stopped = 0;
    int direction;//up =1, down = 0, unknown = -1
    public:
        vehicle(int no, int lane,int rors,int d=0):vehicle_no(no),lane_no(lane),vehicle_status(rors),direction(d)
        {
            if(vehicle_status == 0)
                direction = -1;
        }
        friend void process_safety(vehicle a, vehicle b)
        {
            if(a.vehicle_no != b.vehicle_no)
            {
                if(a.vehicle_status == 1 && b.vehicle_status ==1)
                {
                    if(a.lane_no==b.lane_no)
                    {
                        if(a.direction != b.direction)
                            throw 1;
                    }
                }
            }
        }
};
int main()
{
    vehicle v1(01,2,1,0),v2(02,2,1,1);
    try
    {
        process_safety(v1,v2);
    }
    catch(int)
    {
        cout << "collision alert..."<<endl;
    }
    return 0;
}