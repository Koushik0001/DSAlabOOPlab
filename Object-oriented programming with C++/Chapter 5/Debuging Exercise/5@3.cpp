#include<iostream>
using namespace std;

class weight 
{
        int leter , ML;
    public :
        void getdata();
        void putdata();
        void sum_of_weight(weight, weight);
};

void weight :: getdata()
{
    cout << "on leter : ";
    cin >> leter;
    cout << "in ML : ";
    cin >> ML;
}
void weight :: putdata()
{
    cout << leter << " Leter and  " << ML << " ML ";
}
void weight ::  sum_of_weight(weight w1, weight w2)
{
    ML = w1.ML + w2. ML;
    leter = ML /1000;
    ML = ML%1000;
    leter += w1.leter + w2.leter;
}
int main()
{
    weight w1, w2, w3;
    cout << "Enter weight in Leter and ML\n";
    cout << "Enter weight 1 ";
    w1.getdata();
    cout <<"Enter weight 2 ";
    w2.getdata();
    w3.sum_of_weight(w1,w2);
    cout << "Total Weight = ";
    w3.putdata();
    return 0;
}