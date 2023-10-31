#include <iostream>
#include <SDL.h>
#include <vector>

//Init class
#include "class/Window.h"
#include "class/GameObject.h"

using namespace std;

int main( int argc, char* args[] ) 
{
    bool quit = false;

    int x = 100, y = 100;
    int w = 100, h = 100;

    int size = 5;
    SDL_Rect fillRect;
    //vector<SDL_Rect> ligne;
    //ligne.resize(size);

    SDL_Event e;

    bool error;
    Window window(&error);
    window.createRenderer();

    GameObject entity;

    if (error)
    {
        cout << "Failed to initialize!" << endl;
        exit(0);
    }

    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(window.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        int offsetX = SCREEN_HEIGHT / 2;
        int offsetY = SCREEN_HEIGHT / 4;
        int space = 110;
        for (x = offsetX; x < size * space + offsetX; x += space)
        {
            for (y = 100; y < size * space; y += space)
            {
                fillRect = { x, y, w, h };
                entity.draw(window.gRenderer, fillRect);
            }
        }

        

        //Update screen
        SDL_RenderPresent(window.gRenderer);
    }

	return 0;
}
