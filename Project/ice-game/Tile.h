#pragma once
#include "Sprite.h"
#include "default.h"
#include "collider.h"

enum TileType {
	Walkable, Wall, Slide, End
};

//The tiles class used by the levelmanager to create levels
class Tile
{
public:
	Sprite* sprite;
	Collider* collider;
	Vector2* position;
	TileType type;

	Tile(TileType _type, Vector2* _position);
	~Tile();

	void Init();
	std::string GetTexture(TileType type);
};