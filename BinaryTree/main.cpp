#include "LBinaryTree.h"
#include <iostream>
#include <string>
#include <list>



int main(){

    LinkedBinaryTree<std::string> *names = new LinkedBinaryTree<std::string>;

    names->addRoot();

    LinkedBinaryTree<std::string>::Position p;
    LinkedBinaryTree<std::string>::Position root;
    root = names->root();
    *root = "Tony";

    names->expandExternal(root);
    p = root.left();

    *p = "Happy";

    *root.right() = "Pepper";

    names->print();

    delete names;


    return 0;
}