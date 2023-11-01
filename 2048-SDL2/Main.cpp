#include <iostream>
#include <SDL.h>
#include <vector>

//Init class
#include "class/Window.h"
#include "class/GameObject.h"
#include "class/Tile.h"
#include "class/Grid.h"

using namespace std;

int main(int argc, char* args[])
{
    #define SCREEN_WIDTH 1280
    #define SCREEN_HEIGHT 720

    Grid grid(4);
    grid.spawnBlock(0);
    grid.draw();

    bool running = true;

    SDL_Event event;

    bool error;
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, &error);
    window.createRenderer();

    if (error)
    {
        cout << "Failed to initialize!" << endl;
        exit(0);
    }

    while (running)
    {
        int direction= -1;
        //Handle events on queue
        while (SDL_PollEvent(&event) != 0)
        {
            //User requests quit
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            //User presses a key
            if (event.type == SDL_KEYDOWN)
            {
                //Select surfaces based on key press
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    cout << "pressed up" << endl;
                    direction = 0;
                    break;

                case SDLK_DOWN:
                    cout << "pressed down" << endl;
                    direction = 1;
                    break;

                case SDLK_LEFT:
                    cout << "pressed left" << endl;
                    direction = 2;
                    break;

                case SDLK_RIGHT:
                    cout << "pressed right" << endl;
                    direction = 3;
                    break;

                default:
                    cout << "pressed idk which fcking key" << endl;
                    break;
                }
            }
        }
        if (direction != -1)
        {
            grid.merge(direction);
            grid.moveBlocks(direction);
            if (!grid.checkFreeTiles())
                grid.spawnBlock(0);
            grid.draw();
            if (grid.checkVictory())
            {
                cout << "Victoire" << endl << endl;
                running = false;
            }
            if (grid.checkFreeTiles())
            {
                cout << "Possibilite de merge : " << grid.checkMerge() << endl;
                if (grid.checkMerge() == 0)
                {
                    cout << "Perdu" << endl << endl;
                    running = false;
                }
            }
        }

        window.update();
    }

    return 0;
}