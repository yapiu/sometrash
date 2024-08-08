#include <cstdlib>
#include <stdio.h>
#pragma once

class myfloat {
protected:
  int c;
  int d;
  bool sign;

public:
  myfloat(double v = 0.0) {
    c = (int)v;
    d = abs((int)(((v - c) * 10000)));
    if(c < 0){
      sign = true;
    }
    sign = false;
  }
  myfloat(int, int, int, bool);
  void print();

  friend myfloat operator+(myfloat, myfloat);
  friend myfloat operator*(myfloat, myfloat);
  friend myfloat operator-(myfloat, myfloat);
};