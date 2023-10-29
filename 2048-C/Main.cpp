#include <iostream>

#include "Tile.h"
#include "Grid.h"
#include "Game.h"

using namespace std;
//setfill() permet de remplir des cases vides

int main()
{
    srand(time(0));
    //Définition des composants
    int size = 4;
    int direction;
    bool loop = true;

    //Début du jeu
    Grid grid(size);
    grid.spawnBlock(0);
    grid.draw();
    Game game;

    //Boucle de jeu
    while (loop)
    {
        direction = game.moveInput();
        if (direction == 4)
            loop = false;
        grid.merge(direction);
        grid.moveBlocks(direction);
        if (!grid.checkFreeTiles())
            grid.spawnBlock(0);
        grid.draw();
        if (grid.checkVictory())
        {
            cout << "Victoire" << endl << endl;
            loop = false;
        }
        if (grid.checkFreeTiles())
        {
            cout << "Possibilite de merge : " << grid.checkMerge() << endl;
            if (grid.checkMerge() == 0)
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