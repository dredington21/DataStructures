#ifndef SLINKEDLIST
#define SLINKEDLIST

#include "SNode.h"
#include <iostream>

template <typename E> class SLinkedList {
public:
  SLinkedList();
  ~SLinkedList();
  bool empty() const;
  const E &front() const;
  void addFront(const E &e);
  void removeFront();
  void print();

private:
  int nElem = 0;
  SNode<E> *head;
};
template <typename E> SLinkedList<E>::SLinkedList() : head(nullptr) {}

template <typename E> bool SLinkedList<E>::empty() const {
  return head == nullptr;
}

template <typename E> const E &SLinkedList<E>::front() const {
  return head->elem;
}

template <typename E> SLinkedList<E>::~SLinkedList() {
  while (!empty())
    removeFront();
}

template <typename E> void SLinkedList<E>::addFront(const E &e) {
  SNode<E> *v = new SNode<E>;
  v->elem = e;
  v->next = head;
  head = v;

  nElem++;
}

template <typename E> void SLinkedList<E>::removeFront() {
  SNode<E> *old = head;
  head = old->next;
  delete old;
  nElem--;
}

template <typename E> void SLinkedList<E>::print() {
  SNode<E> *curr = head;

  while (curr) {
    std::cout << curr->elem << " ";
    curr = curr->next;
  }
  std::cout << std::endl << std::endl;
}

#endif