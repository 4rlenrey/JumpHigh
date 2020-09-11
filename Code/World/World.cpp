#include "World/World.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Platform/Platform.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;


void World::generatePlatform(sf::Vector2f po, sf::Vector2f s){
    //fix later
   
    // srand(time(NULL));
    
    // sf::Vector2f posiston; 
    // posiston.x = 100;
    // posiston.y = 100;

    // sf::Vector2f size;
    // size.x = (rand() % 200)+100;
    // size.y = (rand() % 50)+100;

    World::platforms.push_back(new Platform{po, s});
}

World::World(const int& nPlatform)
{
    sf::Vector2f s;
    s.x = 681;
    s.y = 151;

    sf::Vector2f po;
    po.x = 0;
    po.y = 0;

    World::numberOfPlatforms = nPlatform;

    for(int i = 0; i < nPlatform; i++)
    {
    po.x = po.x + 100;
    po.y = po.y + 160;

    World::generatePlatform(po, s);
    }
}