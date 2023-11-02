#pragma once

#include <vector>
#include "tile.h"

class Grid {
public:
    Grid(SDL_Renderer* renderer, int rows, int columns, int tileSize, int tileSpacing);

    void draw();

   /* bool checkFreeTiles();

    void newFreeTile(int x, int y);

    Tile getFreeTile();

    void spawnBlock(int useCase);

    void merge(int direction);

    void moveBlocks(int direction);

    bool checkVictory();

    int checkMerge();*/

private:
    SDL_Renderer* renderer;
    int rows;
    int columns;
    int tileSize;
    int tileSpacing;
    std::vector<std::vector<Tile>> grid;
};


    