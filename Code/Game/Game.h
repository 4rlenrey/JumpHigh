#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
  public:
  Game(std::string n, sf::Vector2u windowSize);

  void start();
  void run();
  void pollEvents();
  void draw();
  void update();
  float deltaTime();
   
  private:
  sf::RenderWindow _window;
  sf::Vector2u _windowSize;
  std::string _title;
  sf::Event _event;
  
  sf::Clock _timer;
  sf::Time _frameStartTime;
};

#endif
