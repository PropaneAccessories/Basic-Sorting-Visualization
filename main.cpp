/**
A program to visualize the following 3 basic sorting algorithms:
    Selection Sort, Insertion Sort, & Shellsort
The entire program is rendered using the SDL and SDL extension libraries.
**/

#include "SDL.h"
#include "SDL_ttf.h"
#include "mainprogram.h"
#include "bars.h"
#include "eventhandler.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "shellsort.h"

using namespace std;

int main(int argc, char *argv[])
{
    MainProgram application;
    Bars data;
    EventHandler e;
    SelectionSort ss;
    InsertionSort is;
    Shellsort sh;
    bool sorted = false;

    while(!e.quitProgram())
    {
        e.handleEvents();

        if(!e.isPauseSelected() && !sorted)
        {
            switch(e.getSortSelection())
            {
            case EventHandler::SS_CLICKED:
                {
                    ss.ssAlgorithm(data.getRectArray());
                    sorted = ss.isSorted();
                    break;
                }
            case EventHandler::IS_CLICKED:
                {
                    is.isAlgorithm(data.getRectArray());
                    sorted = is.isSorted();
                    break;
                }
            case EventHandler::SH_CLICKED:
                {
                    sh.shAlgorithm(data.getRectArray());
                    sorted = sh.isSorted();
                    break;
                }
            } // switch
        }   // if(!e.isPauseSelected())

        if(e.getFunctionSelection() == EventHandler::RESET_CLICKED)
        {
            ss.reset();
            is.reset();
            sh.reset();
            data.reset();
            e.reset();
            sorted = false;
        }

        application.render(data.getRectArray(), ss, is, sh, e);
        SDL_Delay(e.getDelay());
    }

    return 0;
}
