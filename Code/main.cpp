#include "Game/Game.h"
#include <string>

#include <filesystem>
#include <random>

using namespace std::filesystem;

int main()
{
    srand(time(nullptr));
    AnimationSystem::loadAnimations("./resources/Animations/");
    Platform::loadTextures("./resources/Textures/Platforms/");
    Menu::font.loadFromFile("./resources/Fonts/techniqo.ttf");
    Score::font.loadFromFile("./resources/Fonts/techniqu.ttf");

    Game game{};
    
    game.run();
}
