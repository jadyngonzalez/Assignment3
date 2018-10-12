#include <iostream>
#include <fstream>
#include <string>
#include "SyntaxCheck.h"

using namespace std;

int main(int argc, char* argv[])
{
  if(argc == 1) //checking for command line arguments
  {
    cerr << "File not included.";
    exit(0);
  }
  if(argc > 2)
  {
    cerr << "Too many arguments entered.";
    exit(0);
  }
  else
  {
    SyntaxCheck run(argv[1]);
  }
  return 0;
}
