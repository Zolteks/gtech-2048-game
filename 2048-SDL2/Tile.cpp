#include "class/Tile.h"

Tile::Tile(int x, int y, int w, int h, int val)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->val = val;
}

int Tile::getVal()
{
    return this->val;
}

int Tile::getX()
{
    return this->x;
}

int Tile::getY()
{
    return this->y;
}

int Tile::getWidth()
{
    return this->w;
}

int Tile::getHeight()
{
    return this->h;
}