#include "Exceptions/QueueEmptyException.h"
#include "LinkedQueue.h"
#include <iostream>
#include <string>

int main(){
  LinkedQueue<std::string> *names = new LinkedQueue<std::string>;

  names ->enqueue ("Michael");
  names ->enqueue ("Jerry");

  names->print();

  names->dequeue();

  names->print();
}