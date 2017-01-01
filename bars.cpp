#include "bars.h"
#include "SDL.h"
#include <stdlib.h>
#include <time.h>

Bars::Bars()    { createArray(); }

void Bars::createArray()
{
    srand(time(NULL));
    int random = 0;
    for(int i=0; i<100; i++)
    {
        random = (rand() % 300) + 50;
        rectArray[i] = {200+(i*6),375-random,4,random};
    }
}

void Bars::reset()              { createArray(); }

SDL_Rect* Bars::getRectArray()  { return rectArray; }

