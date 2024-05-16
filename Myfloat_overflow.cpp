#include "Myfloat_overflow.h"
#include "float.h"

void Myfloat_overflow::print() {
  if (Saturation_flag == 1) {
    printf("*");
  }
  myfloat::print();
} 
Myfloat_overflow operator+(Myfloat_overflow f1, Myfloat_overflow f2) {
  int flag = f1.Saturation_flag || f2.Saturation_flag;
  myfloat sum = (myfloat)f1 + (myfloat)f2;
  return Myfloat_overflow(sum, flag);
}
Myfloat_overflow operator-(Myfloat_overflow f1, Myfloat_overflow f2) {

  int flag = f1.Saturation_flag || f2.Saturation_flag;

  myfloat result = (myfloat)f1 - (myfloat)f2;

  return Myfloat_overflow(result, flag);
}
Myfloat_overflow operator*(Myfloat_overflow f1, Myfloat_overflow f2) {
  int flag = f1.Saturation_flag || f2.Saturation_flag;

  myfloat multiply = (myfloat)f1 * (myfloat)f2;

  return Myfloat_overflow(multiply, flag);
}
