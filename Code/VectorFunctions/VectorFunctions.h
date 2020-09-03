#ifndef VECTORFUNCTIONS_H
#define VECTORFUNCTIONS_H

#include <ostream>
#include <SFML/Graphics.hpp>

std::ostream& operator<<(std::ostream& out, const sf::Vector2f& vec);

float length(const sf::Vector2f& vec);
sf::Vector2f normalized(const sf::Vector2f& vec);

#endif