#pragma once
#include "GameObject.h"
#include <iostream>
#include <map>

class Tile : public GameObject {
public:
    Tile(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color, int value);

    int getValue();

    int getX();

    int getY();

    void setValue(int value);

    void draw() override;

protected:
    std::map<int, SDL_Texture*>* textures;

    int value;
    SDL_Texture* pNumberTexture;
    std::string textValue;
};