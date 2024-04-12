#include "float.h"

int main()
{
	myfloat f1(7.9);
	myfloat f2(8.2);
	myfloat f10(10.9);
	
	myfloat f3 = f1 + f2;
	myfloat f4 = f1 - f2;
	myfloat f4pos = f2 - f1;
	myfloat f5 = f2 - f10;
	myfloat f6 = f2 * f1;
	f3.print();
	f4.print();
	f4pos.print();
	f5.print();
	f6.print();
	return 0;
}