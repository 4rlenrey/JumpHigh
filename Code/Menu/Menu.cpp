#include <SFML/Graphics.hpp>
#include "Menu.h"

sf::Font Menu::font;

Options::Options(const Option option)
  : _option{option}
{

}

Menu::Menu()
  : select{0}, _isOpen{true}
{
  
  _options.push_back(Options{Option::Play});
  _options.back()._text.setString("Play");
  _options.push_back(Options{Option::Exit});
  _options.back()._text.setString("Exit");
  _options[0].isSelected = true;

  run();
}


void Menu::checkInput()
{
  if(Input::Escape.justPressed())
  {
    _isOpen = true;
  }
  if(Input::W.justPressed())
      if(select < _options.size()-1)
      {
        _options[select].isSelected = false;
        select++; 
        _options[select].isSelected = true;
      }
  if(Input::S.justPressed())
      if(select > 0)
      {
        _options[select].isSelected = false;
        select--;  
        _options[select].isSelected = true;
      }
}

bool Menu::isOpen()
{
  return _isOpen; 
}

void Menu::open(sf::RenderTarget& window)
{
  while (_isOpen)
  {
    update(dynamic_cast<sf::RenderWindow&>(window));
    for(Options& option : _options)
    window.draw(option._text);
  }
}
void Menu::update(sf::RenderWindow& window)
{
  sf::Event _event;
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
 for(Options& option : _options)
  {
    if (option.isSelected == true)
      option._text.setColor(sf::Color::Red);
    else
      option._text.setColor(sf::Color::White);    
  } 
}

std::vector<Options>& Menu::getOptions()
{
  return _options;
}

void Menu::run()
{
  for(int i = 0; i < _options.size(); i++)
  {
    _options[i]._text.setFont(font);
    _options[i]._text.setPosition(100, 100 + 100*i);
    _options[i]._text.setCharacterSize(24);                          
    _options[i]._text.setStyle(sf::Text::Bold); 
    if (_options[i].isSelected == true)
      _options[i]._text.setColor(sf::Color::Red);
    else
      _options[i]._text.setColor(sf::Color::White);    
  }    
}