#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <shellapi.h>

using namespace std;

class Grid
{
public:
    vector<vector<int>> grid;
    int gridSize;
    Grid(int size)
    {
        printf("constucted\n");
        this->gridSize = size;
        this->grid.resize(size);
        for (int i = 0; i < size; i++)
        {
            this->grid[i].resize(size);
        }
    }

    void init()
    {
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
        printf("passage inside draw\n\n");
        for (int i = 0; i < this->gridSize; i++)
        {
            for (int j = 0; j < this->gridSize; j++)
            {
                //printf("before this.grid: i=%d, j=%d\n", i, j);
                printf("%d ", this->grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    void spawnBlock()
    {
        this->grid[1][1] = 1;
    }

    //setfill() permet de remplir des cases vides

    void moveBlocks(char blocks)
    {
        char keyInput;
        //cin.get(keyInput);
        //cout << "Touche appuyer : " << keyInput << endl;
        
    }
};

class User
{
public:
    char player;
    User(char user)
    {
        cout << "A toi de jouer !" << endl;
        this->player = user;
    }

    void moveInput() {
        int i = 0;
        while (i == 0)
        {
            if ((GetAsyncKeyState(VK_UP) & 0x8000) != 0)
            {
                cout << "HAUT" << endl;
                i++;
            }
            if ((GetAsyncKeyState(VK_DOWN) & 0x8000) != 0)
            {
                cout << "BAS" << endl;
                i++;
            }
            if ((GetAsyncKeyState(VK_LEFT) & 0x8000) != 0)
            {
                cout << "GAUCHE" << endl;
                i++;
            }
            if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0)
            {
                cout << "DROITE" << endl;
                i++;
            }
        }
    }
};

int main()
{
    printf("start of Main\n\n");
    Grid grid(4);
    grid.init();
    grid.spawnBlock();
    grid.draw();
    User user();
    user.moveInput();
    printf("end of Main\n\n");
    exit(0);
}