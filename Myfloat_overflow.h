#include "float.h"
#include <iostream>
#define limit 9999

class Myfloat_overflow : public myfloat {
private:
//убрать отсюда перенести в overflow() //не использует оператор сложения нужно добавить френды чтобы видел
// кери флаг сохранять и если делаются вычисления числом с керрифлагом и без нужно выводить звездочку
  int overflow() {
    if (c > limit || c < -limit) {
      c = limit;
      d = 0;
      Saturation_flag = 1;
    }
    return Saturation_flag;
  }

public:
  Myfloat_overflow(double v) : myfloat(v) { overflow(); }
  Myfloat_overflow(myfloat a) : myfloat(a) { overflow(); }
  void print();
};