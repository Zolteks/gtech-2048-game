#include <iostream>

#include "class/Grid.h"

using namespace std;

Grid::Grid(int size)
    {
        this->gridSize = size;
        this->grid.resize(size);
        for (int i = 0; i < size; i++)
        {
            this->grid[i].resize(size);
        }
        //initialisation de la grille
        for (int i = 0; i < this->gridSize; i++)
        {
            for (int j = 0; j < this->gridSize; j++)
            {
                this->grid[i][j].val = 0;
            }
        }
    }

void Grid::draw()
{
    system("cls");
    for (int i = 0; i < this->gridSize; i++)
    {
        for (int j = 0; j < this->gridSize; j++)
        {
            cout << "|" << this->grid[i][j].val << "\t";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

bool Grid::checkFreeTiles()
{
    freeTiles.clear();
    int counter = 0;
    for (int i = 0; i < this->gridSize; i++)
    {
        for (int j = 0; j < this->gridSize; j++)
        {
            if (grid[i][j].getVal() == 0)
            {
                newFreeTile(i, j);
                counter++;
            }
        }
    }
    if (counter == 0)
    {
        // returns true if the grid is full
        return true;
    }
    else
    {
        return false;
    }
}

void Grid::newFreeTile(int x, int y)
{
    Tile newFreeTile(x, y, 0);
    this->freeTiles.push_back(newFreeTile);
}

Tile Grid::getFreeTile()
{
    size_t range = this->freeTiles.size();
    if (range == 0)
    {
        Tile tile(-1, -1);
        return tile;
    }
    int index = rand() % range;
    Tile newTile = this->freeTiles[index];
    this->freeTiles.erase(this->freeTiles.begin() + index);
    return newTile;
}

void Grid::spawnBlock(int useCase = 0)
{
    switch (useCase)
    {
    case 0:
    {
        checkFreeTiles();
        Tile tileToAdd = getFreeTile();
        int tileValue;
        if (rand() % 10 == 0)
            tileValue = 4;
        else
            tileValue = 2;
        grid[tileToAdd.getX()][tileToAdd.getY()].val = tileValue;
        break;
    }
    case 1:
    {
        grid[0][1].val = 1024;
        grid[0][2].val = 1024;
        break;
    }
    }
}

void Grid::merge(int direction)
{
    switch (direction)
    {
    case 0:
        // up
        for (int ligne = 0; ligne < this->gridSize; ligne++)
        {
            for (int colonne = 0; colonne < this->gridSize; colonne++)
            {
                if (this->grid[ligne][colonne].val == 0)
                    continue;

                for (int sameCell = ligne + 1; sameCell < this->gridSize; sameCell++)
                {
                    if (this->grid[sameCell][colonne].val == 0)
                        continue;
                    if (this->grid[ligne][colonne].val != this->grid[sameCell][colonne].val)
                        break;

                    this->grid[ligne][colonne].val = this->grid[ligne][colonne].val * 2;
                    this->grid[sameCell][colonne].val = 0;
                    break;
                }
            }
        }
        break;
    case 1:
        // down
        for (int ligne = this->gridSize - 1; ligne > 0; ligne--)
        {
            for (int colonne = 0; colonne < this->gridSize; colonne++)
            {
                if (this->grid[ligne][colonne].val == 0)
                    continue;

                for (int sameCell = ligne - 1; sameCell > -1; sameCell--)
                {
                    if (this->grid[sameCell][colonne].val == 0)
                        continue;
                    if (this->grid[ligne][colonne].val != this->grid[sameCell][colonne].val)
                        break;

                    this->grid[ligne][colonne].val = this->grid[ligne][colonne].val * 2;
                    this->grid[sameCell][colonne].val = 0;
                    break;
                }
            }
        }
        break;
    case 2:
        // left
        for (int ligne = 0; ligne < this->gridSize; ligne++)
        {
            for (int colonne = 0; colonne < this->gridSize; colonne++)
            {
                if (this->grid[ligne][colonne].val == 0)
                    continue;

                for (int sameCell = colonne + 1; sameCell < this->gridSize; sameCell++)
                {
                    if (this->grid[ligne][sameCell].val == 0)
                        continue;
                    if (this->grid[ligne][colonne].val != this->grid[ligne][sameCell].val)
                        break;

                    this->grid[ligne][colonne].val = this->grid[ligne][colonne].val * 2;
                    this->grid[ligne][sameCell].val = 0;
                    break;
                }
            }
        }
        break;
    case 3:
        // right
        for (int ligne = 0; ligne < this->gridSize; ligne++)
        {
            for (int colonne = this->gridSize - 1; colonne > 0; colonne--)
            {
                if (this->grid[ligne][colonne].val == 0)
                    continue;

                for (int sameCell = colonne - 1; sameCell > -1; sameCell--)
                {
                    if (this->grid[ligne][sameCell].val == 0)
                        continue;
                    if (this->grid[ligne][colonne].val != this->grid[ligne][sameCell].val)
                        break;

                    this->grid[ligne][colonne].val = this->grid[ligne][colonne].val * 2;
                    this->grid[ligne][sameCell].val = 0;
                    break;
                }
            }
        }
        break;
    }
}

void Grid::moveBlocks(int direction)
{
    int xMove = 0;
    int yMove = 0;

    switch (direction)
    {
    case 0:
        // up
        for (int ligne = 0; ligne < this->gridSize; ligne++)
        {
            for (int colonne = 0; colonne < this->gridSize; colonne++)
            {
                if (this->grid[ligne][colonne].val != 0)
                    continue;

                for (int fullCell = ligne + 1; fullCell < this->gridSize; fullCell++)
                {
                    if (this->grid[fullCell][colonne].val == 0)
                        continue;
                    this->grid[ligne][colonne].val = this->grid[fullCell][colonne].val;
                    this->grid[fullCell][colonne].val = 0;
                    break;
                }
            }
        }
        break;
    case 1:
        // down
        for (int ligne = this->gridSize - 1; ligne > 0; ligne--)
        {
            for (int colonne = 0; colonne < this->gridSize; colonne++)
            {
                if (this->grid[ligne][colonne].val != 0)
                    continue;

                for (int fullCell = ligne - 1; fullCell > -1; fullCell--)
                {
                    if (this->grid[fullCell][colonne].val == 0)
                        continue;
                    this->grid[ligne][colonne].val = this->grid[fullCell][colonne].val;
                    this->grid[fullCell][colonne].val = 0;
                    break;
                }
            }
        }
        break;
    case 2:
        // left
        for (int ligne = 0; ligne < this->gridSize; ligne++)
        {
            for (int colonne = 0; colonne < this->gridSize; colonne++)
            {
                if (this->grid[ligne][colonne].val != 0)
                    continue;

                for (int fullCell = colonne + 1; fullCell < this->gridSize; fullCell++)
                {
                    if (this->grid[ligne][fullCell].val == 0)
                        continue;
                    this->grid[ligne][colonne].val = this->grid[ligne][fullCell].val;
                    this->grid[ligne][fullCell].val = 0;
                    break;
                }
            }
        }
        break;
    case 3:
        // right
        for (int ligne = 0; ligne < this->gridSize; ligne++)
        {
            for (int colonne = this->gridSize - 1; colonne > 0; colonne--)
            {
                if (this->grid[ligne][colonne].val != 0)
                    continue;

                for (int fullCell = colonne - 1; fullCell > -1; fullCell--)
                {
                    if (this->grid[ligne][fullCell].val == 0)
                        continue;
                    this->grid[ligne][colonne].val = this->grid[ligne][fullCell].val;
                    this->grid[ligne][fullCell].val = 0;
                    break;
                }
            }
        }
        break;
    }
}

bool Grid::checkVictory()
{
    for (int ligne = 0; ligne < gridSize; ligne++)
    {
        for (int colonne = 0; colonne < gridSize; colonne++)
        {
            if (grid[ligne][colonne].val == 2048)
                return true;
        }
    }

    return false;
}

int Grid::checkMerge()
{
    int count = 0;
    for (int ligne = 0; ligne < gridSize; ligne++)
    {
        for (int colonne = 0; colonne < gridSize; colonne++)
        {
            if (colonne + 1 < gridSize && grid[ligne][colonne].val == grid[ligne][colonne + 1].val)
                count++;
            if (colonne - 1 > -1 && grid[ligne][colonne].val == grid[ligne][colonne - 1].val)
                count++;
            if (ligne + 1 < gridSize && grid[ligne][colonne].val == grid[ligne + 1][colonne].val)
                count++;
            if (ligne - 1 > -1 && grid[ligne][colonne].val == grid[ligne - 1][colonne].val)
                count++;
        }
    }
    return count;
}