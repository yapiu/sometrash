#include "float.h"
#include <iostream>
#define limit 9999

class Myfloat_overflow : public myfloat {
private:
  int Saturation_flag;

  void overflow() {
    Saturation_flag = 0;
    if (c >= limit || c <= -limit) {
      c = limit;
      d = 0;
      Saturation_flag = 1;
    }
  }
//=(
public:
  Myfloat_overflow(double v) : myfloat(v) { overflow(); }
  Myfloat_overflow(myfloat a, int flag) : myfloat(a) {
  overflow();
  Saturation_flag = flag;
  }
  void print();
  friend Myfloat_overflow operator+(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator-(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator*(Myfloat_overflow, Myfloat_overflow);
};