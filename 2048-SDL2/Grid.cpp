#include <iostream>

#include "class/Grid.h"

using namespace std;

Grid::Grid(SDL_Renderer* renderer, int rows, int columns, int tileSize, int tileSpacing) 
    : renderer(renderer), rows(rows), columns(columns), tileSize(tileSize), tileSpacing(tileSpacing){
    // Initialisez la grille de tuiles
    grid.resize(rows, std::vector<Tile>(columns, Tile(renderer, 0, 0, tileSize, tileSize, { 255, 255, 255, 255 }, 0)));

    // Calculez la largeur et la hauteur de l'espace entre les tuiles
    gridSize = rows;
    int spacingX = tileSpacing;
    int spacingY = tileSpacing;

    // Initialisation des valeurs des tuiles à zéro et avec un espacement
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            int tileX = col * (tileSize + spacingX);
            int tileY = row * (tileSize + spacingY);
            grid[row][col] = Tile(renderer, tileX, tileY, tileSize, tileSize, { 204, 192, 179, 255 }, 0);
        }
    }
}

void Grid::draw() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            grid[row][col].draw();
        }
    }
}

bool Grid::checkFreeTiles()
{
    int spacingX = tileSpacing;
    int spacingY = tileSpacing;
    freeTiles.clear();
    int counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (grid[i][j].getValue() == 0)
            {
                newFreeTile(i, j, 0, 0);
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

void Grid::newFreeTile(int x, int y, int w, int h)
{
    this->freeTiles.push_back(Tile(renderer, x, y, w, h, { 204, 192, 179, 255 }, 0));
}

Tile Grid::getFreeTile()
{
    size_t range = this->freeTiles.size();
    if (range == 0)
    {
        return Tile(renderer, -1, -1, tileSize, tileSize, { 204, 192, 179, 255 }, 0);
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
        printf("%d, %d\n", tileToAdd.getX(), tileToAdd.getY());
        grid[tileToAdd.getX()][tileToAdd.getY()].setValue(tileValue);
        break;
    }
    case 1:
    {
        grid[0][1].setValue(1024);
        grid[0][2].setValue(1024);
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
                if (this->grid[ligne][colonne].getValue() == 0)
                    continue;

                for (int sameCell = ligne + 1; sameCell < this->gridSize; sameCell++)
                {
                    if (this->grid[sameCell][colonne].getValue() == 0)
                        continue;
                    if (this->grid[ligne][colonne].getValue() != this->grid[sameCell][colonne].getValue())
                        break;

                    this->grid[ligne][colonne].setValue(this->grid[ligne][colonne].getValue() * 2);
                    this->grid[sameCell][colonne].setValue(0);
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
                if (this->grid[ligne][colonne].getValue() == 0)
                    continue;

                for (int sameCell = ligne - 1; sameCell > -1; sameCell--)
                {
                    if (this->grid[sameCell][colonne].getValue() == 0)
                        continue;
                    if (this->grid[ligne][colonne].getValue() != this->grid[sameCell][colonne].getValue())
                        break;

                    this->grid[ligne][colonne].setValue(this->grid[ligne][colonne].getValue() * 2);
                    this->grid[sameCell][colonne].setValue(0);
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
                if (this->grid[ligne][colonne].getValue() == 0)
                    continue;

                for (int sameCell = colonne + 1; sameCell < this->gridSize; sameCell++)
                {
                    if (this->grid[ligne][sameCell].getValue() == 0)
                        continue;
                    if (this->grid[ligne][colonne].getValue() != this->grid[ligne][sameCell].getValue())
                        break;

                    this->grid[ligne][colonne].setValue(this->grid[ligne][colonne].getValue() * 2);
                    this->grid[ligne][sameCell].setValue(0);
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
                if (this->grid[ligne][colonne].getValue() == 0)
                    continue;

                for (int sameCell = colonne - 1; sameCell > -1; sameCell--)
                {
                    if (this->grid[ligne][sameCell].getValue() == 0)
                        continue;
                    if (this->grid[ligne][colonne].getValue() != this->grid[ligne][sameCell].getValue())
                        break;

                    this->grid[ligne][colonne].setValue(this->grid[ligne][colonne].getValue() * 2);
                    this->grid[ligne][sameCell].setValue(0);
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
                if (this->grid[ligne][colonne].getValue() != 0)
                    continue;

                for (int fullCell = ligne + 1; fullCell < this->gridSize; fullCell++)
                {
                    if (this->grid[fullCell][colonne].getValue() == 0)
                        continue;
                    this->grid[ligne][colonne].setValue(this->grid[fullCell][colonne].getValue());
                    this->grid[fullCell][colonne].setValue(0);
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
                if (this->grid[ligne][colonne].getValue() != 0)
                    continue;

                for (int fullCell = ligne - 1; fullCell > -1; fullCell--)
                {
                    if (this->grid[fullCell][colonne].getValue() == 0)
                        continue;
                    this->grid[ligne][colonne].setValue(this->grid[fullCell][colonne].getValue());
                    this->grid[fullCell][colonne].setValue(0);
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
                if (this->grid[ligne][colonne].getValue() != 0)
                    continue;

                for (int fullCell = colonne + 1; fullCell < this->gridSize; fullCell++)
                {
                    if (this->grid[ligne][fullCell].getValue() == 0)
                        continue;
                    this->grid[ligne][colonne].setValue(this->grid[ligne][fullCell].getValue());
                    this->grid[ligne][fullCell].setValue(0);
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
                if (this->grid[ligne][colonne].getValue() != 0)
                    continue;

                for (int fullCell = colonne - 1; fullCell > -1; fullCell--)
                {
                    if (this->grid[ligne][fullCell].getValue() == 0)
                        continue;
                    this->grid[ligne][colonne].setValue(this->grid[ligne][fullCell].getValue());
                    this->grid[ligne][fullCell].setValue(0);
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
            if (grid[ligne][colonne].getValue() == 2048)
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
            if (colonne + 1 < gridSize && grid[ligne][colonne].getValue() == grid[ligne][colonne + 1].getValue())
                count++;
            if (colonne - 1 > -1 && grid[ligne][colonne].getValue() == grid[ligne][colonne - 1].getValue())
                count++;
            if (ligne + 1 < gridSize && grid[ligne][colonne].getValue() == grid[ligne + 1][colonne].getValue())
                count++;
            if (ligne - 1 > -1 && grid[ligne][colonne].getValue() == grid[ligne - 1][colonne].getValue())
                count++;
        }
    }
    return count;
}