#pragma once
#include <SDL.h>

class GameObject
{
public:
    int x, y, w, h;
    #define COLOR_2048 = Color.rgb(237, 194, 46);

    GameObject();
    ~GameObject();

    void draw(SDL_Renderer* gRenderer);

};