#pragma once
#include "GameObject.h"
#include <iostream>
#include <map>

class Tile : public GameObject {
public:
    Tile(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color, int value, std::map<int, SDL_Texture*>* map);

    int getX();
    int getY();
    int getValue();
    void setValue(int value);
    void draw() override;

protected:
    std::map<int, SDL_Texture*>* textures = NULL;

    int value;
    SDL_Texture* pNumberTexture = NULL;
    std::string textValue;
    SDL_Texture* textTexture;
    TTF_Font* font;
    SDL_Color textColor;
};