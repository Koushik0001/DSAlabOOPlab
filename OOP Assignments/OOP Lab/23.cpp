/*23. Create a simple class SavingsAccount for savings account used in banks as follows: Each SavingsAccount object 
should have three data members to store the account holder’s name, unique account number and balance of the 
account. Assume account numbers are integers and generated sequentially. Note that once an account number is 
allocated to an account, it does not change during the entire operational period of the account. The bank also 
specifies a rate of interest for all savings accounts created. Write relevant methods (such as withdraw, deposit 
etc.) in the class. The bank restricts that each account must have a minimum balance of Rs. 1000. Now create 
100 SavingsAccount objects specifying balance at random ranging from Rs. 1,000 to 1,00,000. Now, calculate 
the interest for one year to be paid to each account and deposit the interest to the corresponding balance. Also 
find out total amount of interest to be paid to all accounts in one year. */

#include<iostream>
#include<string.h>
using namespace std;
void get_str(char* & x)
{
    int i=0;
    do
    {
        x[i] = getchar();
        i++;
    }while(x[i-1] != '\n');
    x[i-1] = '\0';
}
class data_base;
class savings_account
{
        char *name;
        int accno;
        float bal;
    public :
        savings_account(const char* a="$$$$\0");
        ~savings_account(){/*cout << "inside savings_account destructor..."<<endl;*/}
        void deposite();
        void withdraw();   
        int min_bal();
        friend class data_base;      
};

class data_base
{
    private:
        struct node
        {
            savings_account account;
            struct node *next;
        };
        typedef node* nodePtr;
        nodePtr head;
        nodePtr curr;
        nodePtr temp;
        static int n;
    public:
        data_base()
        {
            head = NULL;
            curr = NULL;
            temp = NULL;
        }
        ~data_base(){}
        void add_account(savings_account);
        void delete_account(int);
        void display();
        void diplay(const char*, int);
        void transaction();
        friend savings_account::savings_account(const char*);
}a;
int data_base::n = 7446;

int main()
{
    for(int i=0; i<5; i++)
    {
        char* str = new char[20]; 
        fflush(stdin);
        cout << "enter the name : ";
        get_str(str);
        a.add_account(savings_account(str));
        delete []str;
    }
    a.display();
    char c = 'n';
    do
    {
        a.transaction();
        a.display();
        cout << "want again : ";
        fflush(stdin);
        c = getchar();
    } while (c == 'y');
    return 0;
}
savings_account::savings_account(const char* nam)
{
    name = new char[20];
    int i=0;
    while(nam[i] != '\0')
    {
        name[i] = nam[i]; 
        i++;
    }
    name[i] = '\0';
    accno = a.n;
    bal = 0.0;
}   

void savings_account::deposite()
{
    cout << "Enter amount to be deposited(in Rs.) : ";
    float temp;
    cin >> temp;
    bal += temp;
}

void savings_account::withdraw()
{
    cout << "Enter amount to be withdrawn(in Rs.) : ";
    float amount;
    cin >> amount;
    if(bal-amount <1000)
        cout << "Balance insufficient..." << endl;
    else
        bal -= amount;
}

void data_base::add_account(savings_account b)
{
    nodePtr ne = new node;
    savings_account a(b.name); 
    ne->account = a; 
    ne->next = NULL;
    n++;
    if(head != NULL)
    {
        curr = head;
        temp = head;
        while (curr != NULL)
        {
            temp = curr;
            curr = curr->next;
        }
        temp->next = ne;      
    }
    else
        head = ne;
    int op;
    again:
        cout << "Deposite minimum Rs. 1000 to create account. \n\t1)Deposite\n\t2)cancel\n\t";
        cin >> op;
        if(op ==1)
        {
            cout << "Enter amount to be deposited : ";
            float temp_bal;
            cin >> temp_bal;
            if(temp_bal < 1000)
                goto again;
            else
            {
                ne->account.bal = temp_bal;
                cout << "Account created successfully..." << endl;
                cout << "Name : " << ne->account.name << endl;
                cout << "Accno no. " << ne->account.accno << endl;
                cout << "Balance : Rs." << ne->account.bal << endl;
            }
        }
        else if(op == 2)
        {
            ::a.delete_account(ne->account.accno);
            cout << "account creation terminated..."<< endl;
        }
        else 
            goto again;
}

void data_base::delete_account(int no)
{
    nodePtr deletePtr = NULL;
    curr = head;
    temp = head;
    while(curr != NULL && curr->account.accno != no)
    {
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL)
    {
        cout << "No account with provided account details exists\n";
        delete deletePtr;
    }
    else
    {
        deletePtr = curr;
        if(deletePtr == head)
        {
            head = head->next;
            curr = NULL;
            temp = NULL;
        }
        else
        {
            curr = curr->next;
            temp->next =curr;
        }
        delete deletePtr;
    }
}

void data_base::transaction()
{
    fflush(stdin);
    cout << "Enter the account number : ";
    int a;
    cin >> a;
    curr = head;
    while(curr != NULL && curr->account.accno != a)
        curr = curr->next;
    if(curr != NULL)
    {
        cout <<"\n\t1)Deposite\n\t2)Withdraw\n\t3)Delete Account"<< endl;
        int op;
        cin >> op;
        switch(op)
        {
            case 1:
                curr->account.deposite();
                break;
            case 2:
                curr->account.withdraw();
                break;
            case 3:
                char c;
                cout << "Are you sure that you want to delete the account...(y/n)";
                cin >> c;
                if(c == 'y')
                {
                    delete_account(a);
                    cout << "Account deleted successfullly..." << endl;
                }
                else if(c == 'n')
                    cout <<"Deletion process terminated..." << endl; ;            
        }
    }
    else
        cout << "account not found..." << endl;
}

void data_base::display()
{
    curr = head;
    while(curr != NULL)
    {
        cout << "Name : " << curr->account.name << endl;
        cout << "Acc No. " << curr->account.accno << endl;
        cout << "Balance : Rs." << curr->account.bal << endl << endl;
        curr = curr->next;
    }
}