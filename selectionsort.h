#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "SDL.h"

class SelectionSort
{
public:
    SelectionSort();
    void ssAlgorithm(SDL_Rect* rectArray);
    void renderSelectionSort(SDL_Renderer* renderer);
    void reset();
    bool isSorted();

private:
    SDL_Rect highlight;
    SDL_Rect pointer;
    SDL_Rect temp;
    int i;
    int j;
    int pos;
    int lowest;
    bool sorted;

    void updateHighlight();
    void updatePointer();
};

#endif // SELECTIONSORT_H
