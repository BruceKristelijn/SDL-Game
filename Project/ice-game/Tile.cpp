#include "pch.h"
#include "Tile.h"

Tile::Tile(TileType _type, Vector2* _position)
{
	position = _position;
	type = _type;
}

Tile::~Tile()
{
	delete sprite;
	delete collider;
}

std::string Tile::GetTexture(TileType type)
{
	switch (type)
	{
	case Walkable:
		return "ground.bmp";
	case Wall:
		return "dirtWall.bmp";
	case Slide:
		return "iceWall.bmp";
	default:
		return "tree.bmp";
		break;
	}
}

void Tile::Init() {
	sprite = new Sprite(GetTexture(type), position);

	if (type == TileType::Wall) { 
		collider = new Collider(position, new Vector2{25,25}, CollisionType::Collision);
	}
	if (type == TileType::Slide) {
		collider = new Collider(position, new Vector2{ 25,25 }, CollisionType::Trigger);
	}
	if (type == TileType::End) {
		collider = new Collider(position, new Vector2{ 25,25 }, CollisionType::Finish);
	}
}