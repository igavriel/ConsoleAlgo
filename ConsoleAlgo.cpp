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
		cout << "5. Order boolean Array" << endl;
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

			case 5: orderBoolArray(); break;

			case 98:
				intNode::log = !intNode::log;
				break;

			case 99:
				loop = false;
				break;
			}
		}
	}

	void orderBoolArray()
	{
		int size = read_num("Size of Array", 0, 100);
		std::vector<int> ballsArray;
		intRnd ballsRnd(0, 2);

		for (int i = 0; i < size; ++i)
		{
			ballsArray.push_back(ballsRnd.GetNext());
		}

		cout << "Before: ";

		for (auto& item : ballsArray)
		{
			cout << item << " ";
		}

		auto iterLeft = std::begin(ballsArray);
		auto iterRight = std::end(ballsArray)-1;
		int iterationCounter = 0;

		// while left is before the right
		while (iterLeft < iterRight)
		{
			// while left is not at the end and its point to min value
			while (iterLeft != std::end(ballsArray) &&
			        *iterLeft == ballsRnd.GetMin())
			{
				++iterationCounter;
				++iterLeft;
			}

			// while right is not at the beginning and its point to max value
			while (iterRight != std::begin(ballsArray) &&
			        *iterRight == ballsRnd.GetMax())
			{
				++iterationCounter;
				--iterRight;
			}

			if (iterLeft < iterRight)
			{
				int data = *iterLeft;
				*iterLeft = *iterRight;
				*iterRight = data;
			}
		}

		cout << endl << "After:  ";

		for (auto& item : ballsArray)
		{
			cout << item << " ";
		}

		cout << endl << "Iteration Counter: " << iterationCounter << endl;
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

