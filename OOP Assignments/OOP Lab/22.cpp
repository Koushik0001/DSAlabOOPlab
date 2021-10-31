/*22. Write a class IntArray for one dimensional integer array. Implement the necessary constructor, copy constructor, 
and destructor (if necessary) in this class. Implement other member functions to perform operations, such adding 
two arrays, reversing an array, sorting an array etc. Create an IntArray object having elements 1, 2 and 3 in it. 
Print its elements. Now, create another IntArray object which is an exact copy of the previous object. Print its 
elements. Now, reverse the elements of the last object. Finally print elements of both the objects. */
#include<iostream>
using namespace std;
class intArray
{
    int *arr, n;
    public :
        intArray(int x = 0)
        {
            n=x;
            arr = new int[n];
        };
        intArray(intArray &);
        ~intArray(){delete []arr;};
        void getdata();
        void add(intArray &);
        void reverse();
        void sort();
        void display();
};

int main()
{
    intArray a;
    a.getdata();
    a.display();
    intArray b(a);
    b.display();
    b.reverse();
    b.display();
    return 0;
}
intArray::intArray(intArray & a)
{
    n = a.n;
    arr = new int[n];
    for(int i=0; i<n; i++)
        arr[i] = a.arr[i];
}
void intArray::getdata()
{
    cout << "Enter the number of elements : ";
    cin >> n;
    delete []arr;
    arr = new int[n];
    cout << "Enter the elements : ";
    fflush(stdin);
    for(int i=0; i<n; i++)
        cin >> arr[i];
}
void intArray::add(intArray & b)
{
    intArray result(n+b.n);
    int i;
    for(i=0; i<n; i++)
        result.arr[i] = arr[i];
    i = n;
    for(int j=0; j<b.n; j++)
    {
        result.arr[i] = b.arr[j];
        i++;
    }
    delete []arr;
    n = n+b.n;
    for(i=0; i<n; i++)
        arr[i] = result.arr[i];
}
void intArray::reverse()
{
    for(int i=0; i<n/2; i++)
    {
        int j = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] =  j;
    }
}
void intArray::sort()
{
    for(int i=0; i<n; i++)
    {
        int key = arr[i], j = i-1;
        while(arr[j]>key && j>=0)
        {
            arr[i] = arr[j];
            arr[j] = key;
            j--;
        }
    }
}

void intArray::display()
{
    cout << "The array is : ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}