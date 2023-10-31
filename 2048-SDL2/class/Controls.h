#pragma once
#include <SDL.h>

class Controls
{
public:
	Controls();

	void moveLoop(SDL_Event event, SDL_Surface surface);
};