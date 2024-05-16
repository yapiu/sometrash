#include "float.h"
#include <iostream>
#define limit 9999

class Myfloat_overflow : public myfloat {
protected:
  int Saturation_flag;
  // убрать отсюда перенести в overflow() //не использует оператор сложения
  // нужно добавить френды чтобы видел
  //  кери флаг сохранять и если делаются вычисления числом с керрифлагом и без
  //  нужно выводить звездочку
  int overflow() {
    Saturation_flag = 0;
    if (c > limit || c < -limit) {
      c = limit;
      d = 0;
      Saturation_flag = 1;
    }
    return Saturation_flag;
  }

public:
  Myfloat_overflow(double v) : myfloat(v) { Saturation_flag = overflow(); }
  Myfloat_overflow(myfloat a, int flag) : myfloat(a) {
    Saturation_flag = overflow();}
  void print();
  friend Myfloat_overflow operator+(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator-(Myfloat_overflow, Myfloat_overflow);
  friend Myfloat_overflow operator*(Myfloat_overflow, Myfloat_overflow);
};