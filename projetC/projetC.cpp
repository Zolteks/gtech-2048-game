#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
//setfill() permet de remplir des cases vides

class Grid
{
public:
    vector<vector<int>> grid;
    int gridSize;
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
            }
        }
    }

    void draw()
    {
        cout << "passage inside draw" << endl << endl;
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

    void spawnBlock()
    {
        this->grid[1][3] = 1;
    }

    void checkGrid(int yMove, int xMove)
    {

    }

    void moveBlocks(int direction)
    {
        int xMove = 0;
        int yMove = 0;

        switch (direction)
        {
        case 0:
            // up
            yMove = -1;
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
                    }
                }
            }
            break;
        case 3:
            // right
            for (int ligne = 0; ligne < this->gridSize; ligne++)
            {
                for (int colonne = this->gridSize-1; colonne > 0; colonne--)
                {
                    if (this->grid[ligne][colonne] != 0)
                        continue;
                    for (int fullCell = colonne - 1; fullCell > -1; fullCell--)
                    {
                        if (this->grid[ligne][fullCell] == 0)
                            continue;
                        this->grid[ligne][colonne] = this->grid[ligne][fullCell];
                        this->grid[ligne][fullCell] = 0;
                    }
                }
            }
            break;
        }


    }
};

class Game
{
public:
    Game()
    {
        cout << "A toi de jouer !" << endl;
    }

    int moveInput() {
        bool playing = true;
        while (playing)
        {

            if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0)
            {
                cout << endl << "QUIT" << endl;
                playing = false;
            }
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
        }
    }
};

int main()
{
    cout << "Start of main" << endl << endl;
    bool loop = true;
    Grid grid(4);
    grid.spawnBlock();
    grid.draw();
    Game game;
    while (loop)
    {
        grid.moveBlocks(game.moveInput());
        grid.draw();
        if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0)
        {
            loop = false;
        }
    }
    cout << endl << "End of main" << endl;
    exit(0);
}