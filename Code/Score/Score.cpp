#include "Score/Score.h"
#include "GameObject/GameObject.hpp"
#include <string>
#include <SFML/Graphics.hpp>

sf::Font Score::font;


Score::Score(GameObject& player, sf::View& viev)
    : _playerS{player}, _viewS{viev}
{
    _score = 0;
    text.setString("0");
    text.setFont(font);
    text.setPosition(100, 500);
    text.setCharacterSize(35);                          
    text.setStyle(sf::Text::Bold); 
    text.setFillColor(sf::Color::White);
}

void Score::update()
{
    s = "Score: ";
    s.append(std::to_string(_score));
    if (_score < -(_playerS.getPosition().y))
       _score = -(_playerS.getPosition().y);
    text.setString(s);
    text.setPosition(10, _viewS.getCenter().y - 350);

}
