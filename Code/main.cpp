#include "Game/Game.h"

int main()
{
    Game game("JumpHigh", sf::Vector2i{800, 600});
    game.run();

    return 0;
}
