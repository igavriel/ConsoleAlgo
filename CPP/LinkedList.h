#pragma once

template <class T>
class LinkeList
{
public:
	LinkeList()
		: _header(nullptr),
		  _footer(nullptr)
	{
	}
	~LinkeList()
	{
		clear();
	}

	void addNode(node<T>* pNode)
	{
		if (_header == nullptr)
			_header = _footer = pNode;
		else
		{
			_footer->next = pNode;
			pNode->prev = _footer;
			_footer = pNode;
		}
	}

	void buildRandomList(MyRandom<T>& random)
	{
		clear();
		auto i = read_num("List size", 1, 100);
		node<T>* pCurNode = nullptr;

		for (int j = 0; j < i; ++j)
		{
			node<T>* pNode = new node<T>(random.GetNext());
			addNode(pNode);
		}
	}

	void clear()
	{
		node<T>* current = _header;

		while (current != nullptr)
		{
			node<T>* next = current->next;
			delete current;
			current = next;
		}

		_footer = _header = nullptr;
	}

	void printList()
	{
		node<T>* current = _header;

		while (current != nullptr)
		{
			std::cout << current->data << ",";
			current = current->next;
		}

		std::cout << "NIL";
	}

	node<T>*	_header;
	node<T>*	_footer;
};