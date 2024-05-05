#include "Myfloat_overflow.h"
#include "float.h"
#include <cstdio>


int main() {
  myfloat f1(-7.2);
  myfloat f2(8.3);
  myfloat f3(-10.9);
  myfloat f4(2.2);
  myfloat f5(0);

  Myfloat_overflow f1m(-7.2);
  Myfloat_overflow f2m(8.3);
  Myfloat_overflow f3m(-10.9);
  Myfloat_overflow f4m(2.2);
  Myfloat_overflow f5m(9999.9999);

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

  Myfloat_overflow am = f2m * f3m;
  Myfloat_overflow bm = f1m * f3m;
  Myfloat_overflow cm = f2m * f4m;

  Myfloat_overflow dm = f1m + f3m;
  Myfloat_overflow em = f2m + f3m;
  Myfloat_overflow fm = f2m + f4m;

  Myfloat_overflow gm = f1m - f3m;
  Myfloat_overflow zm = f2m - f4m;
  Myfloat_overflow xm = f4m- f2m;
  Myfloat_overflow nm = f3m - f4m;
  Myfloat_overflow mm = f5m + f5m;
  Myfloat_overflow km = f5m - f5m;
  Myfloat_overflow pm = f2m + f5m;

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

  printf("\n");

  am.print();
  bm.print();
  cm.print();
  dm.print();
  em.print();
  fm.print();
  gm.print();
  zm.print();
  xm.print();
  nm.print();
  mm.print();
  km.print();
  pm.print();
  return 0;
}