#pragma once

#ifndef COLLIDER_H
#define COLLIDER_H

#include "default.h"

enum CollisionType {
	Collision, Trigger, Finish
};

class Collider
{
public:
	static std::vector<Collider*> colliders;

	SDL_Rect* collisionRect;

	Collider(Vector2* currentPos, Vector2* size, CollisionType _type);
	~Collider();

	bool CheckCollision(SDL_Rect a, SDL_Rect b);
	bool CheckCollisions();
	bool CheckTriggers();
	bool CheckFinish();

	CollisionType type= CollisionType::Collision;
	Vector2* position;
};

#endif