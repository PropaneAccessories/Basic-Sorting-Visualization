#ifndef BARS_H
#define BARS_H

#include "SDL.h"

class Bars
{
public:
    Bars();
    SDL_Rect* getRectArray();
    void reset();

private:
    SDL_Rect rectArray[100];
    void createArray();
};

#endif // BARS_H
