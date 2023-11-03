#include <iostream>
#include <string>
#include <SDL_ttf.h>
#include "class/Tile.h"

using namespace std;

Tile::Tile(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color, int value)
    : GameObject(renderer, x, y, width, height, color), value(value)
{
    
}

int Tile::getValue()
{
    return value;
}

int Tile::getX()
{
    return x;
}

int Tile::getY()
{
    return y;
}

void Tile::setValue(int value)
{
    this->value = value;
    this->textValue = to_string(value);

    if (value == 0)
        return;

    /*switch (value)
    {
    case 2:
        color = { 238, 228, 218, 255 };
        break;
    case 4:
        color = { 237, 224, 200, 255 };
        break;
    case 8:
        color = { 237, 224, 200, 255 };
        break;
    case 16:
        color = { 242, 177, 121, 255 };
        break;
    case 32:
        color = { 246, 124, 95, 255 };
        break;
    case 64:
        color = { 246, 94, 59, 255 };
        break;
    case 128:
        color = { 237, 207, 114, 255 };
        break;
    case 256:
        color = { 237, 204, 97, 255 };
        break;
    case 512:
        color = { 237, 200, 80, 255 };
        break;
    case 1024:
        color = { 237, 197, 63, 255 };
        break;
    case 2048:
        color = { 237, 194, 46, 255 };
        break;
    }*/

    cout << "La valeur actuelle est " << value << endl;
    pNumberTexture = (*textures)[value];

}

void Tile::draw()
{
    GameObject::draw();
    SDL_RenderCopy(renderer, pNumberTexture, NULL, &rect);
}

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
