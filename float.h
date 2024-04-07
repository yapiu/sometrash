#include <stdio.h>

class myfloat
{  
public:
    int c; 
    int d;
    myfloat(double v)
    {
        c = (int)v;
        d = (int)((v - c) * 10000);
    }
    void print()
    {
        printf("%d.%04d ", c, d);
    }
    friend myfloat operator + (myfloat, myfloat);
    friend myfloat operator * (myfloat, myfloat);
    friend myfloat operator - (myfloat, myfloat);
    friend myfloat operator / (myfloat, myfloat);
};