#include "float.h"
#include "Myfloat_overflow.h"

int main()
{
	myfloat f1(-7.2);
	myfloat f2(8.3);
	myfloat f3(-10.9);
	myfloat f4 (2.2);

	Myfloat_overflow f0(10.9999);
	Myfloat_overflow f9(9999.9999);
	
	myfloat a = f2 * f3;
	myfloat b = f1 * f3;
	myfloat c = f2 * f4;

	myfloat d = f1 + f3;
	myfloat e = f2 + f3; 
	myfloat f = f2 + f4;

	myfloat g = f1 - f3; 
	myfloat z = f2 - f4;
	myfloat x = f4 - f2;
	myfloat n = f3 - f4; 

	Myfloat_overflow h = f0 + f9;


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

	h.print();
	return 0;
}