#include "float.h"
#include <iostream>
#define limit 9999

class Myfloat_overflow : myfloat {
protected:
  int condition_print = 0;

public:
  Myfloat_overflow(double v) : myfloat(v) {
    
  }
  Myfloat_overflow(int sum_c, int sum_d, int condition = 0, bool sign_in = 0)
      : myfloat(sum_c, sum_d, condition, sign_in){
    if (c > limit || c < -limit) {
      c = limit;
      d = 0;
      condition = 0;
    }
    else{
    condition = 1;
    }
    condition_print = condition;
    sign = sign_in;
  }

  Myfloat_overflow(myfloat a) : myfloat(a){

  }

  friend Myfloat_overflow operator+(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator-(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator*(Myfloat_overflow, Myfloat_overflow);
  void print();
};