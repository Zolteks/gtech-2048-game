#pragma once

class Tile
{
public:
    int x, y, val;

    Tile(int x = 0, int y = 0, int val = 2);

    int getVal();

    int getX();

    int getY();
};