#include"iostream"
using namespace std;
class cube
{
    private :
        int length;
        int breadth = 8;
        static int width = 5;
    public :
        cube():length(5),breadth(5){}
        cube(int l, int b): length(l), breadth(b){}
        int area_of_cube(){return length*breadth;}
        int volume_of_cube(){return length*breadth*width;}
        void display()
        {
            cout << "length = " << length << '\t';
            cout << "breadth = " << breadth << '\t';
            cout << "width = " << width << '\n';
        }
};

int main()
{
    cube A1, B1(4,5);
    A1.display();
    B1.display();
    return 0;
}