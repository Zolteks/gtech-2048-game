#pragma once
#include <SDL.h>

class GameObject
{
public:
    int x, y, w, h;
    GameObject();

    void resize();

    void draw(SDL_Renderer* gRenderer);

};