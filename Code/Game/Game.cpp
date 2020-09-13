#include <SFML/Graphics.hpp>
#include "Game/Game.h"
#include "VectorFunctions/VectorFunctions.h"
#include "Collision/Collision.h"
#include "Input/Input.h"

const std::string Game::TITLE = "JumpHigh";
const sf::Vector2u Game::DEFAULT_WINDOW_SIZE = sf::Vector2u{1280, 720};

sf::Texture Game::BACKGROUND_TXT;

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
  background.setTexture(BACKGROUND_TXT);
  _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _title);
  _window.setFramerateLimit(0);

  _world.generateWorld();

  _player.setMass(3);
  _player.registerThisInStaticVector();

  for(auto& platform : _world.getPlatforms())
  {
    platform.registerThisInStaticVector();
  }

}

void Game::pollEvents()
{
  while (_window.pollEvent(_event))
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
  
  for(auto& obj : GameObject::gameObjects)
  { 
    if(obj->getSprite().getTexture())
    {
      _window.draw(*obj);
      drawHitbox(_window, *obj);
    }
    else
    {
      _window.draw(obj->getRectangleShape());
    }
  }

  _window.display();
}

void Game::update()
{
  Game::deltaTime();
  Input::update();
  resetAllCollisions();
  checkAllCollisions();

  for(auto obj : GameObject::gameObjects)
  {
    if(obj->getSprite().getTexture())
    {
      obj->update(_deltaTime);
    }
  }
  
  _timer.restart();

  FPS.work();
}

void Game::run()
{ 
  while (_window.isOpen())
  {
    pollEvents();

    update();

    draw();
  }
}
