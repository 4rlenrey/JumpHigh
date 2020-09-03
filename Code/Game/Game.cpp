#include <SFML/Graphics.hpp>
#include "Game/Game.h"
#include "VectorFunctions/VectorFunctions.h"
#include "Collision/Collision.h"
#include "Input/Input.h"

const std::string Game::TITLE = "JumpHigh";
const sf::Vector2u Game::DEFAULT_WINDOW_SIZE = sf::Vector2u{1280, 720};

sf::Clock Game::_timer{};
float Game::_deltaTime{};
void Game::deltaTime()
{
   Game::_deltaTime = Game::_timer.getElapsedTime().asSeconds();
}

Game::Game(std::string title, sf::Vector2u windowSize)
  : _title{title}, _windowSize{windowSize}
{
  start();
}

void Game::start()
{
  _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _title);
  _window.setFramerateLimit(0);
}

void Game::pollEvents()
{
  while(_window.pollEvent(_event))
  {
    if (_event.type == sf::Event::Closed)
    {
      _window.close();
    }
  }
}

void Game::draw()
{
  _window.clear();

  _window.draw(_player.getRectangleShape());
  _window.draw(_testPlayer.getRectangleShape());
  _window.display();
}

void Game::update()
{
  Game::deltaTime();
  Input::update();
  _player.update(_deltaTime);
  _testPlayer.update(_deltaTime);
  _timer.restart();
}

void Game::run()
{
  _testPlayer.setMass(2);
  _player.setMass(3);
  while (_window.isOpen())
  {
    pollEvents();

    update();
    draw();

  }
}
