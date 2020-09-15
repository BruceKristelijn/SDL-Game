#include "pch.h" 
#include "Spritesheet.h"

Spritesheet::Spritesheet(std::string fileName, Vector2* _position, Vector2 _size, Vector2 spriteSize, Vector2 sheetDimensions)
{
	//Combine paths and load BMP
	std::filesystem::path fullPath = Assets::AssetsPath();

	//Add images folder to path
	fullPath.append("\Images/");
	//fullPath.append("Images");
	fullPath.replace_filename(fileName);

	//Load image from files
	std::cout << "[Spritesheet] Loading texture: " << fullPath.string() << std::endl;

	SDL_Surface* spriteSurface = SDL_LoadBMP(fullPath.string().c_str());

	//Check if the sprite could be renderer
	if (spriteSurface == NULL) {
		std::cout << "Spritesheet could not bo loaded at: " << fullPath.string().c_str() << std::endl;
		return;
	}

	//Load surface into texture
	texture = SDL_CreateTextureFromSurface(Renderer::singleton->mainRenderer, spriteSurface);

	//Create rect for every possible texture
	for (size_t i = 0; i < sheetDimensions.y; i++)
	{
		for (size_t y = 0; y < sheetDimensions.x; y++)
		{
			SDL_Rect rect = { i * spriteSize.x, y * spriteSize.y, spriteSize.x, spriteSize.y };
			texturePositions.push_back(rect);
		}
	}
	SetTexture(0);

	//Get rid of old loaded surface
	SDL_FreeSurface(spriteSurface);

	position = _position;
	rect = new SDL_Rect();
	rect->w = _size.x;
	rect->h = _size.y;

	Renderer::singleton->renderables.push_back(this);
}

void Spritesheet::SetTexture(int id){
	currentTexturePosition = &texturePositions[id];
}

void Spritesheet::Render() {
	std::cout << "REDNERRRRR" << currentTexturePosition->x << std::endl;
	rect->x = position->x;
	rect->y = position->y;

	SDL_RenderCopy(Renderer::singleton->mainRenderer, texture, currentTexturePosition, rect);
}