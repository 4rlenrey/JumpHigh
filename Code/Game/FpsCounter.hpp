#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include <SFML/System.hpp>

class FpsCounter
{
  public:
  
  void work();
  
  private:

  void print();
  void count();

  int _frameCount = 0;
  sf::Clock _timer;
};

#endif