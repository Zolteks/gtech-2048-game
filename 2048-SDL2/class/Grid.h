#pragma once

#include <vector>
#include "Tile.h"

using namespace std;

class Grid
{
public:
    vector<vector<Tile>> grid;
    vector<Tile> freeTiles;
    int gridSize;
    Grid(int size = 4);

    void draw();

    bool checkFreeTiles();

    void newFreeTile(int x, int y);

    Tile getFreeTile();

    void spawnBlock(int useCase);

    void merge(int direction);

    void moveBlocks(int direction);

    bool checkVictory();

    int checkMerge();
};