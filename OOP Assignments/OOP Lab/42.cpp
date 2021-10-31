/*42. Write a class Employee having data member name, salary etc. Write proper constructors, methods to get/set 
them and a virtual method printDetails() that prints all information of a person. Now write two classes Manager 
and Clerk from Employee. Add ‘type’ and ‘allowance’ in the manager and Clerk respectively. Write constructors, 
methods to get/set them and a override printDetails(). Now create a Manager and a Clerk object and call 
printDetails() function on them to display their information. 

Now Create an array of pointers to Employee and store addresses of two Employee, two Managers and two 
Clerks. Call printDetails() on all elements (a loop may be used). Also find the total salary drawn by all 
employees. 
*/
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
void get_str(char* &);

class Employee
{
    protected :
        char* name;
        int salary;
    public :
        Employee(char const *n,int s):salary(s)
        {
            name = new char[strlen(n)];
            strcpy(name,n);
        }
        Employee(){}
        void set_name(char const*);
        void set_sal(int s){salary = s;}
        char* get_name(){return name;}
        int get_salry(){return salary;}
        void virtual printDetails();
        ~Employee(){delete []name;}
};
void Employee::set_name(char const* n)
{
    delete []name;
    name = new char[strlen(n)];
    strcpy(name,n);
}
void Employee::printDetails()
{
    cout << "Name : "<< name << endl;
    cout << "Salary : " << salary <<endl;
}

class Manager:public Employee
{
    private:
        char* type;
    public:
        Manager(char const* n,int s,char const* t):Employee(n,s)
        {
            type = new char[strlen(t)];
            strcpy(type,t);
        }
        Manager(){};
        void set_type(char const*);
        char* get_type(){return type;}
        void printDetails();
        ~Manager(){delete []type;}        
};
void Manager::set_type(char const* t)
{
    delete []type;
    type = new char[strlen(t)];
    strcpy(type,t);
}
void Manager::printDetails()
{
    cout << "Name : " << name << endl;
    cout << "Salary : "<< salary << endl;
    cout << "Type : "<< type << endl;
}

class Clerk : public Employee
{
    private:
        int allowance;
    public:
        Clerk(char const* n,int s,int a):Employee(n,s),allowance(a){}
        Clerk(){}
        void set_al(int al){allowance = al;}
        int get_al(){return allowance;}
        void printDetails();
        ~Clerk(){}
};
void Clerk::printDetails()
{
    cout << "Name : "<< name << endl; 
    cout << "Salary : "<< salary << endl;
    cout << "Allowance : " << allowance << endl;
}

int main()
{
    Manager m("Rabi Roy",90000,"Assistant Product Manager");
    Clerk c("Lisa Jobs",50000,6);
    m.printDetails();
    cout << endl;
    c.printDetails();
    cout << endl;

    Employee ** arrp;
    arrp = new Employee*[6];
    
    Employee e1("Sikha Das",60000), e2("Koushik Saha",30000);
    Manager m1("Koushik Mahanta",150000,"Product Manager"), m2("Jason White",90000,"General Communication");
    Clerk c1("Jonathan Mathew",45000,5), c2("Kelly Black",60000,4);

    arrp[0] = &e1;
    arrp[1] = &e2;
    arrp[2] = &m1;
    arrp[3] = &m2;
    arrp[4] = &c1;
    arrp[5] = &c2;

    for(int i=0; i<6; i++)
    {
        arrp[i] ->printDetails();
        cout << endl;
    }

    int total_sal = 0;
    cout << setw(20) <<"Name" << setw(10) <<"Salary" << endl;
    cout << setw(20) <<"_______" << setw(10) << "_______" << endl;
    for(int i=0; i<6; i++)
    {
        cout << setw(20) << arrp[i]->get_name() << setw(10) <<arrp[i]->get_salry() << endl;
        total_sal += arrp[i]->get_salry();
    }
    cout << setw(30) <<"__________________________________" << endl;
    cout << setw(20)<<"Total = "<< setw(10) <<total_sal << endl;
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