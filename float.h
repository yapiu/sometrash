#include <cstdlib>
#include <stdio.h>
#pragma once

class myfloat {
protected:
  int c;
  int d;
  bool sign;

public:
  myfloat(double v) {
    c = (int)v;
    d = abs((int)(((v - c) * 10000)));
    if(c > 0)
      d++;
    sign = false;
    //???
  }
  myfloat(int sum_c, int sum_d, int condition = 0, bool sign_in = 0) {
    if (condition == 0) {
      while (sum_d > 9999) {
        sum_c++;
        sum_d -= 10000;
      }
    }
    if (condition == 1) {
      while (sum_d > -9999 && sum_c > 0 && sum_d < 0) {
        sum_c--;
        sum_d += 10000;
      }
    }
    c = sum_c;
    d = sum_d;
    sign = sign_in;
  }
  void print() {
    char sg = ' ';
    if (sign) {
      sg = '-';
    }
    printf("%c%d.%04d ", sg, c, d);
  }
  friend myfloat operator+(myfloat, myfloat);
  friend myfloat operator*(myfloat, myfloat);
  friend myfloat operator-(myfloat, myfloat);
};