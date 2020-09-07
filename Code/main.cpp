#include "Game/Game.h"
#include <string>

int main()
{
    Platform::loadTexture("./resources/Textures/Platforms/test.png");
    Game game{};
    game.run();
}
