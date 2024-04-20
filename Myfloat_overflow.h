#include "float.h"
#include <iostream>

class Myfloat_overflow : myfloat {
protected:
  int c;
  int d;
  int condition_print;

public:
  Myfloat_overflow(double v) : myfloat(v) {
    c = (int)v;
    d = abs((int)(((v - c) * 10000)));
    if (c > 0)
      d++;
  }
  Myfloat_overflow(int sum_c, int sum_d, int condition = 0, bool sign_in = 0)
      : myfloat(sum_c, sum_d, condition, sign_in) {
    if (sum_d > 9999 && sum_c < 9999) {
      sum_d = 9999;
      condition = 1;
    }
    if (sum_c > 9999 && sum_d < 9999) {
      sum_c = 9999;
      condition = 0;
    }
    if (sum_c > 9999 && sum_d > 9999) {
      sum_c = 9999;
      sum_d = 9999;
      condition = 2;
    }
    if (sum_c < -9999 & sum_d < 9999) {
      sum_c = -9999;
      condition = -1;
    }
    if (sum_c < -9999 && sum_d > 9999) {
      sum_c = -9999;
      sum_d = 9999;
      condition = -2;
    } 
    if ((sum_c < 9999 && sum_d < 9999) || (sum_c > -9999 && sum_d < 9999)) {
    condition = 3;
    }
    
    condition_print = condition;
    c = sum_c;
    d = sum_d;
    sign = sign_in;
  }

  friend Myfloat_overflow operator+(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator-(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator*(Myfloat_overflow, Myfloat_overflow);
  void print();
};