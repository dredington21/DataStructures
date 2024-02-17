#ifndef STACK_EMPTY_EXCEPTION
#define STACK_EMPTY_EXCEPTION

#include "RuntimeException.h"
#include <string>

class StackEmptyException : public RuntimeException {
public:
  StackEmptyException(const std::string &err) : RuntimeException(err) {}
};

#endif