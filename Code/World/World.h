#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Platform/Platform.hpp"

using namespace std;

class World{
    public:
    int score;
    int numberOfPlatforms;

    World(const int&);
    void generatePlatform(sf::Vector2f po, sf::Vector2f s);

    vector<Platform*> platforms;
};


#endif