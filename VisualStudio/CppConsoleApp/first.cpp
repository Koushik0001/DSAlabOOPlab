/*6. Write a menu driven program to accept a number in any Number System [from Binary, Decimal,
Octal, and Hex] and convert and display the same in any other amongst these.*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;

float to_decimal(char*, int);
char* decimal_to(float, int);
int extract_num(char);
int intiger_part(float);

int position_of_point;

int main()
{
    int op, i = 0, base, k = 0;
    float decimal;
    char* result1, * result2, * result3, nsystem[100], run;

    do
    {
        printf("Enter in which number system you want enter number:\n\t1)decimal\n\t2)Binary\n\t3)Ocatl\n\t4)Hex\n\t");
        printf("Enter Option No.: ");
        fflush(stdin);
        cin >> op;

        printf("Enter the number: ");
        fflush(stdin);

        switch (op)
        {
        case 2:
            base = 2;
            break;
        case 3:
            base = 8;
            break;
        case 4:
            base = 16;
            break;
        }

        switch (op)
        {
        case 1:
            cin >> decimal;
            break;
        default:
            do
            {
                cin >> nsystem[i];

                if (nsystem[i] == '.')
                {
                    position_of_point = i;
                    k++;
                }

                i++;
            } while (nsystem[i - 1] != '\n');
            if (k == 0)
            {
                position_of_point = i - 1;
                nsystem[i - 1] = '.';
            }
            nsystem[i] = '\0';
            decimal = to_decimal(nsystem, base);
        }

        result1 = decimal_to(decimal, 2);
        printf("Binary : ");
        puts(result1);

        result2 = decimal_to(decimal, 8);
        printf("Oct : ");
        puts(result2);

        printf("Decimal : %f", decimal);

        result3 = decimal_to(decimal, 16);
        printf("\nhex : ");
        puts(result3);

        printf("\n\nDo you want to enter another humber(y/n) : ");
        fflush(stdin);
        run = getchar();

        k = 0; i = 0;
        position_of_point = 0;
    } while (run == 'y');

    return 0;
}

float to_decimal(char *nsystem, int base)
{
    float decimal = 0, l = -1;
    int len = strlen(nsystem);

    for (int i = 0; i < position_of_point; i++)
        decimal += (extract_num(nsystem[i]) * pow(base, position_of_point - i - 1));

    for (int i = position_of_point + 1; i < len - 1; i++)
    {
        decimal += extract_num(nsystem[i]) * pow(base, l);
        l--;
    }
    return(decimal);
}

char* decimal_to(float decimal, int result_base)
{
    static char result[100];
    int intiger = decimal, i = 0;
    float fraction = decimal - intiger, temp;

    while (intiger != 0)
    {
        if (intiger % result_base < 10)
            result[i] = (char)((intiger % result_base) + 48);
        else
            result[i] = (char)((intiger % result_base) - 10 + 65);
        intiger = intiger / result_base;
        i++;
    }
    result[i] = '\0';
    _strrev(result);

    if (fraction != 0)
    {
        result[i] = '.';
        i++;
        temp = decimal - intiger_part(decimal);
        while (temp != 0 && temp > 0.0000000000000000001)
        {
            float t = temp * result_base;
            int x = intiger_part(t);
            if (x < 10)
                result[i] = (char)(x + '0');
            else
                result[i] = (char)(x - 10 + 'A');

            temp = t - x;
            i++;
        }
    }
    result[i] = '\0';
    return result;
}

int extract_num(char c)
{
    int num;
    if (c < 58 && c > 47)
        num = c - '0';
    else
        num = c - 'A' + 10;
    return(num);
}

int intiger_part(float x)
{
    int intiger = x;
    return(intiger);
}