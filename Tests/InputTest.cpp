#include "Input/Input.h"
#include <iostream>
#include <unistd.h>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window{sf::VideoMode{100, 100}, "title"};

    while(!Input::Escape.isPressed())
    {
        Input::update();
        std::cout << "W isPressed     = " << Input::W.isPressed() << std::endl;
        std::cout << "W justPressed   = " << Input::W.justPressed() << std::endl;
        std::cout << "W justReleased  = " << Input::W.justReleased() << std::endl;
        sleep(1);
        system("clear");
    }
}