// GenStack.cpp
// An implemented generic class for an array-based stack of any type.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "GenStack.h"

using namespace std;

// Default constructor
template <typename E> GenStack<E>::GenStack()
{
  myArray = new E[128]; //128 bytes
  size = 128;
  top = -1;
}

// Overloaded constructor
template <typename E> GenStack<E>::GenStack(int maxSize)
{
  myArray = new E[maxSize];
  size = maxSize;
  top = -1;
}

// Destructor
template <typename E> GenStack<E>::~GenStack()
{
  // Need to delete myArray because it was dynamically allocated
  delete[] myArray;
}

template <typename E> void GenStack<E>::push(const E& e)
{
  // Resize method is used instead of throwing isFull exception
  if(isFull())
  {
    resize();
  }
  myArray[++top] = e;
}

template <typename E> E& GenStack<E>::pop() throw (StackEmpty)
{
  if(isEmpty())
  {
    throw StackEmpty("Your stack is empty! No elements to pop.");
  }
  return myArray[top--];
}

template <typename E> const E& GenStack<E>::peek() throw (StackEmpty)
{
  if(isEmpty())
  {
    throw StackEmpty("Your stack is empty! No elements to peek at.");
  }
  return myArray[top];
}

// True of top is the last element in the array
template <typename E> bool GenStack<E>::isFull()
{
  return (top == size - 1);
}

template <typename E> bool GenStack<E>::isEmpty()
{
  return (top == - 1);
}

template <typename E> int GenStack<E>::getSize()
{
  return (top + 1);
}

template <typename E> void GenStack<E>::resize()
{
  // In the resize method, I create a second array and make it double the size of the first array.
  E* myBigArray = new E[size*2];
  // Copying over all elements in the initial array
  for (int i = 0; i < size; ++i)
  {
    myBigArray[i] = myArray[i];
  }
  // Deleting the initial array
  delete[] myArray;
  // Useful for future functions
  size *= 2;
  // myArray is now a  new array with extra space
  myArray = new E[size];
  myArray = myBigArray;
}
