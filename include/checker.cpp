// checker.cpp
// An implemented checker class used to check errors in a syntax checker program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "checker.h"

using namespace std;

// Just need to initiate the strings in this constructor
Checker::Checker()
{
  m_prior_sequence = "";
  m_status_message = "";
}

Checker::~Checker()
{

}

//This function is used to read a file and determine any errors in it (if any). It is adapted from the algorithm in the book.
bool Checker::Check(string symbolSequence)
{
  // A stack of characters is created to handle all the delimeters
  GenStack<char> scanStack(symbolSequence.size());
  // I am going to go through the sequence given by the curator to check the delimeter validity
  for (int i = 0; i < symbolSequence.size(); ++i)
  {
    // This prior sequence string will capture delimeters to help us locate errors
    m_prior_sequence += symbolSequence.at(i);
    // If it is a starting sequence we can push it on the stack
    if (symbolSequence.at(i) == '(' || symbolSequence.at(i) == '[' || symbolSequence.at(i) == '{')
    {
      scanStack.push(symbolSequence.at(i));
    }
    // If it is an ending delimeter we want to check that it matches with our starting delimeter on the stack
    else if (symbolSequence.at(i) == ')' || symbolSequence.at(i) == ']' || symbolSequence.at(i) == '}')
    {
      // This is the error that occurs if we do not have anything on the stak. This suggests that we need an extra previous symbol
      // I customize it for each ending delimeter using boolean exprressions
      if (scanStack.isEmpty())
      {
        if (symbolSequence.at(i) == ')')
        {
          m_status_message = "MISSING SYMBOL ERROR\nIt looks like you are missing a '(' symbol for your ')' symbol.";
          return false;
        }
        else if (symbolSequence.at(i) == ']')
        {
          m_status_message = "MISSING SYMBOL ERROR\nIt looks like you are missing a '[' symbol for your ']' symbol.";
          return false;
        }
        else if (symbolSequence.at(i) == '}')
        {
          m_status_message = "MISSING SYMBOL ERROR\nIt looks like you are missing a '{' symbol for your '}' symbol.";
          return false;
        }
      }

      // These are 'wrong type' errors. I will customize it for each ending delimeter to make recommendations for how to modify it
      // and fix the error.
      if (scanStack.peek() != '(' && symbolSequence.at(i) == ')' )
      {
        if (scanStack.peek() == '[')
        {
          m_status_message = "MISMATCH ERROR\nIt looks like you accidentally put a ')' instead of a ']', or conversely a '[' instead of a '('.";
          return false;
        }
        else if (scanStack.peek() == '{')
        {
          m_status_message = "MISMATCH ERROR\nIt looks like you accidentally put a ')' instead of a '}', or conversely a '{' instead of a '('.";
          return false;
        }
      }
      if (scanStack.peek() != '[' && symbolSequence.at(i) == ']' )
      {
        if (scanStack.peek() == '{')
        {
          m_status_message = "MISMATCH ERROR\nIt looks like you accidentally put a ']' instead of a '}', or conversely a '{' instead of a '['.";
          return false;
        }
        else if (scanStack.peek() == '(')
        {
          m_status_message = "MISMATCH ERROR\nIt looks like you accidentally put a ']' instead of a ')', or conversely a '(' instead of a '['.";
          return false;
        }
      }
      if (scanStack.peek() != '{' && symbolSequence.at(i) == '}' )
      {
        if (scanStack.peek() == '(')
        {
          m_status_message = "MISMATCH ERROR\nIt looks like you accidentally put a '}' instead of a ')', or conversely a '(' instead of a '{'.";
          return false;
        }
        else if (scanStack.peek() == '[')
        {
          m_status_message = "MISMATCH ERROR\nIt looks like you accidentally put a '}' instead of a ']', or conversely a '[' instead of a '{'.";
          return false;
        }
      }
      // The element must be popped if it made it through - this means that it was valid
      scanStack.pop();
    }
  }
  // If the stack is empty at the end, then we had a valid sequence!
  if (scanStack.isEmpty())
  {
    m_status_message = "It looks like all your delimeters matched, so you're good to go! Your delimeter stucture looks great.";
    return true;
  }
  // If anything else is funny, it ends up here. This takes care of any random/weird cases.
  else
  {
    m_status_message = "UNMATCH ERROR\nIt looks like some symbols never matched.";
    return false;
  }
}

// Prior sequence accessor
string Checker::getPriorSequence()
{
  return m_prior_sequence;
}


// Status message accessor
string Checker::getStatusMessage()
{
  return m_status_message;
}
