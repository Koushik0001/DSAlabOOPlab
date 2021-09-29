#include "common.h"

float facto(int num)
{
    float factorial = 1;
    for (float i = 1; i <= num; i++)
        factorial = i * factorial;
    return (factorial);
}
float fpower(float base, float power)
{
    base -= 1;
    float ansx1 = 1 + power * base, ansx0 = 0;
    int i = 2;
    while (1)
    {
        ansx1 = ansx1 + multiple_down_to(power, i) * fpower(base, i) / facto(i);
        i++;
        if (i > 8 || mod(ansx1 - ansx0) < 0.00000001)
            break;
        ansx0 = ansx1;
    }
    return(ansx1);
}
float permu(int n, int r)
{
    float ans = facto(n) / facto(n - r);
    return(ans);
}
float combo(int n, int r)
{
    float ans = permu(n, r) / facto(r);
    return(ans);
}
float mod(float a)
{
    if (a >= 0)
        return(a);
    else
        return(-a);
}
float fsin(float y)
{
    if (y > 360)
    {
        do
        {
            y = y - 360;
        } while (y > 360);

    }
    float x = degree_to_rad(y);
    float ansx1 = 0, ansx0 = 0, i = 0, t = 1;
    while (1)
    {
        ansx1 = ansx1 + fpower(-1, i) * fpower(x, t) / facto(t);
        t += 2; i++;
        if (i > 5 && mod(ansx1 - ansx0) < 0.000000001)
            break;
        ansx0 = ansx1;
    }
    return(ansx1);
}
float fcos(float y)
{
    if (y > 360)
    {
        do
        {
            y = y - 360;
        } while (y > 360);

    }
    float x = degree_to_rad(y);
    float ansx1 = 1, ansx0 = 0; int i = 1, t = 2;
    while (1)
    {
        ansx1 = ansx1 + fpower(-1, i) * fpower(x, t) / facto(t);
        t += 2; i++;
        if (i > 6 && mod(ansx1 - ansx0) < 0.000000001)
            break;
        ansx0 = ansx1;
    }
    return (ansx1);
}
float ftan(float x)
{
    if (fcos(x) != 0)
        return (fsin(x) / fcos(x));
}
float degree_to_rad(float x)
{
    float ans = x * 3.14159265 / 180.0;
    return(ans);
}
float fcot(float x)
{
    if (fsin(x) != 0)
        return(fcos(x) / fsin(x));
}
float multiple_down_to(float num, int number_of_terms)
{
    float ans = 1;
    for (int i = 0; i < number_of_terms; i++)
    {
        ans = ans * num;
        num--;
    }
    return(ans);
}