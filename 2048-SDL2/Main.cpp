#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_render.h>
#include <vector>

//Init class
#include "class/Window.h"
#include "class/GameObject.h"
#include "class/Tile.h"
#include "class/Grid.h"

using namespace std;

int main(int argc, char* args[])
{
    srand(time(0));
    #define SCREEN_WIDTH 1280
    #define SCREEN_HEIGHT 720

    SDL_Event event;

    bool error;
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, &error);
    window.createRenderer();
    
    if (error)
    {
        cout << "Failed to initialize!" << endl;
        exit(0);
    }

    if (TTF_Init() == -1) {
        cout << "Failed to initialize TTF!" << endl;
        exit(0);
    }

    //Tile tile(window.gRenderer, 100, 100, 50, 50, { 237, 224, 200, 255 }, 2);
    Grid grid(window.gRenderer, 4, 4, 50, 20);
    grid.spawnBlock(0);

    bool running = true;

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
        //SDL_RenderClear(window.gRenderer);
        SDL_SetRenderDrawColor(window.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

        /* Tiles init */
        grid.draw();
        
        /*for (x = 0; x < size * space; x += space)
        {
            for (y = 0; y < size * space; y += space)
            {
                fillRect = { x, y, w, h };
                oGameObject.draw(window.gRenderer, fillRect);
            }
        }*/
        window.update();
    }

    return 0;
}