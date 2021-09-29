#include<iostream>
using namespace std;

class account
{
    private :
        string name, acc_no,type;
        int balance;
    public :
        void init();
        void deposite();
        void withdraw();
        void display();      
};

int main()
{
    account A, B;
    A.init();
    cout << endl;
    A.deposite();
    cout << endl;
    A.withdraw();
    cout << endl;
    A.display();
    cout << endl << endl;
    return 0;
}

void account :: init()
{
    cout << "Enter the Account Holder's Name : ";
    cin >> name;
    cout << "Enter Acc. No. : ";
    cin >> acc_no;
    cout << "Enter Type of Account : ";
    cin >> type;
    cout << "Enter Balance : ";
    cin >> balance;
}

void account :: deposite()
{
    int x;
    cout << "Enter deposite amount : ";
    cin >> x;
    balance += x;
}

void account :: withdraw()
{
    cout << "Current Balance : " << balance << endl;
    cout << "Enter the Amount to be Withdrawn (<current balance): ";
    int x;
    cin >> x; 
    while(x > balance)
    {
        cout << "Balance not sufficient." << endl;
        cout << "\t1)Enter Another Amount" << endl << "\t2)Exit";
        int op;
        cin >> op;
        if(op == 1)
        {
            cout << "Enter : ";
            cin >> x;
        }
        else
        {
            x = 0;
            break;
        }
    }
    
    balance -= x;
}

void account :: display()
{
    cout << "Name : " << name << endl;
    cout << "Balance : " << balance << endl;
}