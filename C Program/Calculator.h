#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED
#endif // CALCULATOR_H_INCLUDED

#include <math.h>

int add(int a, int b)
{
    int c=a+b;
    return c;
}

int sub(int a1, int b1)
{
    int c1=a1-b1;
    return c1;
}

int mul(int a2, int b2)
{
    int c2=a2*b2;
    return c2;
}

int div(int a3, int b3)
{
    int c3=a3/b3;
    return c3;
}

int power(int a4)
{
    int c4 = pow(a4,2)+0.5;
    return c4;
}

double squarert(int a5)
{
    double c5 = sqrt(a5);
    return c5;
}

double cubert(int a6)
{
    double c6 = cbrt(a6);
    return c6;
}