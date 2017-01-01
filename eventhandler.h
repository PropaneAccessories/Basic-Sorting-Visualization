#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "SDL.h"

class EventHandler
{
public:
    EventHandler();
    void handleEvents();
    bool quitProgram();

    enum highlights
    {
        SELECTIONSORT_HL, INSERTIONSORT_HL,
        SHELLSORT_HL, PAUSE_HL, RESET_HL,
        PLUS_HL, MINUS_HL
    };

    enum clicked
    {
        SS_CLICKED, IS_CLICKED, SH_CLICKED,
        PAUSE_CLICKED, RESET_CLICKED
    };
    int highlightEvent();
    int getDelay();
    int getSortSelection();
    int getFunctionSelection();
    bool isPauseSelected();
    void reset();
    void setSortedComplete();

private:
    SDL_Event event;
    SDL_Cursor* cursor;
    bool quit;
    int xMousePos;
    int yMousePos;
    int highlightKey;
    int delay;
    int sortClicked;
    int functionClicked;
    bool pause;
    bool instanceFlag;
};

#endif // EVENTHANDLER_H
