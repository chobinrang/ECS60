#include <iostream>
#include <fstream>
#include "BinaryHeap.h"
#include "BinaryTree.h"

using namespace std;

class BinaryTreePtr
{
	public:
		Tree<int>* Node = NULL;
		int frequency;
		char character;


		BinaryTreePtr()
		{
	
		} //default constructor



		BinaryTreePtr(char c, int freq)
		{
			Node = new Tree<int>(freq, c, NULL, NULL);
			character = c;
			frequency = freq;
		}

		BinaryTreePtr(char c, int freq, Tree<int>* left, Tree<int>* right)
		{
			character = c;
			frequency = freq;
			Node = new Tree<int>( frequency, character, left, right);
		}

		bool operator<(const BinaryTreePtr& p) const 
		{return Node->getInfo() < p.Node->getInfo();}


};


//need this to compare two BinaryTreePtr Objects
//bool BinaryTreePtr::operator<(const BinaryTreePtr& b) const
//{
//	return frequency < b.frequency;
//}
int main(int argc, char** argv)
{
	ifstream inf(argv[1]);
	char character;
	//BinaryTreePtr p;
	int ascii[256] = {};
	int temp[256];
	int counter = 0;
	BinaryHeap <BinaryTreePtr> heap; //not sure what size

	while (inf.get(character)) //reads each character as char
	{
		
		int num_char = (int)character; //casts char into int
		
		ascii[num_char]++; //increments array based on asci

	}

	for (int j = 0; j < 256; j++)
	{
		if (ascii[j] != 0)
		{
			
			int freq = ascii[j];
			heap.insert(BinaryTreePtr((char)j,ascii[j]));
		}
	}

	while(!heap.isEmpty())
	{
		BinaryTreePtr min_1;
		heap.deleteMin(min_1);
		//cout << (char)min_1.asci_value << min_1.frequency << endl;
		if (heap.isEmpty())
		{
			heap.insert(min_1);
			break;
		}
		else
		{
			
			BinaryTreePtr min_2;
			heap.deleteMin(min_2);
		//	cout << (char)min_2.asci_value << min_2.frequency << endl;
			BinaryTreePtr parent;
			int temp_freq = min_1.Node->getInfo() + min_2.Node->getInfo();
			char temp_char = 'Y';
			BinaryTreePtr Parent(temp_char, temp_freq, min_1.Node, min_2.Node);
			heap.insert(Parent);
		}
	}
	char* random = new char[500]();
	int i = 0;
	BinaryTreePtr last;
	heap.deleteMin(last);
	last.Node->print(random, i);
}
