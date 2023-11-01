#pragma once
#include <SDL.h>

class GameObject
{
public:
    int x, y, w, h;
    GameObject();

    ~GameObject();

    void draw(SDL_Renderer* gRenderer);

};