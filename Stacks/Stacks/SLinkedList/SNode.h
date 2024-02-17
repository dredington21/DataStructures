#ifndef SNODE
#define SNODE

template <typename E> class SNode {
public:
  SNode(){}

private:
  E elem;
  SNode<E> *next;

  template <typename T> friend class SLinkedList;
};

#endif