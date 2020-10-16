#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu/Menu.h"
#include "Input/Input.h"
#include "Game/Game.h"
#include "VectorFunctions/VectorFunctions.h"
#include "Collision/Collision.h"

const std::string Game::TITLE = "JumpHigh";
const sf::Vector2u Game::DEFAULT_WINDOW_SIZE = sf::Vector2u{1280, 720};
const float Game::DEATH_TIME = 3.0f;

sf::Texture Game::backgroundTexture;
sf::Texture Game::deathTexture;
sf::Clock Game::timer;
float Game::deltaTime;

void Game::updateDeltaTime()
{
  Game::deltaTime = Game::timer.getElapsedTime().asSeconds();
}

Game::Game(std::string title, sf::Vector2u windowSize)
    : _title{title}, _windowSize{windowSize}, _cameraController{_player}, _score{_player, _cameraController.getView()}
{
  start();
}

void Game::start()
{
  _background.setTexture(backgroundTexture);

  _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _title);
  _window.setFramerateLimit(0);
  _window.setView(_cameraController.getView());

  _world.generateWorld();

  _player.setMass(3);
  _player.setPosition(sf::Vector2f{600, 300});

  _player.registerThisInStaticVectorOnLayer(0);
  _spikes.registerThisInStaticVectorOnLayer(2);
  _score.registerThisInStaticVector();

  for (auto &platform : _world.getPlatforms())
  {
    platform.registerThisInStaticVectorOnLayer(1);
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

  for (int i = 0; i <= 2; i++)
  {
    for (auto &obj : GameObject::gameObjects)
    {
      if (obj->getLayer() == i)
      {
        _window.draw(*obj);
      }
    }
  }

  _window.draw(_score);
  _window.display();
}

void Game::update()
{
  Input::update();
  resetAllCollisions();
  checkAllCollisions(_player);

  for (auto &obj : GameObject::gameObjects)
  {
    obj->update(deltaTime);
  }

  _cameraController.update(deltaTime);
  _window.setView(_cameraController.getView());
  _score.update();
  _spikes.update(deltaTime);
  _fpsCounter.work();

  restartTimer();
}

void Game::restart()
{
  _world.destroyWorld();

  _world.generateWorld();

  for (auto &platform : _world.getPlatforms())
  {
    platform.registerThisInStaticVectorOnLayer(1);
  }

  _player.reset();
  _spikes.reset();
  _score.reset();
  _cameraController.reset(sf::Vector2f{_windowSize.x / 2.0f, _windowSize.y / 2.0f});

  _menu.trigger("Try again!");
}

void Game::run()
{
  while (windowIsOpen())
  {
    pollEvents();

    if (playerLost())
    {
      showDeathScreen();
      restart();
    }

    update();

    if (menuIsOpen())
    {
      openMenu();
      restartTimer();
    }

    draw();

    Game::updateDeltaTime();
  }
}

bool Game::windowIsOpen()
{
  return _window.isOpen();
}

bool Game::menuIsOpen()
{
  return _menu.isOpen();
}

void Game::openMenu()
{
  _menu.open(_window);
}

bool Game::playerLost()
{
  if (_player.getPosition().y > _cameraController.getView().getCenter().y + _windowSize.y / 2.0f ||
      _player.getPosition().y >= _spikes.getSprite().getPosition().y - 10)
  {
    return true;
  }
  return false;
}

void Game::showDeathScreen()
{
  sf::Clock deathTimer;
  sf::Sprite deathSprite{deathTexture};
  deathSprite.scale(sf::Vector2f{0.5f, 0.5f});

  _cameraController.reset(sf::Vector2f{_windowSize.x / 2.0f, _windowSize.y / 2.0f});
  _window.setView(_cameraController.getView());

  while (windowIsOpen() && deathTimer.getElapsedTime().asSeconds() < DEATH_TIME)
  {
    pollEvents();
    Input::update();
    _window.clear();
    _window.draw(deathSprite);
    _window.display();
  }
}
