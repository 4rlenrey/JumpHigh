#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <iostream>

sf::Font Menu::font;

Options::Options(const Option option)
    : _option{option}, isSelected{false}
{
}

Menu::Menu()
    : select{0}, _isOpen{true}
{
  setup();
}

void Menu::setup()
{
  _options.push_back(Options{Option::Play});
  _options.back()._text.setString("Play");
  _options.push_back(Options{Option::Exit});
  _options.back()._text.setString("Exit");
  _options[0].isSelected = true;

  changableText.setFont(font);
  changableText.setPosition(270, 110);
  changableText.setCharacterSize(30);
  changableText.setFillColor(sf::Color::Blue);

  for (int i = 0; i < _options.size(); i++)
  {
    help.setString("Press space to confirm");
    help.setFont(font);
    help.setPosition(100, 500);
    help.setCharacterSize(50);
    help.setStyle(sf::Text::Bold);
    help.setFillColor(sf::Color::White);

    _options[i]._text.setFont(font);
    _options[i]._text.setPosition(100, 100 + 100 * i);
    _options[i]._text.setCharacterSize(50);
    _options[i]._text.setStyle(sf::Text::Bold);
    if (_options[i].isSelected == true)
      _options[i]._text.setFillColor(sf::Color::Red);
    else
      _options[i]._text.setFillColor(sf::Color::White);
  }
}

void Menu::checkInput()
{
  if (Input::Escape.justPressed())
  {
    _isOpen = true;
  }
  if (_isOpen == true)
  {
    if (Input::W.justPressed())
    {
      if (select > 0)
      {
        _options[select].isSelected = false;
        select--;
        _options[select].isSelected = true;
      }
    }
    if (Input::S.justPressed())
    {

      if (select < _options.size() - 1)
      {
        _options[select].isSelected = false;
        select++;
        _options[select].isSelected = true;
      }
    }
    if (Input::Space.justPressed() && select == 0)
      _isOpen = false;
    if (Input::Space.justPressed() && select == 1)
    {
      exit(1);
    }
  }
}

bool Menu::isOpen()
{
  return _isOpen;
}

void Menu::open(sf::RenderWindow &window)
{
  while (_isOpen && window.isOpen())
  {
    update(window);
    window.clear();
    for (Options &option : _options)
      window.draw(option._text);
    window.draw(help);
    window.draw(changableText);
    window.display();
  }
}
void Menu::update(sf::RenderWindow &window)
{
  sf::Event _event;
  Input::update();
  checkInput();
  changeColorWhenSelected();
  while (window.pollEvent(_event))
  {
    if (_event.type == sf::Event::Closed)
    {
      window.close();
      exit(1);
    }
  }
}

void Menu::changeColorWhenSelected()
{
  for (Options &option : _options)
  {
    if (option.isSelected == true)
      option._text.setFillColor(sf::Color::Red);
    else
      option._text.setFillColor(sf::Color::White);
  }
  //std::cout << select << std::endl;
}

std::vector<Options> &Menu::getOptions()
{
  return _options;
}

void Menu::trigger(const std::string &text)
{
  _isOpen = true;
  changableText.setString(text);
}