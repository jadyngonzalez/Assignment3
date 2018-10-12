#include <iostream>
#include "GenStack.h"
using namespace std;

class SyntaxCheck
{
  public:
    SyntaxCheck();
    ~SyntaxCheck();
    SyntaxCheck(string);

    void check();
  private:
    GenStack<char> delimiters;
    string fileName;
    int counter;

    void cont();
};
