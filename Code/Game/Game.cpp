#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game(std::string title, sf::Vector2u windowSize)
  : _title{title}, _windowSize{windowSize}
{
  start();
}

Game::~Game()
{
  close();
}

void Game::start()
{
  _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _title);
}

void Game::run()
{
  while (_window.isOpen())
  {
      sf::Event event;
      while (_window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              _window.close();
      }

      _window.clear();
      _window.display();
  }
}

void Game::close()
{

}