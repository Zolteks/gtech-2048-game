#include <iostream>
#include <SDL.h>

#include "class/GameObject.h"
#include "class/Window.h"

using namespace std;

GameObject::GameObject(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color)
    : renderer(renderer), x(x), y(y), width(width), height(height), color(color)
{
    rect = { x, y, width, height };
}

GameObject::~GameObject()
{

}

void GameObject::draw() 
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}
