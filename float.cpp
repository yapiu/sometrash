#include "float.h"
int condition;
bool sign;

myfloat operator+(myfloat f1, myfloat f2) {
  condition = 0;
  int sum_c = f1.c + f2.c;
  int sum_d = f1.d + f2.d;
  
  sign = false;
  return myfloat(sum_c, sum_d, condition);
}
myfloat operator-(myfloat f1, myfloat f2) {
  int sum_c, sum_d, is_negative;

  // Вычитание, где первое число больше второго, а его дробная часть меньше
  if (f1.c > f2.c && f1.d < f2.d) {
    condition = 1; // Флаг
    sum_d = f1.d - f2.d;
    sum_c = f1.c - f2.c;

    sign = false;
    return myfloat(sum_c, sum_d, condition);
  }
  // Вычитание, где первое число меньше второго, а его дробная часть больше
  if (f1.c < f2.c && f1.d > f2.d) {
    int num = f1.c; // Меняю местами числа
    f1.c = f2.c;
    f2.c = num;

    int num1 = f1.d;
    f1.d = f2.d;
    f2.d = num1;

    condition = 1; // Флаг
    sum_d = f1.d - f2.d;
    sum_c = f1.c - f2.c;

    sign = true;
    return myfloat(sum_c, sum_d, condition);
  }
  // Вычитание, где первое число меньше второго, как и его дробная часть
  if (f1.c < f2.c && f1.d < f2.d) {
    int num = f1.c; // Меняю местами числа
    f1.c = f2.c;
    f2.c = num;

    int num1 = f1.d;
    f1.d = f2.d;
    f2.d = num1;

    condition = -1; // Флаг
    sum_d = f1.d - f2.d;
    sum_c = f1.c - f2.c;

    sign = true;
    return myfloat(sum_c, sum_d, condition);
  }
  return -666;
}
myfloat operator*(myfloat f1, myfloat f2) {

  int sum_c = f1.c * f2.c;
  int sum_d = f1.d * f2.d;
  
  condition = 0;
  f1.c = sum_c;
  f1.d = sum_d;
  return myfloat(sum_c, sum_d, condition);
}

