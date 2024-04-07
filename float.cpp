#include <stdio.h>
#include "float.h"

myfloat operator+(myfloat f1, myfloat f2)
{
    int sum_c = f1.c + f2.c;
    int sum_d = f1.d + f2.d;
    if (sum_d > 9999)
    {
        sum_d -= 10000;
        sum_c++;
    }
    f1.c = sum_c;
    f1.d = sum_d;
    return f1;
}
myfloat operator-(myfloat f1, myfloat f2)
{
    int sum_c, sum_d, is_negative;

    if (f1.c > f2.c && f1.d < f2.d)
    {
        f1.c--;
        f1.d += 10000;
        sum_d = f1.d - f2.d;
        sum_c = f1.c - f2.c;
        f1.c = sum_c;
        f1.d = sum_d;
        return f1;
    }
    if (f1.c < f2.c && f1.d > f2.d)
    {
        int num = f1.c;
        f1.c = f2.c;
        f2.c = num;

        int num1 = f1.d;
        f1.d = f2.d;
        f2.d = num1;
        
        f1.c--;
        f1.d += 10000;

        sum_d = f1.d - f2.d;
        sum_c = f1.c - f2.c;
        f1.c = -1 *sum_c;
        f1.d = sum_d;
        return f1;
    }
    if (f1.c < f2.c && f1.d < f2.d)
    {
        int num = f1.c;
        f1.c = f2.c;
        f2.c = num;

        int num1 = f1.d;
        f1.d = f2.d;
        f2.d = num1;

        sum_d = f1.d - f2.d;
        sum_c = f1.c - f2.c;
        f1.c = -1 *sum_c;
        f1.d = sum_d;
        return f1;
    }
}
myfloat operator*(myfloat f1, myfloat f2)
{
    int sum_c = f1.c * f2.c;
    int sum_d = f1.d * f2.d;
    f1.c = sum_c;
    f1.d = sum_d;
    return f1;
}
myfloat operator/(myfloat f1, myfloat f2)
{
    int sum_c = f1.c / f2.c;
    int sum_d = f1.d / f2.d;
    f1.c = sum_c;
    f1.d = sum_d;
    return f1;
}
