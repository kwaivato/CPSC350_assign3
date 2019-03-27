// GenStack.cpp
// A declared generic class for an array-based stack of any type.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include <iostream>
#include "StackEmpty.cpp"

using namespace std;

template <typename E>
class GenStack
{
  public:
    // Default constructor
    GenStack();
    // Overloaded constructor
    GenStack(int maxSize);
    // Destructor
    ~GenStack();

    // Functions
    void push(const E& e);
    E& pop() throw (StackEmpty);
    const E& peek() throw (StackEmpty); // aka top

    int getSize();
    bool isEmpty();
    bool isFull();
    void resize();

    // Not member variables, so no need to make private
    int size;
    int top;

    // Pointer is used for the array
    E* myArray;

};
