#pragma once
#include <SDL.h>
#include <SDL_render.h>

class GameObject {
public:
    GameObject(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color);

    ~GameObject();

    void draw();

    // Ajoutez d'autres méthodes si nécessaire
private:
    SDL_Renderer* renderer;
    int x, y, width, height;
    SDL_Color color;
};