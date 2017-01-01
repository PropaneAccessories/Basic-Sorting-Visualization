#ifndef MAINPROGRAM_H
#define MAINPROGARM_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "shellsort.h"
#include "eventhandler.h"

class MainProgram
{
public:
    MainProgram();
    ~MainProgram();
    void render(SDL_Rect* rects, SelectionSort &ss, InsertionSort &is, Shellsort &sh, EventHandler &e);

private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    TTF_Font* mFont;
    SDL_Color WHITE;
    SDL_Color YELLOW;
    SDL_Color BLACK;
    SDL_Rect fixedPositions[10];

    void renderText(EventHandler &e);
    void createFixedPosArray();
};

#endif // MAINPROGRAM_H
