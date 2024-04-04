#ifndef LBINARYTREE
#define LBINARYTREE

#include <iostream>
#include <list>

template <typename E> class LinkedBinaryTree {

protected:
  struct Node {
    E elem;
    Node *parent;
    Node *left;
    Node *right;
    Node() : elem(), parent(nullptr), left(nullptr), right(nullptr) {}
  };

public:
  class Position {
  public:
    Position(Node *v = nullptr) : v(v) {}

    E &operator*() { return v->elem; }
    Position left() const { return Position(v->left); }
    Position right() const { return Position(v->right); }
    Position parent() const { return Position(v->parent); }
    bool isRoot() const { return v->parent == nullptr; }
    bool isExteral() const {
      return (v->left == nullptr && v->right == nullptr);
    }

    friend class LinkedBinaryTree;

  private:
    Node *v;
  };

  typedef std::list<Position> PositionList;

  LinkedBinaryTree() : _root(nullptr), n(0) {}
  ~LinkedBinaryTree();

  int size() const { return n; }
  bool empty() const { return n == 0; }
  Position root() const { return Position(_root); }
  void addRoot();
  void expandExternal(const Position &p);
  PositionList positions() const;
  void print() const;

protected:
  void preorder(Node *v, PositionList *pl) const;
  void inorder(Node *v, PositionList *pl) const;

  void preorderPrint(Node *v) const;
  void inorderPrint(Node *v) const;

  void postOrderDelete(Node *v);

private:
  Node *_root;
  int n;
};

template <typename E> void LinkedBinaryTree<E>::addRoot() {
  _root = new Node;
  n = 1;
}

template <typename E>
void LinkedBinaryTree<E>::expandExternal(const Position &p) {
  Node *v = p.v;
  v->left = new Node;
  v->left->parent = v;

  v->right = new Node;
  v->right->parent = v;

  n += 2;
}

template <typename E>
typename LinkedBinaryTree<E>::PositionList
LinkedBinaryTree<E>::positions() const {
  PositionList pl;
  preorder(_root, pl);
  return PositionList(pl);
}

template <typename E>
void LinkedBinaryTree<E>::inorder(Node *v, PositionList *pl) const {
  if (v->left != NULL) {
    inorder(v->left, pl);
  }

  pl->push_back(Position(v));
  if (v->right != NULL) {
    inorder(v->right, pl);
  }
}

template <typename E>
void LinkedBinaryTree<E>::preorder(Node *v, PositionList *pl) const {

  pl->push_back(Position(v));

  if (v->left != NULL) {
    inorder(v->left, pl);
  }

  if (v->right != NULL) {
    inorder(v->right, pl);
  }
}

template <typename E> void LinkedBinaryTree<E>::preorderPrint(Node *v) const {

  std::cout << v->elem << " ";
  
  if (v->left != NULL) {
    preorderPrint(v->left);
  }

  if (v->right != NULL) {
    preorderPrint(v->right);
  }
}


template <typename E> void LinkedBinaryTree<E>::inorderPrint(Node *v) const {
  
  if (v->left != NULL) {
    inorderPrint(v->left);
  }

  std::cout << v->elem << " ";

  if (v->right != NULL) {
    inorderPrint(v->right);
  }
}

template <typename E> void LinkedBinaryTree<E>::print() const {
  preorderPrint(_root);
  std::cout << std::endl;
}

template <typename E> LinkedBinaryTree<E>::~LinkedBinaryTree() {
  postOrderDelete(_root);
}

template <typename E> void LinkedBinaryTree<E>::postOrderDelete(Node *v) {
  if (v->left != NULL) {
    postOrderDelete(v->left);
  }
  if (v->right != NULL) {
    postOrderDelete(v->right);
  }

  n = 0;
  delete v;
}

#endif