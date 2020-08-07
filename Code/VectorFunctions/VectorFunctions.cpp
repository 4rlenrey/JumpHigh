#include "VectorFunctions/VectorFunctions.h"

std::ostream& operator<<(std::ostream& out, const sf::Vector2f& vec)
{
    out << vec.x << ", " << vec.y;
    return out; 
}