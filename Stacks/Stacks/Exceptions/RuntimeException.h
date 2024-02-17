#ifndef RUNTIME_EXCEPTION
#define RUNTIME_EXCEPTION

#include <string>

class RuntimeException {
  std::string errorMsg;

public:
  RuntimeException(const std::string &err) { errorMsg = err; }
  std::string getMessage() const { return errorMsg; }
};

#endif