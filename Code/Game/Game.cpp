#include <SFML/Graphics.hpp>
#include "window.h"

void Game::setVariables(std::string n, int h, int w)
{
  size.x = h;
  size.y = w;
  title = n;
}

void Game::run()
{
  sf::RenderWindow window(sf::VideoMode(size.x, size.y), title);

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
