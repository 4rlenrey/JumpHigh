#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player/Player.h"

class Game
{
  public:
  static const std::string TITLE;
  static const sf::Vector2u DEFAULT_WINDOW_SIZE;

  static sf::Clock _timer;
  static float _deltaTime;
  static void deltaTime();


  Game(std::string title = TITLE, sf::Vector2u windowSize = DEFAULT_WINDOW_SIZE);

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

class FpsCounter
{
  public:

  private:
  int count;
};

#endif
