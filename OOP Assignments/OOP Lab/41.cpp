/*41. Write a class Person having data member name, age, height etc. Write proper constructors, methods to get/set 
them and a method printDetails() that prints all information of a person. Now write another class Student from 
Person and add data members roll, year of admission etc. Write constructors, methods to get/set them and a 
override printDetails(). Now create a Person and a Student object and call printDetails() function on them to 
display their information. 

Now Create an array of pointers to Person and store addresses of two Persons and two Students. Call 
printDetails() on all elements (a loop may be used). Are you getting output which is supposed to come? Make 
printDetails() function virtual in the base class and check the result. */

#include<iostream>
#include<string.h>
using namespace std;
void get_str(char* &);
class person
{
    protected :
        char *name;
        int height, age;
    public :
        person(char const *str, int h, int a);
        person(){};
        void set_name(char const*);
        void set_height(int);
        void set_age(int);
        char* get_name(){return name;}
        int get_age(){return age;}
        int get_height(){return height;}
        void virtual printDetails();
        ~person(){ delete []name;}
};
person::person(char const *str, int h, int a) : height(h),age(a)
{
    int l = strlen(str);
    name = new char[l];
    strcpy(name, str);
}
void person::set_name(char const *n)
{
    delete []name;
    name = new char[strlen(n)];
    strcpy(name,n);
}
void person:: set_height(int h){height = h;}
void person::set_age(int a){age = a;}
void person::printDetails()
{
    cout << "Name : " << name << endl;
    cout << "Age : "<< age << endl;
    cout << "Height : "<< height << endl;
}

class student : public person
{
    private:
        int roll, AdmYear;
    public :
        student(char const *n, int h, int a, int r, int ay):person(n,h,a)
        {
            roll = r;
            AdmYear = ay;
        }
        student(){};
        void set_roll(int);
        void set_AdmYear(int);
        int get_roll(){return roll;}
        int get_Admyear(){return AdmYear;}
        void printDetails();
        ~student(){};
};
void student::set_roll(int r){roll = r;}
void student::set_AdmYear(int ay){ AdmYear = ay;}
void student::printDetails()
{
    cout << "Name : " << name << endl;
    cout << "Age : "<< age << endl;
    cout << "Height : "<< height << endl;
    cout << "Roll : "<< roll << endl;
    cout << "Admission Year : "<< AdmYear << endl;
}

int main()
{
    person p("Sumit",5,19);
    student s("Koushik",6,19,106,2021);
    p.printDetails();
    cout << endl;
    s.printDetails();
    cout << endl;

    person ** arrp;
    arrp = new person*[4];
    person p1("Sayantak",5,19),p2("Sarbartha",5,19);
    student s1("Sayan",5,19,444,2021),s2("Arnab",5,19,777,2021);

    arrp[0] = &p1;
    arrp[1] = &p2;
    arrp[2] = &s1;
    arrp[3] = &s2;
    
    for(int i=0; i<4; i++)
    {
        arrp[i]->printDetails();
        cout << endl;
    }
    return 0;
}

void get_str(char* & str)
{
    char* a = new char[20];
    int i=0;
    fflush(stdin);
    do
    {
        scanf("%c",&a[i]);
        i++;
    } while (a[i-1] != '\n');
    a[i] = '\0';
    str = new char[strlen(a)];
    strcpy(str,a);
}