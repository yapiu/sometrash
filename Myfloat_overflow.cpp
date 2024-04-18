#include "Myfloat_overflow.h"

void Myfloat_overflow :: print() {
  char sg = ' ';
  if (sign) {
    sg = '-';
  }
  char ptr_c = ' ';
  char ptr_d = ' ';
  if (condition_print == 0 || condition_print == -1) {
    ptr_c = '*';
  }
  if (condition_print == 1) {
    ptr_d = '*';
  }
  if (condition_print == 2 || condition_print == -2) {
    ptr_c = '*';
    ptr_d = '*';
  }
  printf("%c%c%d.%c%04d ", sg, ptr_c, c, ptr_d, d);
}
Myfloat_overflow operator+(Myfloat_overflow f1, Myfloat_overflow f2) {
  int condition = 0;
  bool sign;
  int sum_c;
  int sum_d;

  if (f1.c + f2.c < 0) {
    sign = true;
  } else
    sign = false;

  sum_c = abs(f1.c + f2.c);
  if (f1.c + f2.c < 0) {
    sum_d = abs(f1.d - f2.d);
  } else
    sum_d = f1.d + f2.d;

  return Myfloat_overflow(sum_c, sum_d, condition, sign);
}
