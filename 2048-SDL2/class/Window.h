#pragma once

class Window
{
public:
	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Renderer* gRenderer = NULL;

	#define SCREEN_WIDTH 1280
	#define SCREEN_HEIGHT 720

	Window();
	
	bool init();

	void update();

	void close();

};