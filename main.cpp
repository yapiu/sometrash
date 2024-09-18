#include "Matrix.h"

int main() {

  Matrix m1(3, 3);
  vector v1(3);
  v1[0] = 1134;
  v1[1] = 223;
  v1[2] = 3323;

  m1[0] = v1;
  m1.print();

  return 0;
}