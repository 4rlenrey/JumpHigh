#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef FUNCT
#define FUNCT

class Game
{
  public:
  Game(std::string n, sf::Vector2u windowSize);
  ~Game();

  void start();
  void run();
  void close();

   
  private:
  sf::RenderWindow _window;
  std::string _title;
  sf::Vector2u _windowSize;
};

#endif
