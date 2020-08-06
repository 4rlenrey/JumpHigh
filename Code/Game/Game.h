#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef FUNCT
#define FUNCT

class Game
{
  private:
    std::string title;
    sf::Vector2i size;

  public:
    Game(std::string n, int h, int w){
        setVariables(n, h, w);
    }
    void setVariables(std::string n, int h, int w);
    void run();
};

#endif
