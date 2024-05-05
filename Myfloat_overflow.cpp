#include "Myfloat_overflow.h"

void Myfloat_overflow::print() {
  char sg = ' ';
  if (sign) {
    sg = '-';
  }
  if (condition_print == 0) {
    printf("%c*%d.%04d ", sg, c, d);
  }
  if (condition_print == 1){
    printf("%c%d.%04d ", sg, c, d);
  }
}
Myfloat_overflow operator+(Myfloat_overflow f1, Myfloat_overflow f2) {
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

  return Myfloat_overflow(sum_c, sum_d, condition, sign);
}
Myfloat_overflow operator-(Myfloat_overflow f1, Myfloat_overflow f2) {
  f2.sign = !f2.sign;
  if ((f1.c < 0 && f2.c > 0) || (f1.c > 0 && f2.c < 0)) {
    f1.d *= -1;
  }
  f2.c *= -1;
  f2.d *= -1;
  return operator+(f1, f2);
}
Myfloat_overflow operator*(Myfloat_overflow f1, Myfloat_overflow f2) {
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
  Myfloat_overflow result(multiply);

  return Myfloat_overflow(result.c, result.d, condition, sign);
}
