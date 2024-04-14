#include "float.h"

int main()
{
	myfloat f1(-7.2);
	myfloat f2(8.3);
	myfloat f3(-10.9);
	myfloat f4 (2.2);
	
	myfloat f6 = f2 * f3;
	myfloat f7 = f1 * f3;
	myfloat f8 = f2 * f4;

	f6.print();
	f7.print();
	f8.print();
	return 0;
}