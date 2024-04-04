#include "ArrayVector.h"
#include "Exceptions/IndexOutOfBounds.h"
#include <iostream>
#include <ostream>
#include <vector>

int main() {

  ArrayVector<std::string> *names = new ArrayVector<std::string>;

  names->insert(0, "Dano");
  names->insert(1, "Steve");
  names->print();
  names->insert(1, "Kono");
  names->print();

  for (int i = 0; i < names->size(); i++) {
    std::cout << names->at(i) << " ";
  }
  std::cout << std::endl;

  try {
    std::cout << names->at(4) << std::endl;
  } catch (IndexOutOfBounds e) {
    std::cout << e.getMessage() << std::endl;
  }

}