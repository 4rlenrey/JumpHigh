#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player/Player.h"

class Game
{
  public:
  static sf::Clock _timer;
  static float _deltaTime;
  static void deltaTime();

  Game(std::string n, sf::Vector2u windowSize);

  void start();
  void run();
  void pollEvents();
  void draw();
  void update();

   
  private:
  sf::RenderWindow _window;
  std::string _title;
  sf::Vector2u _windowSize;
  sf::Event _event;
  
  

  Player _player;

};

#endif
