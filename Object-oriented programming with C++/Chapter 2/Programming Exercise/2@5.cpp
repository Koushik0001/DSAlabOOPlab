#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    float f, c;
	cout << setw(20) << "celcius" << setw(20) << "farenhite" << endl;
	for(c=0; c<300; c+=10)
	{
		f = (9.0 * c/5.0) + 32;
		cout << setw(20) << c << setw(20) << f << endl;
	}
	cout << setw(20) << "celcius" << setw(20) << "farenhite" << endl;
	for(f=32; f<300; f+=10)
	{
		c = (f-32) *(5.0/9.0);
		cout << setw(20) << c << setw(20) << f << endl;
	}
	
    cout << "The temprature in celsius is : " << c;
    return 0;
}
