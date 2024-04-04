#ifndef INDEX_OUT_OF_BOUNDS
#define INDEX_OUT_OF_BOUNDS

#include <string>
#include "RuntimeException.h"

class IndexOutOfBounds : public RuntimeException {
public:
  IndexOutOfBounds(const std::string &err) : RuntimeException(err) {}
};

#endif