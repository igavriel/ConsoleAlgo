#pragma once

template <class T>
class node
{
public:
	node(T x)
		: data(x), next(nullptr), prev(nullptr)
	{
		if (log)
		{
			std::cout << data << ",";
		}
	}

	~node()
	{
		if (log)
		{
			std::cout << "~" << data << ",";
		}
	}

	static bool log;
	T data;
	node* next;
	node* prev;
};
