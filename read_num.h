#pragma once

template <class T>
T read_num(char* msg, T min, T max)
{
	T num;

	if (msg != nullptr)
	{
		std::cout << msg;
	}

	do
	{
		std::cout << "> ";
		std::cin >> num;
	}
	while (num <min || num >max);

	return num;
}