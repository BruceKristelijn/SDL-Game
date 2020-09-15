#pragma once
#include "default.h"
#include "Renderable.h"
#include <filesystem>

class Sprite : Renderable
{
public:
	Vector2* position;
	Vector2 size;
	SDL_Texture* texture;
	SDL_Rect* rect;

	Sprite(std::string texturePath, Vector2* position, Vector2 size = { 25, 25 }, bool inherited = false);
	~Sprite();

	void Render();
};

