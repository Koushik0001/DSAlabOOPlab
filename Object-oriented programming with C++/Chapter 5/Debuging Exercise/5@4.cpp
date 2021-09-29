#include<iostream>
using namespace std;

class age
{
    private :
        int child_age;
    public :
        age(): child_age(20){}//age() is a constructor. what is : child_age(){}??
        int father_age(age);
};
int age :: father_age(age d)
{
    d.child_age += 15;
    return d.child_age;
}

int main()
{
    age D;
    cout << "father's age : " << D.father_age(D); 
    return 0;
}