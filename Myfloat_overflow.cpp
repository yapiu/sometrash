#include "Myfloat_overflow.h"
#include "float.h"

void Myfloat_overflow::print() {
  char sg = ' ';
  if (sign) {
    sg = '-';
  }
  if (Saturation_flag == 0) {
    printf("%c*%d.%04d ", sg, c, d);
  }
  if (Saturation_flag == 1){
    printf("%c%d.%04d ", sg, c, d);
  }
}
Myfloat_overflow operator+(Myfloat_overflow f1, Myfloat_overflow f2) {

  myfloat sum = (myfloat)f1 + (myfloat)f2;

  return Myfloat_overflow(sum);
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

  myfloat multiply = (myfloat)f1 * (myfloat)f2;

  return Myfloat_overflow(multiply);
}
