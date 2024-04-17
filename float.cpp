#include "float.h"

myfloat operator+(myfloat f1, myfloat f2) {
  int condition = 0;
  bool sign;
  int sum_d;

  if (f1.c + f2.c < 0) {
    sign = true;
  } else
    sign = false;

  int sum_c = abs(f1.c + f2.c);
  if (f1.c + f2.c < 0) {
    sum_d = abs(f1.d - f2.d);
  } else
    sum_d = f1.d + f2.d;

  return myfloat(sum_c, sum_d, condition, sign);
}
myfloat operator-(myfloat f1, myfloat f2) {
  int sum_c, sum_d;

  // Вычитание, где первое число больше второго, а его дробная часть меньше
  if (f1.c > f2.c && f1.d < f2.d && f1.c > 0 && f2.c > 0) {
    int condition = 1; // Флаг
    sum_d = f1.d - f2.d;
    sum_c = f1.c - f2.c;

    bool sign = false;
    return myfloat(sum_c, sum_d, condition, sign);
  }
  // Вычитание, где первое число меньше второго, а его дробная часть больше
  if (f1.c < f2.c && f1.d > f2.d && f1.c > 0 && f2.c > 0) {

    int condition = 1; // Флаг

    sum_d = f2.d - f1.d;
    sum_c = f2.c - f1.c;

    bool sign = true;
    return myfloat(sum_c, sum_d, condition, sign);
  }
  // Вычитание, где первое число меньше второго, как и его дробная часть
  if (f1.c < f2.c && f1.d < f2.d && f1.c > 0 && f2.c > 0) {

    int condition = -1; // Флаг

    sum_d = f2.d - f1.d;
    sum_c = f2.c - f1.c;

    bool sign = true;
    return myfloat(sum_c, sum_d, condition, sign);
  }
  if (f1.c > f2.c && f1.d > f2.d && f1.c > 0 && f2.c > 0) {

    int condition = -1; // Флаг

    sum_d = f1.d - f2.d;
    sum_c = f1.c - f2.c;

    bool sign = false;
    return myfloat(sum_c, sum_d, condition, sign);
  }
  if (f2.c < 0 && f1.c < 0) {
    int condition = 0;
    bool sign = false;
    sum_d = abs(f1.d - f2.d);
    sum_c = abs(f1.c - f2.c);
    return myfloat(sum_c, sum_d, condition, sign);
  }
  if ((f2.c > 0 && f1.c < 0) || (f2.c < 0 && f1.c > 0)) {
    int condition = 0;
    bool sign = true;
    sum_d = abs(f1.d + f2.d);
    sum_c = abs(f1.c - f2.c);
    return myfloat(sum_c, sum_d, condition, sign);
  }
  else {
    int condition = 0;
    bool sign = false;
    sum_d = abs(f1.d - f2.d);
    sum_c = abs(f1.c - f2.c);
    return myfloat(sum_c, sum_d, condition, sign);
  }
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