#include "Matrix.h"

int main() {

  Matrix m1(3, 3);

  m1[0][0] = 1;
  m1[0][1] = 2;
  m1[0][2] = 3;
  m1[1][0] = 4;
  m1[1][1] = 5;
  m1.print();

  return 0;
}