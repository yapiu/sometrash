#include <iostream>
#include "float.h"

int main()
{
	myfloat f1(7.9);
	myfloat f2(8.2);
	myfloat f3 = f1 + f2;
	f3.print();
	return 0;
}