#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
class Tree
{
  T info;
  char character;
  Tree<T> *Left;
  Tree<T> *Right;

  public:
    Tree(T p, T *leftNode, T *rightNode);
    Tree(T &i, char c, Tree<T> *leftNode, Tree<T> *rightNode);
    void print(char *cpoint, int count);
    T& getInfo();
};

template <class T>
Tree<T>::Tree(T &i, char c, Tree<T> *leftNode, Tree<T> *rightNode)
{	
  info = i;
  character = c;
  Left = leftNode;
  Right = rightNode;
}

template <class T>
void Tree<T>::print( char *cpoint, int count)
{
  int dummy;
  char zero = '0';
  char one = '1';

  if(Left)
  {
    dummy = 1;
  }
  if (Right)
  {
    dummy = 2;
  }

  switch(dummy)
  {
    case 1:
          //char zero = '0';
      cpoint[count] = zero;
      Left->print(cpoint, count + 1);
      break;
    case 2:
          //char one = '1';
    cpoint[count] = one;
    Right->print(cpoint, count + 1);
    break;

  }



if (!Left && !Right)
  {
    cout << character << " " << setw(4) << fixed << info << " ";
    for (int j = 0; j < count; j++)
    {
      cout << cpoint[j];
    } 
    cout << '\n';
  }
}

template <class T>
T& Tree<T>::getInfo()
{
  return info;
}

#endif