#include <iostream>
#include <SDL.h>

#include "class/GameObject.h"
#include "class/Window.h"

using namespace std;

GameObject::GameObject()
{
    
}

void GameObject::resize()
{

}

void GameObject::draw(SDL_Renderer* gRenderer)
{
    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    SDL_SetRenderDrawColor(gRenderer, 255, 192, 203, 0xFF);
    SDL_RenderFillRect(gRenderer, &fillRect);
}