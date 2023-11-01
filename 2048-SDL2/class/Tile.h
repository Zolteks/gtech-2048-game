#pragma once
#include "GameObject.h"

class Tile : GameObject
{
public:
    int val;

    Tile(int x = 0, int y = 0, int w = 50, int h = 50, int val = 0);

    int getVal();

    int getX();

    int getY();

    int getWidth();

    int getHeight();
};