#include <iostream>
#include <SDL.h>

//Init class
#include "class/Window.h"
#include "class/GameObject.h"
#include "class/Controls.h"


using namespace std;

int main( int argc, char* args[] ) 
{
    bool quit = false;

    SDL_Event e;

    Window window;
    GameObject entity;

    if (!window.init())
    {
        cout << "Failed to initialize!" << endl;
    }
    else
    {
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

            entity.draw(window.gRenderer);

            //Update screen
            SDL_RenderPresent(window.gRenderer);
        }
    }

    window.close();

	return 0;
}
