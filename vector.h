#include "Myfloat_overflow.h"

void error(const char *p);
template <typename T> class vector {
protected:
  T *v;
  int sz;
  int capacity;

public:
  vector(int s = 1) {
    if (s <= 0)
      error("er1");
    v = new T[s];
    if (v == 0)
      error("er2");
    sz = s;
    capacity = s;
  }
  ~vector() { delete[] v; }

  vector(const vector &a) {
    sz = a.sz;
    capacity = a.capacity;
    v = new T[capacity];
    for (int i = 0; i < sz; i++) {
      v[i] = a.v[i];
    }
  }

  inline int size() const { return sz; }

  T &operator[](int i) {
    if (i < 0 || i >= sz)
      error("er3");
    return v[i];
  }

  T &elem(int i) const { return v[i]; }

  void kick(int i) {
    for (int j = i + 1; i <= sz; j++) {
      if (i == sz - 1) {
        v[i] = 0;
        break;
      }
      v[i] = v[j];
      v[j] = 0;
      i++;
    }
    sz--;
  }

  void push(T number) {
    sz++;
    if (sz >= capacity) {
      capacity *= 2;
      T *new_vector = new T[capacity];
      for (int i = 0; i < sz - 1; i++) {
        new_vector[i] = v[i];
      }
      delete[] v;
      new_vector[sz - 1] = number;
      v = new_vector;
    } else {
      v[sz - 1] = number;
    }
  }
  void print() {
    for (int i = 0; i < sz; i++) {
      v[i].print();
    }
  }

  vector &operator=(const vector &a) {
    int s = a.size();
    if (s < a.capacity) {
      T *new_vector = new T[a.capacity];
      delete[] v;
      v = new_vector;
    }
    for (int i = 0; i < s; i++) {
      elem(i) = a.elem(i);
    }
    sz = a.sz;
    capacity = a.capacity;
    return *this;
  }

  vector operator+(vector &a) {
    int s = size();
    if (s != a.size()) {
      error("Size error!1");
    }
    vector sum(s);
    for (int i = 0; i < s; i++) {
      sum.elem(i) = elem(i) + a.elem(i);
    }
    return sum;
  }

  friend vector operator-(vector &a, vector &b) {
    int s = a.size();
    if (s != b.size()) {
      error("Size error");
    }
    vector sum(s);
    T *sp = sum.v, *ap = a.v, *bp = b.v;
    while (s--) {
      *sp++ = *ap++ - *bp++;
    }
    return sum;
  }
};


