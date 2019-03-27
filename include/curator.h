// curator.h
// A declared curator class used to help facilitate a syntax checker program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "checker.h"

using namespace std;

class Curator
{
  public:
    // Constructor
    Curator();
    // Destructor
    ~Curator();
    // The checker class will be used to check errors in our file
    Checker getChecker();
    // Method needed to reset our checker
    void setChecker();
    // The Curate function will be used to curate our file, give it to the checker, and return any errors
    void Curate(string fileName);
  private:
    // Input stream to read file
    ifstream m_input_stream;
    // The m_single_line variable is used to hold a string for each line in a given source code file.
    string m_single_line;
    // The m_single_line_cleaned variable is used to hold a 'cleaned' string for each line in a given source code file, where
    // cleaned is defined keeping only the symbols we need to check.
    string m_single_line_cleaned;
    // The m_entire_file_read variable is a long string that holds all of a source code's symbols.
    string m_entire_file_read;
    // Checker to check errors
    Checker m_checker;

    //Error finding variables
    // Used to store the sequence of delimeters that resulted in an error. This is retrieved from our Checker
    string m_delimeter_sequence;
    // Used to store the index of the current delimeter we're searching for. This will be used to tell us the line where the error may be
    int m_delimeter_index;
    // Used to keep track of the current line we're on
    int m_current_line_number;
    // Used to keep track of the line with the error
    int m_error_line_number;
};
