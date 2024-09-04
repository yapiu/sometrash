#include "vector.h"

vector::vector(int s){
  if(s <= 0) error("er1");
  v = new myfloat[s];
  if(v == 0) error("er2");
  sz = s;
  capacity = s;
}

vector::vector(){
  vector(99);
}

vector::~vector(){
delete []v;
}

myfloat& vector::operator[](int i){
  if(i < 0 || i >= sz) error("er3");
  return v[i];
}

void error(const char* p){
  printf("%s", p);
  exit(-1);
}

void vector::kick(int i){
  for(int j = i + 1; i <= sz; j++){
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

void vector::push(myfloat number){
  sz++;
  if(sz >= capacity){  
  capacity *= 2;
  myfloat* new_vector = new myfloat[capacity];
  for (int i = 0; i < sz - 1; i++) {
  new_vector[i] = v[i];
  }
  delete[] v;
  new_vector[sz - 1] = number;
  v = new_vector;
  }
  else{
    v[sz - 1] = number;
  }
}

void vector::print(){
  for(int i = 0; i < sz; i++){
    v[i].print();
  }
}

vector vector::operator+(vector &a){
  int s = size();
  if(s != a.size()){
    error("Size error!1");
  }
  vector sum(s); 
  for (int i = 0; i < s; i++){
    sum.elem(i) = elem(i) + a.elem(i);
  }
  return sum;
}

vector operator - (vector &a, vector &b){
  int s = a.size();
  if(s != b.size()){
    error("Size error");
  }
  vector sum(s);
  myfloat *sp = sum.v, *ap = a.v, *bp = b.v;
  while (s--){
    *sp++ = *ap++ - *bp++;
  }
  return sum;
}

vector& vector::operator=(const vector &a){
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