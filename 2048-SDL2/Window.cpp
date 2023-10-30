#include <iostream>
#include <SDL.h>

#include "class/Window.h"

using namespace std;

Window::Window()
{

}

bool Window::init()
{
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            //gScreenSurface = SDL_GetWindowSurface(gWindow);
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }

    return success;
}

void Window::update()
{

}

void Window::close()
{
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}