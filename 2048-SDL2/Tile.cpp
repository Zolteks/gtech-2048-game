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

/*
 COLOR_EMPTY = Color.rgb(204, 192, 179);
 COLOR_2 = Color.rgb(238, 228, 218);
 COLOR_4 = Color.rgb(237, 224, 200);
 COLOR_8 = Color.rgb(242, 177, 121);
 COLOR_16 = Color.rgb(245, 149, 99);
 COLOR_32 = Color.rgb(246, 124, 95);
 COLOR_64 = Color.rgb(246, 94, 59);
 COLOR_128 = Color.rgb(237, 207, 114);
 COLOR_256 = Color.rgb(237, 204, 97);
 COLOR_512 = Color.rgb(237, 200, 80);
 COLOR_1024 = Color.rgb(237, 197, 63);
 COLOR_2048 = Color.rgb(237, 194, 46);
 */