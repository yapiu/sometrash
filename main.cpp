//#include "Myfloat_overflow.h"
#include "vector.h"
#include <cstdio>
//#include <cstdio>


int main() {
  vector v1(3);
  v1.push(121.3);
  v1.push(3.5);
  v1.push(6.89);
  v1.print();

  vector v3(2);
  v3.push(3);
  v3.push(134.9);
  v3.push(27.1);

  vector v2(2);
  v2.push(121.1);
  v2.push(3);
  v2.push(6);
  
  vector v4(10);

  v4 = v2 + v3;
  printf("\n");
  v4.print();

  v4 = v2 - v3;
  v4.print();
  return 0;
}