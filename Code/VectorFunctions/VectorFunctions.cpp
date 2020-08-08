#include "VectorFunctions/VectorFunctions.h"
#include <math.h>

std::ostream& operator<<(std::ostream& out, const sf::Vector2f& vec)
{
    out << vec.x << ", " << vec.y;
    return out; 
}

float lenght(const sf::Vector2f& vec)
{
    return std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
}

sf::Vector2f normalized(const sf::Vector2f& vec)
{
    float length = lenght(vec);
    
    sf::Vector2f normalized = sf::Vector2f{vec.x / length, vec.y / length};
    
    return normalized;
}

