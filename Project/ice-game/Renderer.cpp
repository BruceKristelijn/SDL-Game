#include "pch.h"
#include "renderer.h"
#include "sprite.h"

Renderer* Renderer::singleton = new Renderer();

bool Renderer::Init()
{
	printf("[Renderer] Initailizing renderer \n");
	Renderer::singleton = this;
	renderables.empty();

	//Create window
	mainWindow = SDL_CreateWindow("ICE Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (mainWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	
	//Get window surface
	mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
	
	printf("[Renderer] Finished Initailizing renderer \n");
	return true;
}

Renderer::~Renderer() {
	SDL_DestroyWindow(mainWindow);
}

//Function called on start
void Renderer::Start()
{
}

void Renderer::Update()
{
	//Clear screen
	SDL_RenderClear(mainRenderer);

	//Render texture to screen
	for (Renderable* renderable : renderables) {
		renderable->Render();
	}

	//Update screen
	SDL_RenderPresent(mainRenderer);
}