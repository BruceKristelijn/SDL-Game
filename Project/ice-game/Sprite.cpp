#include "pch.h"
#include "renderer.h"
#include "Sprite.h"

Sprite::Sprite(std::string texturePath, Vector2* _position, Vector2 _size, bool inherited)
{
	if (inherited) {
		return;
	}
	//Combine paths and load BMP
	std::filesystem::path fullPath = Assets::AssetsPath();

	//Add images folder to path
	fullPath.append( "\Images/" );
	//fullPath.append("Images");
	fullPath.replace_filename(texturePath);

	//Load image from files
	std::cout << "[Sprite] Loading texture: " << fullPath.string() << std::endl;

	SDL_Surface* spriteSurface = SDL_LoadBMP(fullPath.string().c_str());

	//Check if the sprite could be renderer
	if (spriteSurface == NULL) {
		std::cout << "Sprite could not bo loaded at: " << fullPath.string().c_str() << std::endl;
		return;
	}

	//Load surface into texture
	texture = SDL_CreateTextureFromSurface(Renderer::singleton->mainRenderer, spriteSurface);
	position = _position;

	//Get rid of old loaded surface
	SDL_FreeSurface(spriteSurface);

	rect = new SDL_Rect();
	rect->w = _size.x;
	rect->h = _size.y;

	Renderer::singleton->renderables.push_back(this);
}
Sprite::~Sprite()
{
	for (size_t i = 0; i < Renderer::singleton->renderables.size(); i++)
	{
		if (Renderer::singleton->renderables[i] == this) {
			Renderer::singleton->renderables.erase(Renderer::singleton->renderables.begin() + i);
			break;
		}
	}

	SDL_DestroyTexture(texture);
}
void Sprite::Render() {
	rect->x = position->x;
	rect->y = position->y;

	SDL_RenderCopy(Renderer::singleton->mainRenderer, texture, NULL, rect);
}