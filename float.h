#include <stdio.h>

class myfloat {
protected:
  int c;
  int d;
  bool sign;

public:
  myfloat(double v) {
    c = (int)v;
    d = (int)((v - c) * 10000);
  }
  myfloat(int sum_c, int sum_d, int condition) {
    if (condition == 0) {
      while (sum_d > 9999) {
        sum_c++;
        sum_d -= 10000;
      }
    }
    if (condition == 1) {
      while (sum_d > -9999 && sum_c > 0) {
        sum_c--;
        sum_d += 10000;
      }
    }
    c = sum_c;
    d = sum_d;
  }
  void print() { 
    if(sign){
    printf("-%d.%04d ", c, d); 
    }
    else
        printf("%d.%04d ", c, d);
    }
  friend myfloat operator+(myfloat, myfloat);
  friend myfloat operator*(myfloat, myfloat);
  friend myfloat operator-(myfloat, myfloat);
};