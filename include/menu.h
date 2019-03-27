// menu.h
// A declared menu interface used to facilitate a syntax checker program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "curator.h"

using namespace std;

// Allows a user to continuously enter source code files. Must use with curator, checker, and GenStack classes.
class Menu
{
  public:
    Menu();
    ~Menu();
    // The Run method is the user-friendly interface used for a delimeter checker interface.
    void Run(string file_name); // this method is going to start a menu and close it once the user is done based on the user's choice
  private:
    string m_choice;
    string m_file_name;
    Curator m_curator;
};
