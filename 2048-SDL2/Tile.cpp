#include <iostream>
#include <string>
#include <SDL_ttf.h>
#include "class/Tile.h"

Tile::Tile(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color, int value)
    : GameObject(renderer, x, y, width, height, color), pNumberTexture(pNumberTexture), value(value)
{
    
}

int Tile::getValue()
{
    return value;
}

//int Tile::getX()
//{
//    return x;
//}
//
//int Tile::getY()
//{
//    return y;
//}

void Tile::setValue(int value)
{
    this->value = value;
    this->textValue = std::to_string(value);

    if (value == 0)
        return;

    pNumberTexture = (*textures)[value];
 
    /* SDL_Surface textSurface = TTF_RenderText_Solid(font, textValue.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface); */
}

void Tile::draw()
{
    GameObject::draw();
    SDL_RenderCopy(renderer, pNumberTexture, NULL, &rect );
}

//int Tile::getX()
//{
//    return this->x;
//}
//
//int Tile::getY()
//{
//    return this->y;
//}

/*
 SDL_Color COLOR_EMPTY = { 204, 192, 179, 255 };
 SDL_Color COLOR_2 = { 238, 228, 218, 255 };
 SDL_Color COLOR_4 = { 237, 224, 200, 255 };
 SDL_Color COLOR_8 = { 242, 177, 121, 255 };
 SDL_Color COLOR_16 = { 245, 149, 99, 255 };
 SDL_Color COLOR_32 = { 246, 124, 95, 255 };
 SDL_Color COLOR_64 = { 246, 94, 59, 255 };
 SDL_Color COLOR_128 = { 237, 207, 114, 255 };
 SDL_Color COLOR_256 = { 237, 204, 97, 255 };
 SDL_Color COLOR_512 = { 237, 200, 80, 255 };
 SDL_Color COLOR_1024 = { 237, 197, 63, 255 };
 SDL_Color COLOR_2048 = { 237, 194, 46, 255 };
 */
