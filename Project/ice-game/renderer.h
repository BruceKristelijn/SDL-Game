#pragma once
#include "default.h"
#include "input.h"
#include <list> 
#include <iterator>
#include <vector>
#include <memory>
#include <stdio.h>
#include "Renderable.h"

class Renderer : public BaseObject
{
public:
	static Renderer* singleton;
	~Renderer();

	//The window we'll be rendering to
	SDL_Window* mainWindow;

	//The surface contained by the window
	SDL_Surface* screenSurface;
	SDL_Renderer* mainRenderer;

	//List of sprites to render to the screen.
	std::vector<Renderable*> renderables;

	//Called on initialization of program. Used for higher level functions (Like the rendering and input modules).
	bool Init();

	//Called on initialization of the object. If the object is permanant this will be the first gameloop.
	void Start();

	//Called every gameloop.
	void Update();
private:
	const int SCREEN_HEIGHT = 500;
	const int SCREEN_WIDTH = 500;
};

