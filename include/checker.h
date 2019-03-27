// checker.h
// A declared checker class used to check errors in a syntax checker program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include <fstream>
#include "GenStack.cpp"

using namespace std;

class Checker
{
  public:
    // Constructor
    Checker();
    // Destructor
    ~Checker();
    // This checks whether the sequence of delimeters from the file (which is given to us by the curator class) is valid
    bool Check(string symbolSequence);
    // This is an accessor for the sequence of symbols before we encounter an error
    string getPriorSequence();
    // This is an accessor for the status message associated with a given error (or if the delimeter sequence is valid)
    string getStatusMessage();
  private:
    // Used to store the sequence of symbols before we encounter an error
    string m_prior_sequence;
    // Used to store the status message associated with a given error (or if the delimeter sequence is valid)
    string m_status_message;
};
