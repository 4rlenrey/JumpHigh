#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include "GameObject/GameObject.hpp"
#include <string>

class Score
{
    public:
    Score(GameObject& player, sf::View& viev);

    void update();
    std::string s;
    static sf::Font font;
    long long _score;
    sf::Text text;
    GameObject& _playerS;
    sf::View& _viewS;

};

#endif