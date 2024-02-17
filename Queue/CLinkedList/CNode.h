#ifndef CNODE
#define CNODE
// Node class using template parameters
template <typename E> class CNode {
private:
  E elem; // data element 
  CNode<E> *next; // next pointer

public:
  CNode(){}; // default constructor
  
  // Friend class for private access
  template <typename U> friend class CLinkedList;
};

#endif