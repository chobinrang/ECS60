#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "CPUTimer.h"
#include "LinkedList.h"
#include "CursorList.h"
#include "StackAr.h"
#include "StackLi.h"
#include "QueueAr.h"
#include "SkipList.h"

vector<CursorNode <int> > cursorSpace(500001);

using namespace std;



//this function will get the choice and return #
int getChoice()
{
	cout << "      ADT Menu" << endl;
	cout << "0. Quit" << endl;
	cout << "1. LinkedList" << endl;
	cout << "2. CursorList" << endl;
	cout << "3. StackAr" << endl;
	cout << "4. StackLi" << endl;
	cout << "5. QueueAr" << endl;
	cout << "6. SkipList" << endl;
	cout << "Your choice >> ";
	//cout << endl;

	int choice;
	cin >> choice;

	return choice;
} //getChoice()


void Runlist(char *filename)
{
	//cin >> filename;


	List<int> list;
	ListItr<int> listItr = list.zeroth();
	ifstream inf(filename);
	char comment, s[512];
	int value;
	inf.getline(s, 512);
	while(inf >> comment >> value)
	{
		if (comment == 'i')
		{
			list.insert(value, listItr);
		}
		else
		{
			list.remove(value);
		}
	}

} //RunList(*filename)

void RunCursorlist(char *filename)
{
	CursorList<int> Cursorlist(cursorSpace);
	CursorListItr<int> CursorlistItr = Cursorlist.zeroth();
	ifstream inf(filename);
	char comment, s[512];
	int value;
	inf.getline(s,512);

	while(inf >> comment >> value)
	{
		if (comment == 'i')
		{
			Cursorlist.insert(value, CursorlistItr);
		}
		else
		{
			Cursorlist.remove(value);
		}
	}
	
}//RunCursorList()

void RunStackAr(char *filename)
{
	StackAr<int> s(500000);
	ifstream inf(filename);
	char comment, yo[512];
	int value;
	inf.getline(yo,512);

	while(inf >> comment >> value)
	{
		if (comment == 'i')
		{
			s.push(value);
		}
		else
		{
			s.pop();
		}

	}
} //RunStackAr()

void RunStackLi(char* filename)
{
	StackLi<int> s;
	ifstream inf(filename);
	char comment, yo[512];
	int value;
	inf.getline(yo,512);

	while(inf >> comment >> value)
	{
		if (comment == 'i')
		{
			s.push(value);
		}
		else
		{
			s.pop();
		}

	}
} //RunStackLi()

void RunQueueAr(char *filename)
{
	Queue <int> q(500000);
	ifstream inf(filename);
	char comment, yo[512];
	int value;
	inf.getline(yo,512);

	while(inf >> comment >> value)
	{
		if (comment == 'i')
		{
			q.enqueue(value);
		}
		else
		{
			q.dequeue();
		}

	}

}//RunQueueAr(char *filename)

void RunSkipList (char *filename)
{
	SkipList<int> list(0,500000);
	ifstream inf(filename);
	char comment, yo[512];
	int value;
	inf.getline(yo,512);

	while(inf >> comment >> value)
	{
		if (comment == 'i')
		{
			list.insert(value);
		}
		else
		{
			list.deleteNode(value);
		}

	}

} //RunSkipList(filename)



int main()
{
	int choice;
	char filename[256];
	CPUTimer ct;

		cout << "Filename >> " ;
		cin >> filename;

	
	do
	{

		//cout << endl << endl;
		choice = getChoice();
		ct.reset();

		switch (choice)
		{
			case 1: Runlist(filename); break;
			case 2: RunCursorlist(filename); break;
			case 3: RunStackAr(filename); break;
			case 4: RunStackLi(filename); break;
			case 5: RunQueueAr(filename); break;
			case 6: RunSkipList(filename); break;
			
		} //switch

		cout << "CPU time: " << ct.cur_CPUTime() << endl;
	} while(choice > 0);

} //main()