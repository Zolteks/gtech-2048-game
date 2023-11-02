#include <iostream>
#include <string>
#include <SDL_ttf.h>
#include "class/Tile.h"
#include <SDL_ttf.h>
#include <string>
#include <iostream>

Tile::Tile(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color, int value)
    : GameObject(renderer, x, y, width, height, color), pNumberTexture(pNumberTexture), value(value)
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
    switch (value)
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
    }

    this->value = value;
    this->textValue = std::to_string(value);

    if (value <= 8)
        this->textColor = { 0, 0, 0, 255 };
    else
        this->textColor = { 255, 255, 255, 255 };

}

void Tile::draw()
{
    SDL_Rect rect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);

    // Cr�ez une surface SDL_ttf � partir du texte
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, textValue.c_str(), textColor);

    if (textSurface) {
        // Cr�ez une texture � partir de la surface
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        // Obtenez les dimensions du texte
        int textWidth = textSurface->w;
        int textHeight = textSurface->h;

        // D�finissez les coordonn�es pour le texte (ajustez-les pour le placement souhait�)
        int textX = x + (width - textWidth) / 2;
        int textY = y + (height - textHeight) / 2;

        // Affichez le texte
        SDL_Rect textRect = { textX, textY, textWidth, textHeight };
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        // Lib�rez la surface et la texture
        SDL_FreeSurface(textSurface);
        //SDL_DestroyTexture(textTexture);
    }
    /*SDL_Surface* textSurface = TTF_RenderText_Solid(font, textValue.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);*/

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
