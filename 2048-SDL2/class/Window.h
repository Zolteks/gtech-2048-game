#pragma once

class Window
{
public:
	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;

	#define SCREEN_WIDTH 1280
	#define SCREEN_HEIGHT 720

	Window(int width, int height, bool* error);

	~Window();

	void update();

	bool createRenderer();
};