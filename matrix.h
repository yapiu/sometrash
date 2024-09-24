#include "vector.h"
class Matrix {
protected:
int row;
int column;
vector<Myfloat_overflow> *matrix;

public:
Matrix(int = 1, int = 1);
Matrix(const Matrix &a);
~Matrix();
vector<Myfloat_overflow> &operator [](int);
Matrix &operator=(const Matrix &);
Matrix operator+(Matrix&);

void print();
};