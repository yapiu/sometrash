#include "vect.h"

vect vect::operator+(vect &a){
  int s = size();
  if(s != a.size()){
    error("Size error!1");
  }
  vect sum(s); 
  for (int i = 0; i < s; i++){
    sum.elem(i) = elem(i) + a.elem(i);
  }
  return sum;
}

vect operator - (vect &a, vect &b){
  int s = a.size();
  if(s != b.size()){
    error("Size error");
  }
  vect sum(s);
  myfloat *sp = sum.v, *ap = a.v, *bp = b.v;
  while (s--){
    *sp++ = *ap++ - *bp++;
  }
  return sum;
}

vect& vect::operator=(const vect &a){
  if(this != &a){
    int s = size();
  if(s < a.size()){
    error("Size error!");
  }
  if (s > a.size()) {
    s = a.size();
  }
  for(int i = 0; i < s; i++){
  elem(i) = a.elem(i);
  }
  }
  return *this;
}