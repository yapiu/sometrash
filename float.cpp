#include "float.h"
myfloat::myfloat(myfloat &a){
c = a.c;
d = a.d;
}
myfloat operator+(myfloat f1, myfloat f2) {
  int condition, sum_d, sum_c;
  bool sign;

  if (f1.d < f2.d) {
    condition = 0;

  } else {
    condition = 1;
  }

  if (f1.c + f2.c < 0) {
    sign = true;
  } else {
    sign = false;
  }

  sum_c = abs(f1.c + f2.c);
  sum_d = abs(f1.d + f2.d);

  return myfloat(sum_c, sum_d, condition, sign);
}
myfloat operator-(myfloat f1, myfloat f2) {
  f2.sign = !f2.sign;
  if ((f1.c < 0 && f2.c > 0) || (f1.c > 0 && f2.c < 0)) {
  f1.d *= -1;
  }
  f2.c *= -1;
  f2.d *= -1;
  return operator+(f1, f2);
}
myfloat operator*(myfloat f1, myfloat f2) {
  bool sign;
  int condition = -1;

  if (f1.c < 0 && f2.c < 0) {
    sign = false;
  } else if (f1.c < 0 || f2.c < 0) {
    sign = true;
  } else
    sign = false;

  int f1d = f1.d / 1000;
  int f2d = f2.d / 1000;
  int f1c = abs(f1.c);
  int f2c = abs(f2.c);

  int first_part = (f1c * 10 + f1d) * f2d;
  int second_part = (f1c * 10 + f1d) * f2c * 10;

  double multiply = (double)(first_part + second_part) / 100;
  myfloat result(multiply);

  return myfloat(result.c, result.d, condition, sign);
}