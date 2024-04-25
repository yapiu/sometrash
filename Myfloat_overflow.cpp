#include "Myfloat_overflow.h"

void Myfloat_overflow :: print() {
  char sg = ' ';
  if (sign) {
    sg = '-';
  }
  // char ptr_c = ' ';
  // char ptr_d = ' ';
  if (condition_print == 0 || condition_print == -1) {
    // ptr_c = '*';
    printf("%c*%d.%04d ", sg, c, d);
  }
  if (condition_print == 1) {
    // ptr_d = '*';
    printf("%c%d.*%04d ", sg, c, d);
  }
  if (condition_print == 2 || condition_print == -2) {
    // ptr_c = '*';
    // ptr_d = '*';
    printf("%c*%d.*%04d ", sg, c, d);
  }
  if (condition_print == 3) {
    printf("%c%d.%04d ", sg, c, d);
  }
  // printf("%c%c%d.%c%04d ", sg, ptr_c, c, ptr_d, d);
}
