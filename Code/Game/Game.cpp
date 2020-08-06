#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game(std::string title, sf::vector2i windowSize)
  : _title{title}, _windowSize{windowSize}
{

}

void Game::start()
{
  
}

void Game::run()
{
  

  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();
      }

      window.clear();
      window.display();
  }
}
