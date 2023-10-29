#include "Tile.h"

Tile::Tile(int x, int y, int val)
{
    this->x = x;
    this->y = y;
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