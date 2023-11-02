#include "class/Tile.h"
#include <SDL_ttf.h>
#include <string>
#include <iostream>

Tile::Tile(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color, int value)
    : GameObject(renderer, x, y, width, height, color), value(value)
{
    font = TTF_OpenFont("arial.ttf", 24);
    if (!font)
    {
        std::cout << "exit" << std::endl;
        
    }
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
    /*STD_map << int, SDL_Color > colorMap{
        {2 , 255, 65 , 248, 255}
    }

    SDL_Color color;
    color = tile.colorMap.find(tile.getValue()))
    SDL_...(renderer, color.r, color.g, color.b, color.a)*/
    switch (value)
    {
    case 2:
        color = { 238, 228, 218, 255 };
    case 4:
        color = { 237, 224, 200, 255 };
    case 8:
        color = { 237, 224, 200, 255 };
    case 16:
        color = { 242, 177, 121, 255 };
    case 32:
        color = { 246, 124, 95, 255 };
    case 64:
        color = { 246, 94, 59, 255 };
    case 128:
        color = { 237, 207, 114, 255 };
    case 256:
        color = { 237, 204, 97, 255 };
    case 512:
        color = { 237, 200, 80, 255 };
    case 1024:
        color = { 237, 197, 63, 255 };
    case 2048:
        color = { 237, 194, 46, 255 };
    }

    std::cout << "value updated to: " << value << std::endl;

    this->value = value;
    this->textValue = std::to_string(value);

    if (value <= 4)
        this->textColor = { 255, 255, 255, 255 };
    else
        this->textColor = { 0, 0, 0, 255 };

}

void Tile::draw()
{
    SDL_Rect rect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);

    // Créez une surface SDL_ttf à partir du texte
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, textValue.c_str(), textColor);

    if (textSurface) {
        // Créez une texture à partir de la surface
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        // Obtenez les dimensions du texte
        int textWidth = textSurface->w;
        int textHeight = textSurface->h;

        // Définissez les coordonnées pour le texte (ajustez-les pour le placement souhaité)
        int textX = x + (width - textWidth) / 2;
        int textY = y + (height - textHeight) / 2;

        // Affichez le texte
        SDL_Rect textRect = { textX, textY, textWidth, textHeight };
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        // Libérez la surface et la texture
        SDL_FreeSurface(textSurface);
        //SDL_DestroyTexture(textTexture);
    }
    /*SDL_Surface* textSurface = TTF_RenderText_Solid(font, textValue.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);*/

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
