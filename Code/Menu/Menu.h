#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "Input/Input.h"
#include <vector>
#include <string>

enum Option {Play, Exit};

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

    public:
    static sf::Font font;
    Menu();
    void run();
    bool isOpen();
    void open(sf::RenderTarget&);
    void update(sf::RenderWindow&);
    std::vector<Options>& getOptions();
    void checkInput();
};

#endif
