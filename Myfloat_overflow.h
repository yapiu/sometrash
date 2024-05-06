#include "float.h"
#include <iostream>
#define limit 9999

class Myfloat_overflow : myfloat {
private:
  int Saturation_flag = 0;

public:
  Myfloat_overflow(double v) : myfloat(v) {
    
  }
  Myfloat_overflow(myfloat a) : myfloat(a) {
    int Saturation_flag = 1;
    if (c > limit || c < -limit) {
      c = limit;
      d = 0;
      Saturation_flag = 0;
    }
  }


  friend Myfloat_overflow operator+(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator-(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator*(Myfloat_overflow, Myfloat_overflow);
  void print();
};