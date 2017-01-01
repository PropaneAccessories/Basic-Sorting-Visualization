#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "SDL.h"

class Shellsort
{
public:
    Shellsort();
    void shAlgorithm(SDL_Rect* rectArray);
    void renderShellsort(SDL_Renderer* renderer);
    void reset();
    bool isSorted();

private:
    SDL_Rect highlight1;
    SDL_Rect highlight2;
    SDL_Rect pointer;
    SDL_Rect temp;
    int i;
    int j;
    int h;
    bool sorted;

    void updateGraphics();
};

#endif // SHELLSORT_H
