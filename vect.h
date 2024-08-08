#include "vector.h"

class vect:public vector{  
  public:
    vect(int s = 1) : vector(s){};
    vect(vect &);
    //~vect();
    inline vect& operator = (const vect &);
    inline vect operator + (vect &);
    friend inline vect operator - (vect &, vect &);
};
