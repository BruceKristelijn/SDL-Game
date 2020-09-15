#pragma once
#include "default.h"
#include "renderer.h"
#include "Renderable.h"
#include <filesystem>

class Spritesheet : Renderable
{
public:
	Spritesheet(std::string fileName, Vector2* _position, Vector2 size, Vector2 spriteSize, Vector2 sheetDimensions);
	
	void SetTexture(int id);
	void Render();
private:
	Vector2* position;

	SDL_Texture* texture;
	SDL_Rect* rect;
	SDL_Rect* currentTexturePosition;
	std::vector<SDL_Rect> texturePositions;
};

