#include <SFML/Graphics.hpp>
#include "Game.h"

sf::Clock Game::_timer{};

float Game::deltaTime()
{
  return _timer.getElapsedTime().asSeconds()*1000.0f;
}

Game::Game(std::string title, sf::Vector2u windowSize)
  : _title{title}, _windowSize{windowSize}
{
  start();
}

void Game::start()
{
  _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _title);
  _window.setFramerateLimit(60);
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

  _window.draw(_player._rec);

  _window.display();
}

void Game::update()
{
  _player.update(deltaTime());
  //std::cout << _player << std::endl;
}

void Game::run()
{
  while (_window.isOpen())
  {
    _timer.restart();
    pollEvents();

    update();
    draw();
    //std::cout << "FPS: " << 1.0 / _timer.getElapsedTime().asSeconds();
  }
}