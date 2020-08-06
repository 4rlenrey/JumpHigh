#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game(std::string title, sf::Vector2u windowSize)
  : _title{title}, _windowSize{windowSize}
{
  start();
}

void Game::start()
{
  _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _title);
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

  _window.display();
}

void Game::update()
{
  
}

float Game::deltaTime()
{
  return _frameStartTime.asMilliseconds() - _timer.getElapsedTime().asMilliseconds();
}

void Game::run()
{
  while (_window.isOpen())
  {
    _frameStartTime = _timer.restart();
    pollEvents();

    update();
    draw();
  }
}