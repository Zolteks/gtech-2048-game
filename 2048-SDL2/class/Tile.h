#pragma once
#include "GameObject.h"

class Tile : public GameObject {
public:
    Tile(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color, int value);
    int getVal();

    // Ajoutez d'autres m�thodes sp�cifiques aux tuiles ici
private:
    int value;
};