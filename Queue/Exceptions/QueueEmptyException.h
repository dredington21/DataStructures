#ifndef QUEUE_EMPTY_EXCEPTION
#define QUEUE_EMPTY_EXCEPTION

#include "RuntimeException.h"
#include <string>

class QueueEmptyException : public RuntimeException {
public:
  QueueEmptyException(const std::string &err) : RuntimeException(err) {}
};

#endif