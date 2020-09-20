#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include "Platform/Platform.hpp"
#include "AnimationSystem/AnimationSystem.h"
#include "World/World.hpp"
#include "CameraController/CameraController.h"
#include "Menu/Menu.h"
#include "Score/Score.h"
#include "Spikes/Spikes.h"

class FpsCounter
{
  public:
  
  void work()
  {
    count();
    print();
  }
  
  private:
  void print()
  {
    if(_frameCount == 200)
    {
      std::cout << "FPS: " << _frameCount/_timer.getElapsedTime().asSeconds() << std::endl;
      _timer.restart();
      _frameCount = 0;
    }
  }

  void count()
  {
    ++_frameCount;
  }

  int _frameCount = 0;
  sf::Clock _timer;
};

class Game
{
  public:
  static const std::string TITLE;
  static const sf::Vector2u DEFAULT_WINDOW_SIZE;

  static sf::Texture BACKGROUND_TXT;

  static sf::Clock _timer;
  static float _deltaTime;
  static void deltaTime();


  Game(std::string title = TITLE, sf::Vector2u windowSize = DEFAULT_WINDOW_SIZE);

  void start();
  void run();
  void pollEvents();
  void draw();
  void update();
  void death();
  void restart();


  private:
  sf::RenderWindow _window;
  std::string _title;
  sf::Vector2u _windowSize;
  sf::Event _event;
  Menu _menu;

  Player _player;
  CameraController _cameraController;
  World _world;
  Score _score;
  Spikes _spikes;

  sf::Sprite background;

  FpsCounter FPS;
};

#endif
