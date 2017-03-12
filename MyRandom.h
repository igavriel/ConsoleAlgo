#pragma once
#include <random>

template <class T>
class MyRandom
{
public:
    MyRandom(T min, T max)
        : _generator(_rnd()),
          _distribution(min, max)
    {
    }

    T GetNext()
    {
        return _distribution(_generator);
    }

private:
    std::random_device _rnd;
    std::default_random_engine _generator;
    std::uniform_int_distribution<T> _distribution;
};