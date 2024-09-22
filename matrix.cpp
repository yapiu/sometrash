#include "matrix.h"
#include <cstdio>

vector &Matrix::operator[](int number) {
  if (row < 0 || number >= row) {
    error("Size isn't reachable!");
  }
  return matrix[number];
}

Matrix &Matrix::operator=(const Matrix &a) {
  for (int i = 0; i < row; i++) {
    matrix[i] = a.matrix[i];
  }
  return *this;
}

Matrix::Matrix(int numberOfRows, int numberOfColumn) {
  if (numberOfColumn <= 0 || numberOfRows <= 0)
    error("Number has to be real");

  row = numberOfRows;
  column = numberOfColumn;

  matrix = new vector[numberOfRows]; // vector with 1 elements

  if (matrix == 0)
    error("Null pointer");

  vector massive = vector(numberOfColumn); 
  for (int i = 0; i < numberOfRows; i++) {
    matrix[i] = massive;
  }
}

Matrix::Matrix(const Matrix &a) {
  row = a.row;
  column = a.column;

  matrix = new vector[row];
  for (int i = 0; i < row; i++) {
    matrix[i] = a.matrix[i];
  }
}

Matrix::~Matrix() { delete[] matrix; }

void Matrix::print() {
  for (int rowConuter = 0; rowConuter < row; rowConuter++) {
    matrix[rowConuter].print();
    printf("\n");
  }
}

Matrix Matrix::operator+(Matrix &a){
  if(a.column != column && a.row != row){
    error("Size of matrix is not the same!");
  }
  Matrix sum(row,column);
  
  for (int rowConter = 0; rowConter < row; rowConter++) {
  sum[rowConter] = matrix[rowConter] + a.matrix[rowConter];
  }
  return sum;
}