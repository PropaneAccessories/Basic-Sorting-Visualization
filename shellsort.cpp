#include "SDL.h"
#include "shellsort.h"

Shellsort::Shellsort()
{
    highlight1 = {0,0,0,0};
    highlight2 = {0,0,0,0};
    pointer = {0,0,0,0};
    temp = {0,0,0,0};
    sorted = false;
    i = j = h = 40;
}

void Shellsort::shAlgorithm(SDL_Rect* rectArray)
{
    if(h == 0)
    {
        sorted = true;
        updateGraphics();
        return;
    }

    if(i == 100)
    {
        h = h/3;
        i = h;
        j = h;
        updateGraphics();
        return;
    }

    if(j >= h)
    {
        if(rectArray[j-h].h > rectArray[j].h)
        {
            temp.h = rectArray[j].h;
            rectArray[j].h = rectArray[j-h].h;
            rectArray[j-h].h = temp.h;

            temp.y = rectArray[j].y;
            rectArray[j].y = rectArray[j-h].y;
            rectArray[j-h].y = temp.y;

            j -= h;
        }
        else
        {
            i++;
            j = i;
        }
        updateGraphics();
        return;
    }
    else
    {
        i++;
        j = i;
        updateGraphics();
        return;
    }
}

void Shellsort::renderShellsort(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0x50, 0x50, 0x50, 0xFF);    // gray
    SDL_RenderFillRect(renderer, &highlight1);                   // draw highlight1
    SDL_RenderFillRect(renderer, &highlight2);                   // draw highlight2
    SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xFF);    // red
    SDL_RenderFillRect(renderer, &pointer);                      // draw pointer
}

void Shellsort::reset()
{
    highlight1 = {0,0,0,0};
    highlight2 = {0,0,0,0};
    pointer = {0,0,0,0};
    temp = {0,0,0,0};
    sorted = false;
    i = j = h = 40;
}

void Shellsort::updateGraphics()
{
    if(sorted)
    {
        pointer = {0,0,0,0};
        highlight1 = {0,0,0,0};
        highlight2 = {0,0,0,0};
    }
    else
    {
        pointer = {200+(j*6),380,6,6};
        highlight1 = {200+(j*6)-1, 25, 6, 355};
        highlight2 = {200+((j-h)*6)-1, 25, 6, 355};
    }
}

bool Shellsort::isSorted()  { return sorted; }
