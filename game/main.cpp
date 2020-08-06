#include "window/window.h"

int main()
{
    Game gameWindow("JumpHigh", 640, 640);
    gameWindow.keepAlive();

    return 0;
}
