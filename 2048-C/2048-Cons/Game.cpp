#include <windows.h>
#include <iostream>

#include "class/Game.h"

using namespace std;

int Game::moveInput() {
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