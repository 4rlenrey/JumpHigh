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
    Menu::font.loadFromFile("./resources/Fonts/Kamikaze.ttf");
    Score::font.loadFromFile("./resources/Fonts/Kamikaze.ttf");
    Spikes::spikesTexture.loadFromFile("./resources/Textures/Spikes/Spikes2.png");

    Game game{};
    
    game.run();
}
