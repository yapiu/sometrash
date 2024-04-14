#include <stdio.h>
#include <cstdlib>

class myfloat {
protected:
  int c;
  int d;
  bool sign;

public:
  myfloat(double v) {
    c = (int)v;
    d = abs((int)(((v - c) * 10000)+ 1));
  }
  myfloat(int sum_c, int sum_d, int condition, bool sign_in) {
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
    if (sign) {
      printf("-%d.%04d ", c, d);
    } else
      printf("%d.%04d ", c, d);
  }
  friend myfloat operator+(myfloat, myfloat);
  friend myfloat operator*(myfloat, myfloat);
  friend myfloat operator-(myfloat, myfloat);
};