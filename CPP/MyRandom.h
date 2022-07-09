#pragma once
#include <random>

template <class T>
class MyRandom
{
public:
	MyRandom(T min, T max)
		: _min(min),
		  _max(max),
		  _generator(_rnd()),
		  _distribution(min, max)
	{
	}
	T GetMin() const { return _min; }
	T GetMax() const { return _max; }
	T GetNext()
	{
		return _distribution(_generator);
	}

private:
	T _min;
	T _max;
	std::random_device _rnd;
	std::default_random_engine _generator;
	std::uniform_int_distribution<T> _distribution;
};