#include <iostream>
#include <cstdlib>
#define d 10 //default size of stack is 10;

using namespace std;

template<class T> class GenStack
{
  public:
    GenStack(int = d);                //default constructor
    ~GenStack() {delete [] values;}   //destructor

    bool push(T);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
  private:
    int size;
    T *values;
    int top;
};

template<class T> GenStack<T>::GenStack(int s):   //overloaded constructor for stack
  size(s),
  values(new T[size]),
  top(-1)
  {}

template<class T> bool GenStack<T>::isFull() //checking if full
{
  if((top + 1) == size) //if top of stack = size then stack is full
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

template<class T> bool GenStack<T>::isEmpty() //checking if empty
{
  if(top == -1) //if top of stack is -1 then stack is empty
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

template<class T> bool GenStack<T>::push(T val) //add element to stack
{
  bool success = 0;
  if(!GenStack<T>::isFull()) //check if full first
  {
    ++top;
    values[top] = val; //if not full top moves up and adds element
    success = 1;
  }
  else //if stack full then create a new stack twice as big
  {
    T *newValues;
    newValues = new T[size * 2];
    for(int i = 0; i < size; ++i) //with new stack adding previous values into new stack
    {
      newValues[i] = values[i];
    }
    values = newValues;
    values[++top] = val; //pusing onto new stack
    success = 1;
  }
  return success; //success
}

template<class T> T GenStack<T>::pop() //remove and return element of stack
{
  T val = -1;
  if(!GenStack<T>::isEmpty()) //check if empty first
  {
    val = values[top];//if not empty set our temp = to the value at top then decrease top by 1
    --top;
  }
  else
  {
    cerr << "Stack Empty!" << endl; //if stack is empty throw an error
  }
  return val;
}

template<class T> T GenStack<T>::peek()//return the top of the stack
{
  if(!GenStack<T>::isEmpty()) //if not empty returns top of the stack
  {
    return values[top];
  }
  else
  {
    cerr << "Cannot peek an empty Stack!" << endl; //return error if empty
  }
}
