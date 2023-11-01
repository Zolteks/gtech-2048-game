#include <iostream>
#include <SDL.h>
#include <vector>

//Init class
#include "class/Window.h"
#include "class/GameObject.h"
#include "class/Tile.h"

using namespace std;

int main( int argc, char* args[] )
{
    bool quit = false;

    #define SCREEN_WIDTH 1280
    #define SCREEN_HEIGHT 720

    SDL_Event event;

    bool error;
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, &error);
    window.createRenderer();
    GameObject entity;


    /*   Tests   */

    int x = 0, y = 0, w = 50, h = 50;
    int offsetX = 10;


    /* Tiles init */
    vector<Tile> tiles;
    Tile tile(x, y, w, h, 0);
    tiles.push_back(tile);
    for (int val = 2; val <= 2048; val = val * 2)
    {
        Tile tile(x, y, w, h, val);
        tiles.push_back(tile);
    }


    
    int size = 5;

    SDL_Rect fillRect;

    if (error)
    {
        cout << "Failed to initialize!" << endl;
        exit(0);
    }

    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&event) != 0)
        {
            //User requests quit
            if (event.type == SDL_QUIT)
            {
                return 0;
            }
            //User presses a key
            if (event.type == SDL_KEYDOWN)
            {
                //Select surfaces based on key press
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    cout << "pressed up" << endl;
                    break;

                case SDLK_DOWN:
                    cout << "pressed down" << endl;
                    break;

                case SDLK_LEFT:
                    cout << "pressed left" << endl;
                    break;

                case SDLK_RIGHT:
                    cout << "pressed right" << endl;
                    break;

                default:
                    cout << "pressed idk which key" << endl;
                    break;
                }
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(window.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        /*int offsetX = SCREEN_HEIGHT / 2;
        int offsetY = SCREEN_HEIGHT / 4;
        int space = 110;
        for (x = offsetX; x < size * space + offsetX; x += space)
        {
            for (y = 100; y < size * space; y += space)
            {
                fillRect = { x, y, w, h };
                entity.draw(window.gRenderer);
            }
        }*/

        window.update();
    }

	return 0;
}
