#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <tuple>

using namespace std;
//setfill() permet de remplir des cases vides

class Tile
{
public:
    int x, y, val;

    Tile(int x, int y, int val = 2)
    {
        this->x = x;
        this->y = y;
        this->val = val;
    }

    int getVal()
    {
        return this->val;
    }

    int getX()
    {
        return this->x;
    }

    int getY()
    {
        return this->y;
    }
};

class Check
{
public:
    tuple<bool, int, int, int> chekMerge(vector<vector<int>> grid, int gridSize, int direction)
    {

        switch (direction)
        {
        case 0:
            // up
            for (int ligne = 0; ligne < gridSize; ligne++)
            {
                for (int colonne = 0; colonne < gridSize; colonne++)
                {
                    if (grid[ligne][colonne] == 0)
                        continue;

                    for (int sameCell = ligne + 1; sameCell < gridSize; sameCell++)
                    {
                        if (grid[sameCell][colonne] == 0)
                            continue;
                        if (grid[ligne][colonne] != grid[sameCell][colonne])
                            return { false, ligne, colonne, sameCell };

                        return { true, ligne, colonne, sameCell };
                    }
                }
            }
            return { false, 0, 0, 0 };
        case 1:
            // down
            for (int ligne = gridSize - 1; ligne > 0; ligne--)
            {
                for (int colonne = 0; colonne < gridSize; colonne++)
                {
                    if (grid[ligne][colonne] == 0)
                        continue;

                    for (int sameCell = ligne - 1; sameCell > -1; sameCell--)
                    {
                        if (grid[sameCell][colonne] == 0)
                            continue;
                        if (grid[ligne][colonne] != grid[sameCell][colonne])
                            return { false, ligne, colonne, sameCell };

                        return { true, ligne, colonne, sameCell };
                    }
                }
            }
            return { false, 0, 0, 0 };
        case 2:
            // left
            for (int ligne = 0; ligne < gridSize; ligne++)
            {
                for (int colonne = 0; colonne < gridSize; colonne++)
                {
                    if (grid[ligne][colonne] == 0)
                        continue;

                    for (int sameCell = colonne + 1; sameCell < gridSize; sameCell++)
                    {
                        if (grid[ligne][sameCell] == 0)
                            continue;
                        if (grid[ligne][colonne] != grid[ligne][sameCell])
                            return { false, ligne, colonne, sameCell };

                        return { true, ligne, colonne, sameCell };
                    }
                }
            }
            return { false, 0, 0, 0 };
        case 3:
            // right
            for (int ligne = 0; ligne < gridSize; ligne++)
            {
                for (int colonne = gridSize - 1; colonne > 0; colonne--)
                {
                    if (grid[ligne][colonne] == 0)
                        continue;

                    for (int sameCell = colonne - 1; sameCell > -1; sameCell--)
                    {
                        if (grid[ligne][sameCell] == 0)
                            continue;
                        if (grid[ligne][colonne] != grid[ligne][sameCell])
                            return { false, ligne, colonne, sameCell };

                        return { true, ligne, colonne, sameCell };
                    }
                }
            }
            return { false, 0, 0, 0 };
        }
    }

    void checkMove()
    {

    }
};

class Grid
{
public:
    vector<vector<int>> grid;
    vector<Tile> freeSpaces;
    int gridSize;
    Check chekMerge();
    Grid(int size)
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
                this->grid[i][j] = 0;
                Tile tile(i, j, 2);
                this->freeSpaces.push_back(tile);
            }
        }
    }

    void draw()
    {
        system("cls");
        for (int i = 0; i < this->gridSize; i++)
        {
            for (int j = 0; j < this->gridSize; j++)
            {
                cout << "|" << this->grid[i][j];
            }
            cout << "|" << endl;
        }
        cout << endl;
    }

    int spawnBlock()
    {
        int range = this->freeSpaces.size();
        if (range == 0)
            return 0;
        int index = rand() % range;
        Tile tileToAdd = this->freeSpaces[index];
        this->freeSpaces.erase(this->freeSpaces.begin() + index);
        this->grid[tileToAdd.getX()][tileToAdd.getY()] = tileToAdd.getVal();
    }

    void merge(int direction, auto [okCheck, ligne, colonne, sameCell] = chekMerge())
    {
        switch (direction)
        {
        case 0:
            // up
            if (okCheck == false)
                break;

            this->grid[ligne][colonne] = this->grid[ligne][colonne] * 2;
            this->grid[sameCell][colonne] = 0;
            break;
        case 1:
            // down
            for (int ligne = this->gridSize - 1; ligne > 0; ligne--)
            {
                for (int colonne = 0; colonne < this->gridSize; colonne++)
                {
                    if (this->grid[ligne][colonne] == 0)
                        continue;

                    for (int sameCell = ligne - 1; sameCell > -1; sameCell--)
                    {
                        if (this->grid[sameCell][colonne] == 0)
                            continue;
                        if (this->grid[ligne][colonne] != this->grid[sameCell][colonne])
                            break;

                        this->grid[ligne][colonne] = this->grid[ligne][colonne] * 2;
                        this->grid[sameCell][colonne] = 0;
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
                    if (this->grid[ligne][colonne] == 0)
                        continue;

                    for (int sameCell = colonne + 1; sameCell < this->gridSize; sameCell++)
                    {
                        if (this->grid[ligne][sameCell] == 0)
                            continue;
                        if (this->grid[ligne][colonne] != this->grid[ligne][sameCell])
                            break;

                        this->grid[ligne][colonne] = this->grid[ligne][colonne] * 2;
                        this->grid[ligne][sameCell] = 0;
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
                    if (this->grid[ligne][colonne] == 0)
                        continue;

                    for (int sameCell = colonne - 1; sameCell > -1; sameCell--)
                    {
                        if (this->grid[ligne][sameCell] == 0)
                            continue;
                        if (this->grid[ligne][colonne] != this->grid[ligne][sameCell])
                            break;

                        this->grid[ligne][colonne] = this->grid[ligne][colonne] * 2;
                        this->grid[ligne][sameCell] = 0;
                        break;
                    }
                }
            }
            break;
        }
    }

    void moveBlocks(int direction)
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
                    if (this->grid[ligne][colonne] != 0)
                        continue;

                    for (int fullCell = ligne + 1; fullCell < this->gridSize; fullCell++)
                    {
                        if (this->grid[fullCell][colonne] == 0)
                            continue;
                        this->grid[ligne][colonne] = this->grid[fullCell][colonne];
                        this->grid[fullCell][colonne] = 0;
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
                    if (this->grid[ligne][colonne] != 0)
                        continue;

                    for (int fullCell = ligne - 1; fullCell > -1; fullCell--)
                    {
                        if (this->grid[fullCell][colonne] == 0)
                            continue;
                        this->grid[ligne][colonne] = this->grid[fullCell][colonne];
                        this->grid[fullCell][colonne] = 0;
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
                    if (this->grid[ligne][colonne] != 0)
                        continue;

                    for (int fullCell = colonne + 1; fullCell < this->gridSize; fullCell++)
                    {
                        if (this->grid[ligne][fullCell] == 0)
                            continue;
                        this->grid[ligne][colonne] = this->grid[ligne][fullCell];
                        this->grid[ligne][fullCell] = 0;
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
                    if (this->grid[ligne][colonne] != 0)
                        continue;

                    for (int fullCell = colonne - 1; fullCell > -1; fullCell--)
                    {
                        if (this->grid[ligne][fullCell] == 0)
                            continue;
                        this->grid[ligne][colonne] = this->grid[ligne][fullCell];
                        this->grid[ligne][fullCell] = 0;
                        break;
                    }
                }
            }
            break;
        }
    }

    int checkGrid()
    {
        if (spawnBlock() != 0)
            return 0;

        for (int i = 0; i < this->gridSize; i++)
        {
            for (int j = 0; j < this->gridSize; j++)
            {
                
            }
        }
    }
};

class Game
{
public:

    int moveInput() {
        cout << "A toi de jouer !" << endl;
        bool playing = true;
        while (playing)
        {
            if ((GetAsyncKeyState(VK_UP) & 0x8000) != 0)
            {
                while ((GetAsyncKeyState(VK_UP) & 0x8000) != 0)
                {
                    Sleep(1);

                }
                return 0;
            }
            if ((GetAsyncKeyState(VK_DOWN) & 0x8000) != 0)
            {
                while ((GetAsyncKeyState(VK_DOWN) & 0x8000) != 0)
                {
                    Sleep(1);
                }
                return 1;
            }
            if ((GetAsyncKeyState(VK_LEFT) & 0x8000) != 0)
            {
                while ((GetAsyncKeyState(VK_LEFT) & 0x8000) != 0)
                {
                    Sleep(1);
                }
                return 2;
            }
            if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0)
            {
                while ((GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0)
                {
                    Sleep(1);
                }
                return 3;
            }
            if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0)
            {
                cout << endl << "QUIT" << endl;
                playing = false;
            }
        }
        return 4;
    }
};

int main()
{
    int size = 4;
    int direction;
    bool loop = true;
    Grid grid(size);
    grid.spawnBlock();
    grid.draw();
    Game game;
    Check check;
    while (loop)
    {
        direction = game.moveInput();
        if (direction == 4)
            loop = false;
        check.chekMerge(grid, size, direction);
        grid.merge(direction);
        grid.moveBlocks(direction);
        grid.spawnBlock();
        grid.draw();
    }
    cout << endl << "End of main" << endl;
    exit(0);
}