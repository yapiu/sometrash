#include "float.h"
class vector {
  protected:
  myfloat *v;
  int sz;
  int capacity;

public:
  vector(int);
  vector();
  ~vector();

  inline int size() const{return sz;}
  myfloat &operator [](int);
  myfloat &elem(int i) const {return v[i];}
  //const myfloat& elem(int i) const { return v[i]; }
  void kick(int);
  void push(myfloat);
  void print();
};

void error(const char *p);
