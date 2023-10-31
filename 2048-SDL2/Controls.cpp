#include <iostream>
#include <SDL.h>

#include "class/Controls.h"

Controls::Controls()
{
    enum KeyPressSurfaces
    {
        KEY_PRESS_SURFACE_DEFAULT,
        KEY_PRESS_SURFACE_UP,
        KEY_PRESS_SURFACE_DOWN,
        KEY_PRESS_SURFACE_LEFT,
        KEY_PRESS_SURFACE_RIGHT,
        KEY_PRESS_SURFACE_TOTAL
    };
}

void Controls::moveLoop(SDL_Event event, SDL_Surface surface)
{
    while (SDL_PollEvent(&event) != 0)
    {
        //User requests quit
        if (event.type == SDL_QUIT)
        {
            return;
        }
        //User presses a key
        else if (event.type == SDL_KEYDOWN)
        {
            //Select surfaces based on key press
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                surface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                break;

            case SDLK_DOWN:
                surface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                break;

            case SDLK_LEFT:
                surface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                break;

            case SDLK_RIGHT:
                surface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                break;

            default:
                surface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                break;
            }
        }
    }
}