#include "eventhandler.h"
#include "SDL.h"

EventHandler::EventHandler()
{
    quit = false;
    instanceFlag = false;
    pause = false;

    highlightKey = -1;
    sortClicked = -1;
    functionClicked = -1;
    delay = 0;
}

void EventHandler::handleEvents()
{
    while(SDL_PollEvent(&event))
    {
        // Exiting the program
        if(event.type == SDL_QUIT) quit = true;

        // Mouse position handling
        if(event.type == SDL_MOUSEMOTION)
        {
            // hovering over the selection sort
            SDL_GetMouseState(&xMousePos, &yMousePos);
            if(xMousePos >= 20 && xMousePos <= 150 && yMousePos >= 20 && yMousePos <= 40)
            {
                cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
                SDL_SetCursor(cursor);
                highlightKey = SELECTIONSORT_HL;
                break;
            }
            // hovering over the insertion sort
            if(xMousePos >= 20 && xMousePos <= 150 && yMousePos >= 80 && yMousePos <= 100)
            {
                cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
                SDL_SetCursor(cursor);
                highlightKey = INSERTIONSORT_HL;
                break;
            }
            // hovering over the shellsort
            if(xMousePos >= 20 && xMousePos <= 150 && yMousePos >= 140 && yMousePos <= 160)
            {
                cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
                SDL_SetCursor(cursor);
                highlightKey = SHELLSORT_HL;
                break;
            }
            // hovering over pause
            if(xMousePos >= 20 && xMousePos <= 80 && yMousePos >= 240 && yMousePos <= 260)
            {
                cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
                SDL_SetCursor(cursor);
                highlightKey = PAUSE_HL;
                break;
            }
            // hovering over reset
            if(xMousePos >= 100 && xMousePos <= 160 && yMousePos >= 240 && yMousePos <= 260)
            {
                cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
                SDL_SetCursor(cursor);
                highlightKey = RESET_HL;
                break;
            }
            // hovering over "+"
            if(xMousePos >= 150 && xMousePos <= 170 && yMousePos >= 300 && yMousePos <= 320)
            {
                cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
                SDL_SetCursor(cursor);
                highlightKey = PLUS_HL;
                break;
            }
            // hovering over "-"
            if(xMousePos >= 20 && xMousePos <= 40 && yMousePos >= 300 && yMousePos <= 320)
            {
                cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
                SDL_SetCursor(cursor);
                highlightKey = MINUS_HL;
                break;
            }
            highlightKey = -1;
            cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
            SDL_SetCursor(cursor);
        }

        // Mouse click handling
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_GetMouseState(&xMousePos, &yMousePos);
            if(xMousePos >= 20 && xMousePos <= 150 && yMousePos >= 20 && yMousePos <= 40)
            {
                if(!instanceFlag)
                {
                    sortClicked = SS_CLICKED;
                    instanceFlag = true;
                }
                break;
            }
            if(xMousePos >= 20 && xMousePos <= 150 && yMousePos >= 80 && yMousePos <= 100)
            {
                if(!instanceFlag)
                {
                    sortClicked = IS_CLICKED;
                    instanceFlag = true;
                }
                break;
            }
            if(xMousePos >= 20 && xMousePos <= 150 && yMousePos >= 140 && yMousePos <= 160)
            {
                if(!instanceFlag)
                {
                    sortClicked = SH_CLICKED;
                    instanceFlag = true;
                }
                break;
            }
            if(xMousePos >= 20 && xMousePos <= 80 && yMousePos >= 240 && yMousePos <= 260)
            {
                if(pause)   pause = false;
                else        pause = true;
                break;
            }
            // reset click event
            if(xMousePos >= 100 && xMousePos <= 160 && yMousePos >= 240 && yMousePos <= 260)
            {
                functionClicked = RESET_CLICKED;
                break;
            }
            // '+' and '-' clicks
            if(xMousePos >= 150 && xMousePos <= 170 && yMousePos >= 300 && yMousePos <= 320)
            {
                if(delay > 0)   delay -= 5;
                else            delay = 0;
                break;
            }
            if(xMousePos >= 20 && xMousePos <= 40 && yMousePos >= 300 && yMousePos <= 320)
            {
                if(delay < 250) delay += 5;
                else            delay = 250;
                break;
            }

        }
    }
}

void EventHandler::reset()
{
    quit = false;
    instanceFlag = false;
    pause = false;

    highlightKey = -1;
    sortClicked = -1;
    functionClicked = -1;
}

/** Getter Functions **/
bool EventHandler::quitProgram()                { return quit; }

int EventHandler::getSortSelection()            { return sortClicked; }

int EventHandler::getFunctionSelection()        { return functionClicked; }

bool EventHandler::isPauseSelected()            { return pause; }

int EventHandler::highlightEvent()              { return highlightKey; }

int EventHandler::getDelay()                    { return delay; }

/** Setter Functions **/
void EventHandler::setSortedComplete()          { sortClicked = -1; }
