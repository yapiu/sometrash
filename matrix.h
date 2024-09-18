#include "vector.h"
class Matrix {
protected:
int row;
int column;
vector *matrix;

public:
// Matrix();
Matrix(int, int);
~Matrix();
vector &operator [](int);
// Matrix &operator=(const vector &);
void print();
};