#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Grid
{
public:
    vector<vector<int>> grid;
    int gridSize;
    Grid(int size)
    {
        cout << "constucted" << endl;
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
        this->grid[1][1] = 1;
    }

    //setfill() permet de remplir des cases vides

    void moveBlocks(char keyInput)
    {
        cout << "Mouvement " << keyInput << endl;
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
                //grid.moveBlocks('HAUT');
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
    cout << "start of Main" << endl << endl;
    bool loop = true;
    Grid grid(4);
    grid.spawnBlock();
    grid.draw();
    while (loop)
    {
        User user('p');
        user.moveInput();
        if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0)
        {
            loop = false;
        }
    }
    cout << endl << "end of Main" << endl;
    exit(0);
}