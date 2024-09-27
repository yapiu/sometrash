#include "Matrix.h"

int main() {

  Matrix m1(3, 3);

  m1[0][0] = 1;
  m1[0][1] = 2;
  m1[0][2] = 3;
  m1[1][0] = 4;
  m1[1][1] = 5;

  Matrix m2(3, 3);
  m2[0][0] = 2;
  m2[0][1] = 1;
  m2[0][2] = 5;
  m2[1][0] = 2.5;
  m2[1][1] = 1.5;
  m2[1][2] = 5.5;

  m1.print();
  printf("\n");
  m2.print();
  printf("\n");
  
  Matrix sum(3,3);
  sum = m1 + m2;
  //sum = m1; //+
  sum.print();

  return 0;
}