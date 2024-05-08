#include "float.h"
#include <iostream>
#define limit 9999

class Myfloat_overflow : public myfloat {
private:
  int Saturation_flag = 0;

  void overflow() {
    Saturation_flag = 1;
    if (c > limit || c < -limit) {
      c = limit;
      d = 0;
      Saturation_flag = 0;
    }
  }

public:
  Myfloat_overflow(double v) : myfloat(v) { overflow(); }
  Myfloat_overflow(myfloat a) : myfloat(a) { overflow(); }
  void print();
};