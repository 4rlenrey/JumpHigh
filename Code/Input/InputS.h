#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <SFML/Graphics.hpp>

class Input
{
 public:
    static bool _W;
    static bool _A;
    static bool _S;
    static bool _D;
    static bool _Space;
    static bool _Escape;

    static void update();

};


#endif