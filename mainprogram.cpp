#include <string>
#include <sstream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "mainprogram.h"
#include "selectionsort.h"
#include "eventhandler.h"

MainProgram::MainProgram()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    mWindow = SDL_CreateWindow("Basic Sorting", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, 800,400, SDL_WINDOW_SHOWN);
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    mFont = TTF_OpenFont("veraFonts/Vera.ttf", 20);

    WHITE = {255,255,255,255};
    YELLOW = {255,255,0,255};
    BLACK = {0,0,0,255};
    createFixedPosArray();
}

MainProgram::~MainProgram()
{
    TTF_Quit();
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void MainProgram::render(SDL_Rect* rects, SelectionSort &ss, InsertionSort &is, Shellsort &sh, EventHandler &e)
{
    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);  // black
    SDL_RenderClear(mRenderer); // clear the screen and fill it with the rendering color

    switch (e.getSortSelection())
    {
    case EventHandler::SS_CLICKED:
        {
            ss.renderSelectionSort(mRenderer);
            break;
        }
    case EventHandler::IS_CLICKED:
        {
            is.renderInsertionSort(mRenderer);
            break;
        }
    case EventHandler::SH_CLICKED:
        {
            sh.renderShellsort(mRenderer);
            break;
        }
    }

    SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xFF);  // white
    SDL_RenderFillRects(mRenderer, rects, 100); // draw the bars to be sorted

    renderText(e); // render text on the side.
    fixedPositions[9].x = 140 - ((e.getDelay()/5) * 2);
    SDL_RenderFillRect(mRenderer, &fixedPositions[8]);
    SDL_RenderFillRect(mRenderer, &fixedPositions[9]);

    SDL_RenderPresent(mRenderer);   // updates the screen with any rendering done since the last call
}

void MainProgram::renderText(EventHandler &e)
{
    // creating a blank surface to blit to
    SDL_Surface* s1 = SDL_CreateRGBSurface(0, 200, 400, 32,0,0,0,0);
    // fill the blank surface with black
    SDL_FillRect(s1, NULL, SDL_MapRGB(s1->format,0,0,0));
    SDL_Surface* s2;
    SDL_Surface* s3;
    SDL_Surface* s4;
    SDL_Surface* s5;
    SDL_Surface* s6;
    SDL_Surface* s7;
    SDL_Surface* s8;

    // creating the text surfaces whose color depends on if the mouse is hovering over it
    if(e.highlightEvent() == EventHandler::SELECTIONSORT_HL)
        s2 = TTF_RenderText_Solid(mFont, "Selection Sort", YELLOW);
    else
        s2 = TTF_RenderText_Solid(mFont, "Selection Sort", WHITE);
    if(e.highlightEvent() == EventHandler::INSERTIONSORT_HL)
        s3 = TTF_RenderText_Solid(mFont, "Insertion Sort", YELLOW);
    else
        s3 = TTF_RenderText_Solid(mFont, "Insertion Sort", WHITE);
    if(e.highlightEvent() == EventHandler::SHELLSORT_HL)
        s4 = TTF_RenderText_Solid(mFont, "Shellsort", YELLOW);
    else
        s4 = TTF_RenderText_Solid(mFont, "Shellsort", WHITE);
    if(e.highlightEvent() == EventHandler::PAUSE_HL)
        s5 = TTF_RenderText_Solid(mFont, "Pause", YELLOW);
    else
        s5 = TTF_RenderText_Solid(mFont, "Pause", WHITE);
    if(e.highlightEvent() == EventHandler::RESET_HL)
        s6 = TTF_RenderText_Solid(mFont, "Reset", YELLOW);
    else
        s6 = TTF_RenderText_Solid(mFont, "Reset", WHITE);
    if(e.highlightEvent() == EventHandler::PLUS_HL)
        s7 = TTF_RenderText_Solid(mFont, "+", YELLOW);
    else
        s7 = TTF_RenderText_Solid(mFont, "+", WHITE);
    if(e.highlightEvent() == EventHandler::MINUS_HL)
        s8 = TTF_RenderText_Solid(mFont, "-", YELLOW);
    else
        s8 = TTF_RenderText_Solid(mFont, "-", WHITE);

    // blit the surfaces onto s1
    SDL_BlitSurface(s2, NULL, s1, &fixedPositions[0]);
    SDL_BlitSurface(s3, NULL, s1, &fixedPositions[1]);
    SDL_BlitSurface(s4, NULL, s1, &fixedPositions[2]);
    SDL_BlitSurface(s5, NULL, s1, &fixedPositions[4]);
    SDL_BlitSurface(s6, NULL, s1, &fixedPositions[5]);
    SDL_BlitSurface(s7, NULL, s1, &fixedPositions[6]);
    SDL_BlitSurface(s8, NULL, s1, &fixedPositions[7]);

    // create a texture out of the blitted surface
    SDL_Texture* t1 = SDL_CreateTextureFromSurface(mRenderer, s1);
    SDL_FreeSurface(s1);
    SDL_FreeSurface(s2);
    SDL_FreeSurface(s3);
    SDL_FreeSurface(s4);
    SDL_FreeSurface(s5);
    SDL_FreeSurface(s6);
    SDL_FreeSurface(s7);
    SDL_FreeSurface(s8);

    // copy the texture to the rendering target
    SDL_RenderCopy(mRenderer, t1, NULL, &fixedPositions[3]);
    SDL_DestroyTexture(t1);
}

void MainProgram::createFixedPosArray()
{
    fixedPositions[0] = {20,20,0,0};        // selection sort text
    fixedPositions[1] = {20,80,0,0};        // insertion sort text
    fixedPositions[2] = {20,140,0,0};       // shellsort text
    fixedPositions[3] = {0,0,200,400};      // text drawing area
    fixedPositions[4] = {20,240,0,0};       // pause text
    fixedPositions[5] = {100,240,0,0};      // reset text
    fixedPositions[6] = {150,300,0,0};      // the plus sign
    fixedPositions[7] = {20,300,0,0};       // the minus sign
    fixedPositions[8] = {40,310,100,5};     // bar for the slider
    fixedPositions[9] = {120,300,5,25};     // the slider
}
