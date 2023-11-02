#pragma once
#include "GameObject.h"
#include <string>
#include <SDL_ttf.h>

class Tile : public GameObject {
public:
    Tile(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color, int value);

    int getX();
    int getY();
    int getValue();
    void setValue(int value);

    void draw();
    // Ajoutez d'autres méthodes spécifiques aux tuiles ici
private:
    int value;
    std::string textValue;
    SDL_Texture* textTexture;
    TTF_Font* font;
    SDL_Color textColor;
};