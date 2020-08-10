#include <SFML/Graphics.hpp>
#include "InputS.h"

bool Input ::_W = false;
bool Input ::_A = false;
bool Input ::_S = false;
bool Input ::_D = false;
bool Input ::_Space = false;
bool Input ::_Escape = false;

void Input :: update()
{
    sf::Event event;

    if (event.type == sf::Event::KeyPressed)
    {
        (event.key.code == sf::Keyboard::W) ? Input::_W = true : Input::_W = false;
        (event.key.code == sf::Keyboard::A) ? Input::_A = true : Input::_A = false;
        (event.key.code == sf::Keyboard::S) ? Input::_S = true : Input::_S = false;
        (event.key.code == sf::Keyboard::D) ? Input::_D = true : Input::_D = false;
        (event.key.code == sf::Keyboard::Space) ? Input::_Space = true : Input::_Space = false;
        (event.key.code == sf::Keyboard::Escape) ? Input::_Escape = true : Input::_Escape = false;
    }
}