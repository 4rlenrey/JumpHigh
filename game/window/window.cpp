#include <SFML/Graphics.hpp>
#include "window.h"

void Window::keepAlive()
{
  sf::RenderWindow window(sf::VideoMode(300, 300), "Working window!");

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
