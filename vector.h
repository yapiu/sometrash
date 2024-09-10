#include "Myfloat_overflow.h"
class vector {
  protected:
  Myfloat_overflow *v;
  int sz;
  int capacity;

public:
  vector(int s = 1);
  vector();
  ~vector();

  inline int size() const{return sz;}
  Myfloat_overflow &operator [](int);
  Myfloat_overflow &elem(int i) const {return v[i];}
  //const Myfloat_overflow& elem(int i) const { return v[i]; }
  void kick(int);
  void push(Myfloat_overflow);
  void print();
  vector& operator = (const vector &);
  vector operator + (vector &);
  friend vector operator - (vector &, vector &); // убрать френд
};

void error(const char *p);
