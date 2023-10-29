#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
//setfill() permet de remplir des cases vides

class Tile
{
public:
    int x, y, val;

    Tile(int x = 0, int y = 0, int val = 2)
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

class Grid
{
public:
    vector<vector<Tile>> grid;
    vector<Tile> freeTiles;
    int gridSize;
    Grid(int size = 4)
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

    void draw()
    {
        system("cls");
        for (int i = 0; i < this->gridSize; i++)
        {
            for (int j = 0; j < this->gridSize; j++)
            {
                cout << "|" << this->grid[i][j].val;
            }
            cout << "|" << endl;
        }
        cout << endl;
    }

    bool checkFreeTiles()
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

    void newFreeTile(int x, int y)
    {
        Tile newFreeTile(x, y, 0);
        this->freeTiles.push_back(newFreeTile);
    }

    Tile getFreeTile()
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

    void spawnBlock()
    {
        checkFreeTiles();
        Tile tileToAdd = getFreeTile();
        int tileValue;
        if (rand() % 10 == 0)
            tileValue = 4;
        else
            tileValue = 2;
        grid[tileToAdd.getX()][tileToAdd.getY()].val = tileValue;
    }

    void merge(int direction)
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
};

class Check : Grid
{
public:
    Check()
    {
        this->grid = grid;
    }

    bool checkVictory()
    {
        for (int ligne = 0; ligne < gridSize; ligne++)
        {
            for (int colonne = 0; colonne < gridSize; colonne++)
            {
                if (this->grid[ligne][colonne].val == 2048)
                    return true;
            }
        }

        return false;
    }

    int checkMerge()
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
                return 4;
            }
        }
        return 4;
    }
};

int main()
{
    srand(time(0));
    //Définition des composants
    int size = 4;
    int direction;
    bool loop = true;

    //Début du jeu
    Grid grid(size);
    grid.spawnBlock();
    grid.draw();
    Check check;
    Game game;

    //Boucle de jeu
    while (loop)
    {
        direction = game.moveInput();
        if (direction == 4)
            loop = false;
        grid.merge(direction);
        grid.moveBlocks(direction);
        grid.spawnBlock();
        grid.draw();
        if (check.checkVictory() == true)
        {
            cout << "Victoire" << endl << endl;
            loop = false;
        }
        if (grid.checkFreeTiles())
        {
            cout << "Possibilite de merge : " << check.checkMerge() << endl;
            if (check.checkMerge() == 0)
            {
                cout << "Perdu" << endl << endl;
                loop = false;
            }
        }
    }

    //Fin
    cout << endl << "Game Over" << endl;
    exit(0);
}