// curator.cpp
// An implemented curator class used to help facilitate a syntax checker program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "curator.h"

using namespace std;

// Default constructor
Curator::Curator()
{
  m_single_line = "";
  m_single_line_cleaned = "";
  m_entire_file_read = "";
  Checker m_checker;
  m_delimeter_index = 0;
  m_current_line_number = 1;
  m_error_line_number = 1;
}

// Destructor
Curator::~Curator()
{

}

// Checker accessor
Checker Curator::getChecker()
{
  return m_checker;
}

// Checker mutator (resets checker)
void Curator::setChecker()
{
  Checker m_checker;
}

void Curator::Curate(string fileName)
{
  m_input_stream.open(fileName);
  // This if/else statement is used to catch any files that do not exist. If this isn't here, then the program will enter
  // an infinte loop and fail.
  if (m_input_stream.fail())
  {
    cout << "File does not exist!" << endl;
  }
  else
  {
    // The while loop while run as long as a source code file has not been completely read.
    while(getline(m_input_stream, m_single_line))
    {
      // Here, I loop through each line to find our delimeters
      for (int i = 0; i < m_single_line.size(); ++i)
      {
        // These boolean expressions will add a symbol to our delimeter sequence iff it is a delimeter. Else, we will continue.
        if (m_single_line.at(i) == '[')
        {
          m_single_line_cleaned += '[';
        }
        else if (m_single_line.at(i) == ']')
        {
          m_single_line_cleaned += ']';
        }
        else if (m_single_line.at(i) == '{')
        {
          m_single_line_cleaned += '{';
        }
        else if (m_single_line.at(i) == '}')
        {
          m_single_line_cleaned += '}';
        }
        else if (m_single_line.at(i) == '(')
        {
          m_single_line_cleaned += '(';
        }
        else if (m_single_line.at(i) == ')')
        {
          m_single_line_cleaned += ')';
        }
        // If a symbol is not a delimeter, then the character is skipped.
        else
        {
          continue;
        }
      }
      // We will add the delimeters from each line to our delimeter sequence here.
      m_entire_file_read += (m_single_line_cleaned);
      // We reset the single line for each line.
      m_single_line_cleaned = "";
    }
    m_input_stream.close();
    // This will only happen if there was no error - therefore no need to give them any details about an error
    if (m_checker.Check(m_entire_file_read))
    {
      cout << m_checker.getStatusMessage() << endl;
    }
    // If there was a delimeter error, we go down this path.
    else
    {
      // We will first give them the error message.
      cout << m_checker.getStatusMessage() << endl;
      // Now, we will find the error using our delimeter sequence.
      m_delimeter_sequence = m_checker.getPriorSequence();
      m_input_stream.open(fileName);
      // This if/else statement is used to catch any files that do not exist. If this isn't here, then the program will enter
      // an infinte loop and fail.
      if (m_input_stream.fail())
      {
      }
      else
      {
        // The while loop while run as long as the file has not been completely read.
        while(getline(m_input_stream, m_single_line))
        {
          // We go through each line in the file, just like before.
          for (int i = 0; i < m_single_line.size(); ++i)
          {
            // In this boolean expression, we update our error line. The error line is updated only if it has one of our delimeter symbols.
            // We then increase the index and look for the next delimeter symbol.
            if (m_single_line.at(i) == m_delimeter_sequence.at(m_delimeter_index) && m_delimeter_index != (m_delimeter_sequence.size() - 1))
            {
              m_delimeter_index++;
              m_error_line_number = m_current_line_number;
            }
            // In this boolean expression, we update the line to be that of the symbol before the error.
            else if (m_single_line.at(i) == m_delimeter_sequence.at(m_delimeter_index) && m_delimeter_index == (m_delimeter_sequence.size() - 1))
            {
              m_error_line_number = m_current_line_number;
            }
            // If it's not a delimeter in our sequence, then we keep looking
            else
            {
              continue;
            }
          }
          // The curent line number must be increased for each line.
          m_current_line_number++;
        }
      m_input_stream.close();
      // In the end, we will give them the line.
      cout << "Line where error may lie: " << m_error_line_number << endl;
    }
  }
}
}
