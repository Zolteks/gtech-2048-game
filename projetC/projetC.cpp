#include <iostream>
#include <stdio.h>
#include <vector>
#include <windows.h>

using namespace std;

class Grid
{
public:
    vector<vector<int>> grid;
    int gridSize;
    Grid( int size )
    {
        this->gridSize = size;
        this->grid.resize(size);
        for (int i = 0; i < size; i++)
        {
            this->grid[i].resize(size);
        }
    }

    void draw()
    {
        for (int i = 0; i < this->gridSize; i++)
        {
            for (int j = 0; j < this->gridSize; j++)
            {
                this->grid[i][j] = 0;
                printf("%d ", this->grid[i][j]);
            }
            printf("\n");
        }
    }

    void spawnBlock()
    {

    }

    void moveBlocks(char direction)
    {
        int xMove, yMove;

        switch (direction)
        {
        case 'up':
            yMove = -1;
        case 'down':
            yMove = 1;
        case 'left':
            xMove = -1;
        case 'right':
            xMove = 1;
        }

        for (int y = 0; y < this->gridSize; y++)
        {
            for (int x = 0; x < this->gridSize; x++)
            {
                if (x+xMove > -1 && x+xMove < this->gridSize && y + yMove > -1 && y + yMove < this->gridSize)
                {
                    if (this->grid[x + xMove][y + yMove] == 0)
                    {

                    }
                }
            }
        }
    }
};

class Game :
{
public:
    Game()
    {
        cout << "A toi de jouer !" << endl;
    }

    void moveInput() {
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
                cout << "HAUT" << endl;
                while ((GetAsyncKeyState(VK_UP) & 0x8000) != 0)
                {
                    Sleep(1);
                }
            }
            if ((GetAsyncKeyState(VK_DOWN) & 0x8000) != 0)
            {
                cout << "BAS" << endl;
                while ((GetAsyncKeyState(VK_DOWN) & 0x8000) != 0)
                {
                    Sleep(1);
                }
            }
            if ((GetAsyncKeyState(VK_LEFT) & 0x8000) != 0)
            {
                cout << "GAUCHE" << endl;
                while ((GetAsyncKeyState(VK_LEFT) & 0x8000) != 0)
                {
                    Sleep(1);
                }
            }
            if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0)
            {
                cout << "DROITE" << endl;
                while ((GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0)
                {
                    Sleep(1);
                }
            }
        }
    }
};

int main()
{
    Grid grid(4);
    grid.draw();
    Game game();
    game.moveInput();
}