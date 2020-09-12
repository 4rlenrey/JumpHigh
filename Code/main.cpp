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

    Game game{};
    
    game.run();
}
