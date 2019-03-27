// StackEmpty.cpp
// An error class used to handle cases of an empty stack.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include <string>
#include <iostream>
#include "RuntimeException.cpp"

using namespace std;

// Implements the RuntimeException class
class StackEmpty : public RuntimeException {
  public:
    StackEmpty(const string& err) : RuntimeException(err) {}
};
