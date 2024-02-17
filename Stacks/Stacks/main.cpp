#include "Exceptions/StackEmptyException.h"
#include "LinkedStack.h"
#include <iostream>
#include <string>

int main() {
  LinkedStack<std::string> *names = new LinkedStack<std::string>;

  names->push("Rachel");
  names->push("Monica");
  names->push("Rebecca");

  names->print();
 

 names->clearStack();
 names->push("Jamal");
 names->print();



  std::cout << "test";

}
