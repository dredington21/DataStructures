// FILO = LIFO

// push(2), push(4), push(8)

// 8 -> 4 -> 2

// top() = 8
// pop()
// 4 2

// nullptr
// pop()
// top()

#ifndef LINKED_STACK
#define LINKED_STACK

#include "Exceptions/StackEmptyException.h"
#include "SLinkedList/SLinkedList.h"
#include <exception>
#include <iostream>
#include <string>

template <typename E> class LinkedStack {
public:
  LinkedStack() : S(), numElem(0) {}

  int size() const {return numElem;}
  bool empty() const {return numElem == 0;}
  const E &top() const noexcept(false); // return top element of stack
  void push(const E &e);                // add element to top of stack
  void pop() noexcept(false);           // remove top elemet from stack
  void print();
  void clearStack();

private:
  SLinkedList<E> S;
  int numElem;
};

template <typename E> void LinkedStack<E>::push(const E &e) {
  S.addFront(e);
  numElem++;
}

template <typename E> const E &LinkedStack<E>::top() const noexcept(false) {

  if (empty()) {
    throw StackEmptyException("Top of empty stack");
  }

  return S.front();
}

template <typename E> void LinkedStack<E>::pop() noexcept(false) {

  if (empty()) {
    throw StackEmptyException("Pop from empty stack");
  }

  S.removeFront();
  numElem--;
}

template <typename E> void LinkedStack<E>::print() {

  LinkedStack<E> p;
  while(!S.empty()){
    p.push(top());
    std::cout << top() << " ";
    pop();
  }

  while(!p.empty()){
    push(p.top());
    p.pop();
  }

  std::cout << std::endl;

}

template <typename E> void LinkedStack<E>:: clearStack(){

if (empty()){
  return;
}
else{
  pop();
  clearStack();
}
}

#endif
