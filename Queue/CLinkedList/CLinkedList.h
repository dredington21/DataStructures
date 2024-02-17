#ifndef CLINKEDLIST
#define CLINKEDLIST

#include "CNode.h"
#include <iostream>

// CircleList Linked List using a templated class
template <typename E> class CLinkedList {
public:
  // Default constructor, initializes cursor pointer to NULL
  CLinkedList() : cursor(nullptr) {}

  // Destructor, removes all nodes from the list
  ~CLinkedList();

  // Returns whether the list is empty or not
  bool empty() const { return cursor == nullptr; }

  // Returns the element at following the cursor
  const E &front() const { return cursor->next->elem; }

  // Returns the element at the cursor
  const E &back() const { return cursor->elem; }

  // Moves the cursor to the next element in the list
  void advance() { cursor = cursor->next; }

  // Adds a new node to the list after the cursor
  void add(const E p);

  // Removes the node after the cursor
  void remove();

private:
  CNode<E> *cursor; // current node in the list
};

template <typename E> CLinkedList<E>::~CLinkedList() {
  while (!empty())
    remove();
}

template <typename E> void CLinkedList<E>::add(const E p) {
  CNode<E> *v = new CNode<E>;
  v->elem = p;
  if (cursor == nullptr) { // if the list is empty, insert the new node as the
                           // only node in the list
    v->next = v;
    cursor = v;
  } else { // otherwise, insert the new node after the cursor
    v->next = cursor->next;
    cursor->next = v;
  }
};

template <typename E> void CLinkedList<E>::remove() {
  CNode<E> *old = cursor->next;
  if (old == cursor) { // if the list only has one node, set the cursor to NULL
    cursor = nullptr;
  } else { // otherwise, remove the node and update the cursor
    cursor->next = old->next;
  }
  delete old;
}

#endif