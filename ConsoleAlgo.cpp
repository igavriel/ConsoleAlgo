// ConsoleAlgo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "read_num.h"
#include "MyRandom.h"
#include "node.h"
#include "LinkedList.h"

using namespace std;

using intNode = node<int>;
using intRnd = MyRandom<int>;
using intList = LinkeList<int>;
bool intNode::log = false;


class ConsoleMenu
{
public:
	ConsoleMenu()
		: _intRnd(-100, 100),
		  _boolRnd(0, 1)
	{
	}

	~ConsoleMenu()
	{
	}

	void displayMenu()
	{
		cout << "0. Display Menu" << endl;
		cout << endl;
		cout << "1. Build Linked List (int)" << endl;
		cout << "2. Print Linked List (int)" << endl;
		cout << "3. Build Linked List (bool)" << endl;
		cout << "4. Print Linked List (bool)" << endl;
		cout << "5. Order boolean Linked List" << endl;
		cout << "98. Print debug logger" << endl;
		cout << endl;
		cout << "99. EXit" << endl;
	}

	void start()
	{
		displayMenu();
		bool loop = true;

		while (loop)
		{
			int i = read_num("", 0, 99);

			switch (i)
			{
			case 0: displayMenu(); break;

			case 1: _intList.buildRandomList(_intRnd); break;

			case 2: _intList.printList(); break;

			case 3: _boolList.buildRandomList(_boolRnd); break;

			case 4: _boolList.printList(); break;

			case 5: orderBoolList(); break;

			case 98:
				intNode::log = !intNode::log;
				break;

			case 99:
				loop = false;
				break;
			}
		}
	}

	void orderBoolList()
	{
		intNode* curLeft = _boolList._header;
		intNode* curRight = _boolList._footer;

		while (curLeft != nullptr &&
		        curRight != nullptr &&
		        curLeft != curRight)
		{
			if (curLeft->data == 0)
			{
				curLeft = curLeft->next;
			}
			else if (curRight->data == 1)
			{
				curRight = curLeft->prev;
			}
			else
			{
				int data = curLeft->data;
				curLeft->data = curRight->data;
				curRight->data = data;
			}
		}
	}

private:
	intRnd _intRnd;
	intRnd _boolRnd;
	intList	_intList;
	intList	_boolList;
};

int main()
{
	{
		ConsoleMenu cm;
		cm.start();
	}
	cout << endl << "Press any char to exit" << endl;
	int i;
	cin >> i;
	return 0;
}

