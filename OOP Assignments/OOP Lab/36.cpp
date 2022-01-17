/*36. Design and implement class(es) to support the following code segment. 
Table t(4, 5), t1(4, 5); 
cin >> t; 
t[0][0] = 5; 
int x = t[2][3]; 
t1 = t; 
cout << t << “\n” << t1; */
#include<iostream>
using namespace std;
class Table
{
    int** t;
    int row, column;
    int first_index;
    short int second_index;
    public:
        Table(int r, int c):row(r),column(c)
        {
            t = new int*[row];
            for(int i=0; i<r;i++)
                t[i] = new int[column];
        }
        friend istream &operator>>( istream  &input, Table &T ) 
        { 
            for(int i=0; i<T.row;i++)
            {
                for(int j=0; j<T.column; j++)
                input >>T.t[i][j];
            }
            return input;            
        }
        friend ostream &operator<<( ostream  &output, Table &T ) 
        { 
            for(int i=0; i<T.row;i++)
            {
                for(int j=0; j<T.column; j++)
                output << T.t[i][j] << "  ";
            }
            return output;            
        }
        int* & operator[](int index)
        {
            first_index = index;
            return t[index];
        }
        int & operator[](short int index)
        {
            second_index = index;
            return ((*this)[first_index][second_index]);
        }


};

int main()
{
    Table t(4, 5), t1(4, 5); 
    cin >> t; 
    t[0][0] = 5; 
    int x = t[2][3]; 
    t1 = t; 
    cout << t << "\n" << t1;
    return 0;
}