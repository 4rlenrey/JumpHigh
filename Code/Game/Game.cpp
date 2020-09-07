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
  : _title{title}, _windowSize{windowSize}, _testPlatform{sf::Vector2f{200,500}, sf::Vector2f{200, 200}}
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

  for(auto it = std::begin(GameObject::gameObjects); it != std::end(GameObject::gameObjects); it++)
  {
    _window.draw(*(*it));
  }
  _window.draw(_testPlatform);
  _window.draw(_player.getRectangleShape());
  _window.display();
}

void Game::update()
{
  Game::deltaTime();
  Input::update();
  resetAllCollisions();
  checkAllCollisions();
  
  for(auto it = std::begin(GameObject::gameObjects); it != std::end(GameObject::gameObjects); it++)
  {
    (*it)->update(_deltaTime);
  }
  
  _timer.restart();
}

void Game::run()
{
  _player.setMass(3);
  while (_window.isOpen())
  {
    pollEvents();

    update();
    draw();

  }
}
