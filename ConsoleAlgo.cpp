// ConsoleAlgo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "read_num.h"
#include "MyRandom.h"

#include <iostream>     // std::cout
using namespace std;


class node
{
public:
	node(int x)
		: data(x), next(nullptr)
	{
		if (log)
		{
			std::cout << data << ", ";
		}
	}

	~node()
	{
		if (log)
		{
			std::cout << "~" << data << ", ";
		}
	}

	static bool log;
	int data;
	node* next;
};

bool node::log = false;

class ConsoleMenu
{
public:
	ConsoleMenu()
		: _myRnd(-100, 100),
		  _header(nullptr),
		  _footer(nullptr)
	{
	}

	~ConsoleMenu()
	{
		clearList();
	}

	void displayMenu()
	{
		cout << "0. Display Menu" << endl << endl;
		cout << "1. Build Linked List" << endl;
		cout << "2. Print Binary Tree" << endl;
		cout << "98. Print debug logger" << endl;
		cout << endl << "99. EXit" << endl;
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

			case 1: buildList(); break;

			case 2: displayMenu(); break;

			case 98: node::log = !node::log; break;

			case 99: loop = false; break;
			}
		}
	}
	void clearList()
	{
		node* current = _header;

		while (current != nullptr)
		{
			node* next = current->next;
			delete current;
			current = next;
		}

		_footer = _header = nullptr;
	}

	void addNodeToList(node* pNode)
	{
		if (_header == nullptr)
			_header = _footer = pNode;
		else
		{
			_footer->next = pNode;
			_footer = pNode;
		}
	}

	void buildList()
	{
		clearList();
		auto i = read_num("List size", 1, 100);
		node* pCurNode = nullptr;

		for (int j = 0; j < i; ++j)
		{
			node* pNode = new node(_myRnd.GetNext());
			addNodeToList(pNode);
		}
	}


private:
	MyRandom<int>_myRnd;
	node*	_header;
	node*	_footer;
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

