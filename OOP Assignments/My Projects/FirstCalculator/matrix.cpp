#include "matrix.h"
#include "iostream"
using namespace std;
void cmatrix::transpose(cmatrix a)
{
    r = a.c;
    c = a.r;

    mat = new float* [r];
    for (int i = 0; i < r; i++)
        mat[i] = new float[c];
    for (int i = 0; i < a.r; i++)
    {
        for (int j = 0; j < a.c; j++)
        {
            mat[j][i] = a.mat[i][j];
        }
    }
}
void cmatrix::multiply(cmatrix a, cmatrix b)
{
    std::cout << "Which product do you want :\n\t1)matrix1 * matrix2\n\t2)matrix2 * matrix1 : ";
    int op;
    std::cin >> op;
    if (op == 2)
    {
        mat = b.mat;
        b.mat = a.mat;
        a.mat = mat;

        int t;
        t = a.r;
        a.r = b.r;
        b.r = t;

        t = a.c;
        a.c = b.c;
        b.c = t;
    }
    if (a.c != b.r)
    {
        std::cout << "MULTIPLICATION NOT VALID";
        exit(1);
    }

    r = a.r;
    c = b.c;

    mat = new float* [r];
    for (int i = 0; i < r; i++)
        mat[i] = new float[c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            float* column = new float[b.r];
            for (int k = 0; k < b.r; k++)
                column[k] = b.mat[k][j];
            mat[i][j] = element(a.mat[i], column, b.r);
        }
    }
}
void cmatrix::add(cmatrix a, cmatrix b)
{
    r = a.r;
    c = a.c;
    mat = new float* [r];
    for (int i = 0; i < r; i++)
        mat[i] = new float[c];
    if (a.r = !b.r || a.c != b.c)
        std::cout << "Addition not defined.";
    else
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                mat[i][j] = a.mat[i][j] + b.mat[i][j];
            }
        }
    }

}
float cmatrix::element(float* array1, float* array2, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + ((array1[i]) * (array2[i]));
    return(sum);
}
void cmatrix::get_data()
{
    std::cout << "Order of the matrix (row column) : ";
    std::cin >> r >> c;
    mat = new float* [r];
    for (int i = 0; i < r; i++)
        mat[i] = new float[c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            std::cin >> mat[i][j];
    }
}
void cmatrix::display()
{
    std::cout << "The resutant matrix is : " << std::endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            std::cout << mat[i][j] << "\t";
        std::cout << '\n';
    }
}
void cmatrix::negative_of_matrix(cmatrix a)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            mat[i][j] = (-1) * mat[i][j];
    }
}
void cmatrix::const_multiplication(cmatrix a, float x)
{
    r = a.r;
    c = a.c;

    mat = new float* [r];
    for (int i = 0; i < r; i++)
        mat[i] = new float[c];

    for (int i = 0; i < a.r; i++)
    {
        for (int j = 0; j < c; j++)
            mat[i][j] = x * a.mat[i][j];
    }
}

void matrix()
{
    cout << "What do you want to perform : " << "\n\t";
    cout << "1)Transpose of a matrix\n\t2)Matrix Multiplicatin\n\t3)Matrix Addition\n\t4)Matrix Subtraction\n\t";
    cout << "5)Multuply with conatant\n\t6)Exit\n\t";
    cout << "Enter option nummber : ";
    int op;
    cin >> op;
    switch (op)
    {
    case 1:
        cmatrix a, result;
        a.get_data();
        result.transpose(a);
        result.display();
        break;
    case 2:
        cmatrix b;
        a.get_data();
        b.get_data();
        result.multiply(a, b);
        result.display();
        break;
    case 3:
        a.get_data();
        b.get_data();
        result.add(a, b);
        result.display();
        break;
    case 4:
        a.get_data();
        b.get_data();
        cout << "\nWhat do you wnat :\n\t1)matrix1 - matrix2\n\t2)matrix2 - matrix1\n\t";
        cout << "Enter Option number : ";
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
            b.negative_of_matrix(b);
            break;
        case 2:
            a.negative_of_matrix(a);
            break;
        }
        result.add(a, b);
        result.display();
        break;
    case 5:
        float x;
        a.get_data();
        cout << "\nEnter the constant : ";
        cin >> x;
        result.const_multiplication(a, x);
        result.display();
        break;
    case 6:
        exit(1);
    }
}
