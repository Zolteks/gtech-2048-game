#pragma once

#include<map>

class Window
{
public:
	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;
	SDL_Surface* pSurface = NULL;
	SDL_Texture* pTexture = NULL;

	std::map<int, SDL_Texture*> textures;

	Window(int width, int height, bool* error);
  
	~Window();

	bool createRenderer();

	void update();
};