#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "Input/Input.h"
#include <vector>
#include <string>

enum Option
{
    Play,
    Exit
};

class Options
{
public:
    Options(Option);
    sf::Text _text;
    Option _option;
    bool isSelected;
};

class Menu
{
    void changeColorWhenSelected();
    int select;
    std::vector<Options> _options;
    bool _isOpen;
    sf::Text help;
    sf::Text changableText;

public:
    static sf::Font font;
    Menu();
    void setup();
    void trigger(const std::string &text);
    bool isOpen();
    void open(sf::RenderWindow &);
    void update(sf::RenderWindow &);
    std::vector<Options> &getOptions();
    void checkInput();
};

#endif
