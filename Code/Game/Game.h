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
#include "Game/FpsCounter.hpp"

class Game
{
public:
  static const std::string TITLE;
  static const sf::Vector2u DEFAULT_WINDOW_SIZE;
  static const float DEATH_TIME;

  static sf::Texture backgroundTexture;
  static sf::Texture deathTexture;

  static sf::Clock timer;
  static float deltaTime;
  static void updateDeltaTime();
  static void restartTimer()
  {
    timer.restart();
  }

  Game(std::string title = TITLE, sf::Vector2u windowSize = DEFAULT_WINDOW_SIZE);

  void start();
  void run();
  void pollEvents();
  void restart();
  void update();
  void draw();
  void showDeathScreen();

private:
  bool windowIsOpen();
  bool menuIsOpen();
  bool playerLost();
  void openMenu();

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

  sf::Sprite _background;

  FpsCounter _fpsCounter;
};

#endif
