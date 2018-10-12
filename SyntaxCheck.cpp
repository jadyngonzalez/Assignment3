#include <iostream>
#include<fstream>
#include "SyntaxCheck.h"

using namespace std;

SyntaxCheck::SyntaxCheck() //default
{
  fileName = "source.txt";
  if(!ifstream(fileName))
  {
    cerr << "Invalid argument." << endl;
  }
  check();
}

SyntaxCheck::SyntaxCheck(string fileName) //Overloaded constructor
{
  this->fileName = fileName;
  if(!ifstream(fileName))
  {
    cerr << "Invalid argument.";
  }
  check(); //checks syntax
}

SyntaxCheck::~SyntaxCheck()
{

}

void SyntaxCheck::check()
{
  string line = ""; //string to hold line of file
  counter = 1; //line counter

  while(true)
  {
    ifstream readFile(fileName);
    while(getline(readFile, line))
    {
      for(int i = 0; i < line.length(); ++i) //going through each character in the line
      {
        if(line[i] == '/' && line[i+1] == '/') //if double '//' is found breaks to the next line
        {
          break;
        }
        if(line[i] == '[' || line[i] == '{' || line[i] == '(' || line[i] == ']' || line[i] == '}' || line[i] == ')')//checking for delimiters
        {
          if ((line[i] == '(') || (line[i] == '[') || (line[i] == '{'))//if opening push onto stack
          {
            delimiters.push(line[i]);
          }
          else if ((delimiters.peek() == '(') && (line[i] == ')')) //peeks top if match found pops it
          {
            delimiters.pop();
          }
          else if ((delimiters.peek() == '[') && (line[i] == ']'))//peeks top if match found pops it
          {
            delimiters.pop();
          }
          else if ((delimiters.peek() == '{') && (line[i] == '}'))//peeks top if match found pops it
          {
            delimiters.pop();
          }
          else if ((delimiters.peek() == '(') && (line[i] == ']' || line[i] == '}'))  //match not found return error
          {
            cout << "Invalid syntax at line " << counter << ": ')' expected. '" << endl;
          }
          else if ((delimiters.peek() == '[') && (line[i] == ')' || line[i] == '}')) //match not found return error
          {
            cout << "Invalid syntax at line " << counter << ": ']' expected. '" << endl;
          }
          else if ((delimiters.peek() == '{') && (line[i] == ']' || line[i] == ')')) //match not found return error
          {
            cout << "Invalid syntax at line " << counter << ": '}' expected. '" << endl;
          }
        }
      }
      ++counter;
    }
    if(!delimiters.isEmpty()) //error for reaching end of file but stack is not empty
    {
      cout << "Invalid syntax. Found " << delimiters.pop() << " without a closing statement on line " << counter << endl;
      exit(0);
    }

    cout << "This file has correct syntax." << endl;
    cout << "Would you like to check another file?" << endl;
    cout << "Enter (Y)es or (N)o." << endl;
    char input;
    cin >> input;
    if(input == 'Y')
    {
      cont();
    }
    else if(input == 'N')
    {
      cout << "Exiting.";
      break;
    }
    else
    {
      cout << "Imvalid input. Exiting.";
      break;
    }
  }
}

void SyntaxCheck::cont() //continues if user enters 'Y'
{
  cout << "Enter the next file name:" << endl;
  string next;
  cin >> next;
  if(!ifstream(next))
  {
    cerr << "Invalid argument.";
  }
  this->fileName = next;
  counter = 1;
}
