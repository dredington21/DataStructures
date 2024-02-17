#ifndef LINKED_DEQUE
#define LINKED_DEQUE

#include "DLinkedList/DLinkedList.h"
#include "Exceptions/DequeEmptyException.h"
#include <iostream>

template <typename E> class LinkedDeque {
public:
  LinkedDeque() : D(), numElem(0) {}
  int size() const {return numElem;}
  bool empty() const {return numElem == 0;}
  const E &front() const noexcept(false);
  const E &back() const noexcept(false);

  void insertFront(const E &e);
  void insertBack(const E &e);
  
  void removeFront() noexcept(false);
  void removeBack() noexcept(false);

  void print();

private:
  int numElem;
  DLinkedList<E> D;
};

template <typename E> const E &LinkedDeque<E>::front() const noexcept(false) {
  if (empty()) {
    throw DequeEmptyException("Front of empty deque");
  }
  return D.front();
}

template <typename E> const E &LinkedDeque<E>::back() const noexcept(false) {
  if (empty()) {
    throw DequeEmptyException("Back of empty deque");
  }
  return D.back();
}


template <typename E> void LinkedDeque<E>::insertFront(const E &e) {
  D.addFront(e);
  numElem++;
}

template <typename E> void LinkedDeque<E>::insertBack(const E &e) {
  D.addBack(e);
  numElem++;
}

template <typename E> void LinkedDeque<E>::removeFront() noexcept(false) {
  if (empty()) {
    throw DequeEmptyException("removeFront of empty deque");
  }
  D.removeFront();
  numElem--;
}

template <typename E> void LinkedDeque<E>::removeBack() noexcept(false) {
  if (empty()) {
    throw DequeEmptyException("removeBack of empty deque");
  }
  D.removeBack();
  numElem--;
}

template <typename E> void LinkedDeque<E>::print() {
  LinkedDeque<E> p;

  while (!empty()) {
    std::cout << front() << " ";
    p.insertFront(front());
    removeFront();
  }

  while (!p.empty()) {
    insertFront(p.front());
    p.removeFront();
  }

  std::cout << std::endl;

}


// D - 1 4 8 3
// p - 



#endif


