#include <stdio.h>

class myfloat
{
protected:
    int c; 
    int d;
    
public:
    myfloat(double v)
    {
        c = (int)v;
        d = (int)((v - c) * 10000);
    }
    void print()
    {
        printf("%d.%04d ", c, d);
    }
};