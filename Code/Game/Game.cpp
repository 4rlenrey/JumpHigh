#include <SFML/Graphics.hpp>
#include "Game/Game.h"
#include "VectorFunctions/VectorFunctions.h"
#include "Collision/Collision.h"
#include "Input/Input.h"
#include "Menu/Menu.h"
#include <iostream>

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
    : _title{title}, _windowSize{windowSize}, _cameraController{_player}, _score{_player, _cameraController.getView()}, _spikes{}
{
  start();
}

void Game::start()
{
  background.setTexture(BACKGROUND_TXT);
  _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _title);
  _window.setFramerateLimit(0);
  _window.setView(_cameraController.getView());



  _world.generateWorld();

  _player.setMass(3);
  _player.setPosition(sf::Vector2f{600, 300});
  
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
      _window.draw(*obj);
      // drawHitbox(_window, *obj);
  }
  _window.draw(_score.text);
  _window.draw(_spikes._sprite);

  _window.display();
}

void Game::update()
{
  Input::update();
  resetAllCollisions();
  checkAllCollisions(_player);
  

  //_menu.checkInput();

  for(auto& obj : GameObject::gameObjects)
  {
      obj->update(_deltaTime);
  }
  
  _cameraController.update(_deltaTime);
  _window.setView(_cameraController.getView());
  _score.update();
  _timer.restart();
  _spikes.update(_deltaTime);
  FPS.work();
}

void Game::restart()
{
  _world.destroyWorld();
  
  _world.generateWorld();
  for(auto& platform : _world.getPlatforms())
  {
    platform.registerThisInStaticVector();
  }
  _player.reset();
  _spikes.reset();
  _score._score = 0;
  _cameraController.getView().setCenter(_windowSize.x/2.0f, _windowSize.y/2.0f);
  _menu.trigger("Try again!");
  
}

void Game::run()
{ 
  while (_window.isOpen())
  {
    pollEvents();

    if(
      _player.getPosition().y > _cameraController.getView().getCenter().y + _windowSize.y/2.0f ||
      _player.getPosition().y >= _spikes._sprite.getPosition().y - 10
     )
    {
      restart();
    }

    update();
    if(_menu.isOpen())
    {
      _menu.open(_window);
      _timer.restart();
    }
    
    draw();
    Game::deltaTime();
  }
}
