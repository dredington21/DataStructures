#ifndef ARRAY_VECTOR
#define ARRAY_VECTOR

#include "Exceptions/IndexOutOfBounds.h"
#include <cmath>
#include <iterator>
#include <iostream>


template <typename E> class ArrayVector{

public:
ArrayVector() : capacity(), n(0), A(nullptr){};
int size() const {return n;}
bool empty() const {return n==0;}

E &operator[](int i) {return A[i];} // not safe
E &at (int i) noexcept(false); // safe

void erase(int i);
void insert(int i, const E &e);
void reserve(int N);
void print();

private: 
  int capacity;
  int n;
  E *A;


};

template <typename E> E &ArrayVector<E> :: at(int i) noexcept(false){
  if (i < 0 || i >=n){
    throw(IndexOutOfBounds)("index out of range");
  }
  return A[i];
}

template <typename E> void ArrayVector<E>:: reserve(int N){
  if (capacity >= N) {
    return;
  }
  E *B = new E[N];
  for (int j = 0; j < n; j++){
    B[j] = A[j];
  }
  if (A != nullptr){
    delete[] A;
  }

  A=B;
  capacity = N;
}

template <typename E> void ArrayVector<E> :: insert(int i, const E &e){
  if(n >= capacity){
    reserve(std::max(1,2 * capacity));
  }
  for (int j=n-1; j>=i;j--){
    A[j+1] = A[j];
  }
  A[i] = e;
  n++;
}

template <typename E> void ArrayVector<E> :: erase(int i){
  for (int j = i+1; j <n; j++){
    A[j-1] = A[j];

  }
  n-1;
}

template <typename E> void ArrayVector<E> :: print(){
  for (int i=0; i<n;i++){
    std::cout << at(i) << " ";
  }
  std::cout << std:: endl;
}
#endif