#include <stdio.h>
#include "float.h"

// void myfloat::print(void)
// {
//     printf("%d.%04d ", c, d);
// }


myfloat operator + (myfloat f1, myfloat f2)
{
    int sum_c = f1.c + f2.c; 
    int sum_d = f1.d + f2.d;
    f1.c = sum_c;
    f1.d = sum_d;
    return f1;
}
