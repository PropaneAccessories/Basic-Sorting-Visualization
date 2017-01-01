#include "bars.h"
#include "selectionsort.h"

SelectionSort::SelectionSort()
{
    highlight = {0,0,0,0};
    pointer = {0,0,0,0};
    i = 0;
    j = 0;
    pos = 0;
    lowest = 1000;
    sorted = false;
}

void SelectionSort::ssAlgorithm(SDL_Rect* rectArray)
{
    // test if the sort has been completed. 'i' represents the outside loop.
    if(i == 99)
    {
        updateHighlight();
        sorted = true;
        return;
    }
    // check if the inside loop has been completed. If so, swap lowest to position 'i'
    if(j == 100)
    {
        lowest = 1000;

        temp.h = rectArray[i].h;
        rectArray[i].h = rectArray[pos].h;
        rectArray[pos].h = temp.h;

        temp.y = rectArray[i].y;
        rectArray[i].y = rectArray[pos].y;
        rectArray[pos].y = temp.y;

        i++;
        j = i;
        return;
    }

    if(rectArray[j].h < lowest)
    {
        lowest = rectArray[j].h;
        pos = j;
        j++;
        updateHighlight();
        updatePointer();
        return;
    }
    else
    {
        j++;
        updatePointer();
        return;
    }
}

void SelectionSort::updateHighlight()
{
    if(pos == 0 || i == 99)
        highlight = {0,0,0,0};
    else
        highlight = {200+(pos*6)-1, 25, 6, 355};
}

void SelectionSort::updatePointer()
{
    pointer = {200+(j*6),380,6,6};
}

void SelectionSort::renderSelectionSort(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0x50, 0x50, 0x50, 0xFF);  // gray
    SDL_RenderFillRect(renderer, &highlight);                  // draw highlight
    SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xFF);  // red
    SDL_RenderFillRect(renderer, &pointer);                    // draw pointer
}

void SelectionSort::reset()
{
    highlight = {0,0,0,0};
    pointer = {0,0,0,0};
    i = 0;
    j = 0;
    pos = 0;
    lowest = 1000;
    sorted = false;
}

bool SelectionSort::isSorted()  { return sorted; }
