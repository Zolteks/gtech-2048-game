#include <iostream>
#include <SDL.h>
#include <vector>
#include <string>
#include <SDL_ttf.h>

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

    if (TTF_Init() == -1) {
        cout << "Failed to initialize TTF!" << endl;
        *error = true;
        return;
    }

    //Initialistaion de SDL_TTF
    TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
    if (!font)
    {
        cout << "Failed to initialize ttf : " << SDL_GetError() << endl;
        *error = true;
        return;
    }

    //Initialistaion des Textures
    SDL_Color color;
    for (int i = 2; i <= 2048; i = i * 2)
    {
        string textValue = to_string(i);
        if (i <= 4)
            color = { 105, 105, 105, 255 };
        else
            color = { 255, 245, 238, 255 };
        
        pSurface = TTF_RenderText_Solid(font, textValue.c_str(), color);
        pTexture = SDL_CreateTextureFromSurface(gRenderer, pSurface);
        
        SDL_FreeSurface(pSurface);

        textures[i] = pTexture;
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