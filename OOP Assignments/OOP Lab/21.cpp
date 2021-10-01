/*21. Write a class Vector for one dimensional array. Write suitable constructor/copy constructor. Also add member 
functions for performing basic operations (such as addition, subtraction, equality, less, greater etc.). Create vectors 
and check if those operations are working correctly. */
#include<iostream>
using namespace std;

class vector
{
        int *arr, n;
    public:
        vector(int c)
        {
            n = c;
            arr = new int[c];
        }
        vector(vector & p)
        {
            n = p.n;
            arr = new int[n];
            for(int i=0; i<n; i++)
                arr[i] = p.arr[i];
        }
        void get_data();
        int max();
        int least();
        int sum();
        void display();
        void del(){ delete []arr;}
};
void vector::get_data()
{
    for(int i=0; i<n; i++)
        cin >> arr[i];
}
int vector::max()
{
    int t=arr[0];
    for(int i=0; i<n; i++)
    {
        if(t<arr[i])
        {
            t=arr[i];
            continue;
        }
    }
    return t;
}
int vector::least()
{
    int t=arr[0];
    for(int i=0; i<n; i++)
    {
        if(t>arr[i])
        {
            t=arr[i];
            continue;
        }
    }
    return t;
}
int vector::sum()
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    return sum;
}
void vector::display()
{
    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
}
int main()
{
    cout << "Enter the number of elements of the array : ";
    int n;
    cin >> n;
    vector a(n);
    cout << "\nEnter the elements : ";
    a.get_data();
    cout << "\nthe elements of a are : ";
    a.display();
    vector b(a);
    a.del();
    cout << "\nThe elements of b are : ";
    b.display();
    cout << "\nsum of the elements of vector a is " << a.sum() << endl; 
    cout << "biggest element of vector a is " << a.max() << endl;
    cout << "smallest element of vector a is " << a.least() << endl;
    return 0;
}