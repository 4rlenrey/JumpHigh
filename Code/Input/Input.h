#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

struct ButtonStates
{
    bool isPressed();
    bool justPressed();
    bool justReleased();
    void operator=(bool val);

    private:
    bool _currentState = 0;
    bool _previousState = 0;
    bool _justPressed = 0;
    bool _justReleased = 0;
    void checkButtonJustPressed();
    void checkButtonJustReleased();
};

class Input
{
    public:
    static ButtonStates W;
    static ButtonStates A;
    static ButtonStates S;
    static ButtonStates D;
    static ButtonStates Space;
    static ButtonStates Escape;
    
    static void update();
};


#endif