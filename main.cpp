#include "float.h"

int main()
{
	myfloat f1(-7.2);
	myfloat f2(8.3);
	myfloat f3(-10.9);
	myfloat f4 (2.2);
	
	myfloat a = f2 * f3;
	myfloat b = f1 * f3;
	myfloat c = f2 * f4;

	myfloat d = f1 + f3;
	myfloat e = f2 + f3; 
	myfloat f = f2 + f4;

	myfloat g = f1 - f3; 
	myfloat z = f2 - f4;
	myfloat x = f4 - f2;
	myfloat n = f3 - f4; // !

	a.print();
	b.print();
	c.print();
	d.print();
	e.print();
	f.print();
	g.print();
	z.print();
	x.print();
	n.print();

	return 0;
}