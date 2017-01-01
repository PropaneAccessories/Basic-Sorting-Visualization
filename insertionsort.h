#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "SDL.h"

class InsertionSort
{
public:
    InsertionSort();
    void isAlgorithm(SDL_Rect* rectArray);
    void renderInsertionSort(SDL_Renderer* renderer);
    void reset();
    bool isSorted();

private:
    SDL_Rect highlight;
    SDL_Rect pointer;
    SDL_Rect temp;
    int i;
    int j;
    bool sorted;

    void updateHighlightPointer();
};

#endif // INSERTIONSORT_H
