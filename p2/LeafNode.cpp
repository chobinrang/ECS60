#include <iostream>
#include <climits>
#include "LeafNode.h"
#include "InternalNode.h"
#include "QueueAr.h"

using namespace std;


LeafNode::LeafNode(int LSize, InternalNode *p,
  BTreeNode *left, BTreeNode *right) : BTreeNode(LSize, p, left, right)
{
  values = new int[LSize];
}  // LeafNode()

void LeafNode::addToLeft(int value, int last)
{
  leftSibling->insert(values[0]);

  for(int i = 0; i < count - 1; i++)
    values[i] = values[i + 1];

  values[count - 1] = last;
  if(parent)
    parent->resetMinimum(this);
} // LeafNode::ToLeft()

void LeafNode::addToRight(int value, int last)
{
  rightSibling->insert(last);

  if(value == values[0] && parent)
    parent->resetMinimum(this);
} // LeafNode::addToRight()

void LeafNode::addToThis(int value)
{
  int i;

  for(i = count - 1; i >= 0 && values[i] > value; i--)
      values[i + 1] = values[i];

  values[i + 1] = value;
  count++;

  if(value == values[0] && parent)
    parent->resetMinimum(this);
} // LeafNode::addToThis()


void LeafNode::addValue(int value, int &last)
{
  int i;

  if(value > values[count - 1])
    last = value;
  else
  {
    last = values[count - 1];

    for(i = count - 2; i >= 0 && values[i] > value; i--)
      values[i + 1] = values[i];
    // i may end up at -1
    values[i + 1] = value;
  }
} // LeafNode:: addValue()


int LeafNode::getMaximum()const
{
  if(count > 0)  // should always be the case
    return values[count - 1];
  else
    return INT_MAX;
} // getMaximum()


int LeafNode::getMinimum()const
{
  if(count > 0)  // should always be the case
    return values[0];
  else
    return 0;

} // LeafNode::getMinimum()


LeafNode* LeafNode::insert(int value)
{
  int last;

  if(count < leafSize)
  {
    addToThis(value);
    return NULL;
  } // if room for value

  addValue(value, last);

  if(leftSibling && leftSibling->getCount() < leafSize)
  {
    addToLeft(value, last);
    return NULL;
  }
  else // left sibling full or non-existent
    if(rightSibling && rightSibling->getCount() < leafSize)
    {
      addToRight(value, last);
      return NULL;
    }
    else // both siblings full or non-existent
      return split(value, last);
}  // LeafNode::insert()

void LeafNode::print(Queue <BTreeNode*> &queue)
{

  cout << "Leaf: ";
  for (int i = 0; i < count; i++)
    cout << values[i] << ' ';
  cout << endl;


} // LeafNode::print()


LeafNode* LeafNode::remove(int value)
{   // To be written by students

//make changes for the error.txxt files
int zero_location;
bool check = false;

  for(int i = 0; i < count; i++){
    if (values[i] == value){
      values[i] = 0;
      zero_location = i;
  check = true;
   //   break; 
    }
    //if (i == (count - 1)){
      //return NULL;
    //}
  }

if (check == true)
{
  for(int j = zero_location; j < (count -1); j++ ){
    values[j] = values[j+1];
  }
  count = count - 1;
  if (parent){
    parent->resetMinimum(this);
  }
}

  if (count < (leafSize+1)/2 && parent != NULL) {
    //borrow from left sibling
    if(leftSibling){ //If Left sibling is there 
       if((leftSibling->getCount())-1 < (leafSize+1)/2){
        return MergeLeft();
   
       }
       else{
        int max = leftSibling->getMaximum();
        leftSibling->remove(max);
        this->insert(max);
       }
     } 
    else if(rightSibling){
        if((rightSibling->getCount()-1) < (leafSize+1)/2)
        { 
          return MergeRight();
        } 
        else{
          int min = rightSibling->getMinimum();
          rightSibling->remove(min);
          this->insert(min);
        }
    }
  }
 
  return NULL;  // filler for stub
}  // LeafNode::remove()

LeafNode* LeafNode::MergeLeft(){
  if (count != 0){
    int temp_val = getMinimum();
    this->remove(temp_val);
    leftSibling->insert(temp_val);
    leftSibling->setRightSibling(rightSibling);
  }
  if(parent){
    parent->resetMinimum(this);
  }
  return this;
}

LeafNode* LeafNode::MergeRight(){
  if (count != 0){
    int temp_val = getMinimum();
    this->remove(temp_val);
    rightSibling->insert(temp_val);
    rightSibling->setLeftSibling(leftSibling);
  }
  if(parent){
    parent->resetMinimum(this);
  }
  return this;
}


LeafNode* LeafNode::split(int value, int last)
{
  LeafNode *ptr = new LeafNode(leafSize, parent, this, rightSibling);


  if(rightSibling)
    rightSibling->setLeftSibling(ptr);

  rightSibling = ptr;

  for(int i = (leafSize + 1) / 2; i < leafSize; i++)
    ptr->values[ptr->count++] = values[i];

  ptr->values[ptr->count++] = last;
  count = (leafSize + 1) / 2;

  if(value == values[0] && parent)
    parent->resetMinimum(this);
  return ptr;
} // LeafNode::split()