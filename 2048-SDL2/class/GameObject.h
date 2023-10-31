#pragma once

class GameObject
{
public:

    GameObject();
    ~GameObject();

    void resize();

    void draw(SDL_Renderer* gRenderer, SDL_Rect fillRect);

};