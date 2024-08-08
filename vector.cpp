#include "vector.h"
#include "float.h"

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