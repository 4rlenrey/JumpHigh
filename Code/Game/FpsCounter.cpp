#include "FpsCounter.hpp"
#include <iostream>

void FpsCounter::work()
{
    count();
    print();
}

void FpsCounter::print()
{
    if (_frameCount == 200)
    {
        std::cout << "FPS: " << _frameCount / _timer.getElapsedTime().asSeconds() << std::endl;
        _timer.restart();
        _frameCount = 0;
    }
}

void FpsCounter::count()
{
    ++_frameCount;
}
