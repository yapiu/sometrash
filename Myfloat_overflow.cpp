#include "Myfloat_overflow.h"
#include "float.h"

void Myfloat_overflow::print() {
  if (Saturation_flag == 1) {
    printf("*");
  }
  myfloat::print();
} 
Myfloat_overflow operator+(Myfloat_overflow f1, Myfloat_overflow f2) {

  myfloat sum = (myfloat)f1 + (myfloat)f2;

  return Myfloat_overflow(sum);
}
Myfloat_overflow operator-(Myfloat_overflow f1, Myfloat_overflow f2) {

  myfloat result = (myfloat)f1 - (myfloat)f2;

  return Myfloat_overflow(result);
}
Myfloat_overflow operator*(Myfloat_overflow f1, Myfloat_overflow f2) {

  myfloat multiply = (myfloat)f1 * (myfloat)f2;

  return Myfloat_overflow(multiply);
}
