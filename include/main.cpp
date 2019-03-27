// main.cpp
// A main program used to run a public interface of a syntax checker program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "Menu.h"

using namespace std;

// Main method for the entire program.
int main(int argc, char** argv)
{
  Menu syntax_menu;
  syntax_menu.Run(argv[1]);
  return 0;
}
