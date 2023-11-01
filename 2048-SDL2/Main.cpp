#include <iostream>
#include <SDL.h>

//Init class
#include "class/Window.h"
#include "class/GameObject.h"


using namespace std;

int main( int argc, char* args[] )
{
    bool quit = false;

    //SDL_Surface* surface = NULL;
    SDL_Event event;

    Window window;
    GameObject entity;

    if (!window.init())
    {
        cout << "Failed to initialize!" << endl;
    }
    else
    {
        cout << "Initialization successful!" << endl;
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
        }

            //Clear screen
            SDL_SetRenderDrawColor(window.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

            entity.draw(window.gRenderer);

            //Update screen
            SDL_RenderPresent(window.gRenderer);
        }

    window.close();

	return 0;
}
