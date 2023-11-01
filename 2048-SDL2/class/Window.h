#pragma once

class Window
{
public:
	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;

	Window(int width, int height, bool* error);
  
	~Window();

	bool createRenderer();

	void update();

	bool createRenderer();
};