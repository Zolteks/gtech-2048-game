#include <iostream>
#include <SDL.h>

#include "class/Window.h"

using namespace std;

Window::Window(int width, int height, bool* error)
{

    *error = false;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        *error = true;
        return;
    }

    //Create window
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        *error = true;
        return;
    }
}

Window::~Window()
{
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

bool Window::createRenderer()
{
    bool success = true;
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL)
    {
        cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
        return false;
    }

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    return success;
}

void Window::update()
{
    //Update screen
    SDL_RenderPresent(gRenderer);
}