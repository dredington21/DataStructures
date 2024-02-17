#include "Exceptions/DequeEmptyException.h"
#include "LinkedDeque.h"
#include <iostream>
#include <string>

int main() {
  LinkedDeque<std::string> *names = new LinkedDeque<std::string>;

  names->insertFront("Mike");
  names->insertBack("Harvy");

  //names->print();

  names->insertFront("Donna");

  names->insertBack("Rachel");

  names->print();

  names->removeFront();

  names->print();

  names->removeBack();

  names->print();

  names->removeBack();
  names->removeBack();

  try {
    names->removeBack();
  } catch (DequeEmptyException e) {
    std::cout << e.getMessgae() << std::endl;
  }

  try {
    names->removeFront();
  } catch (DequeEmptyException e) {
    std::cout << e.getMessgae() << std::endl;
  }

  try {
    names->back();
  } catch (DequeEmptyException e) {
    std::cout << e.getMessgae() << std::endl;
  }

  try {
    names->front();
  } catch (DequeEmptyException e) {
    std::cout << e.getMessgae() << std::endl;
  }

  return 0;
}