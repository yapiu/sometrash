#include "vector.h"
class Matrix {
protected:
int row;
int column;
vector *matrix;

public:
Matrix(int = 1, int = 1);
Matrix(const Matrix &a);
~Matrix();
vector &operator [](int);
Matrix &operator=(const vector &);

void print();
};