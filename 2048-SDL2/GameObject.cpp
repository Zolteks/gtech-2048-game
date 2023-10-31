#include <iostream>
#include <SDL.h>

#include "class/GameObject.h"
#include "class/Window.h"

using namespace std;

GameObject::GameObject()
{
    
}

GameObject::~GameObject()
{

}

void GameObject::resize()
{

}

void GameObject::draw(SDL_Renderer* gRenderer, SDL_Rect fillRect)
{
    //SDL_Rect fillRect = { x, y, w, h };
    SDL_SetRenderDrawColor(gRenderer, 255, 192, 203, 0xFF);
    SDL_RenderFillRect(gRenderer, &fillRect);
}