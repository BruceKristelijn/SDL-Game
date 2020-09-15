#pragma once

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "default.h"
#include "collider.h"

class Rigidbody
{
public:
	Rigidbody(Vector2* position, Vector2 size);

	void Update();
	bool CanMove(Vector2 desiredPosition);
	bool HitsTrigger(Vector2 desiredPosition);
	bool HasHitFinish(Vector2 desiredPosition);

	Collider* collider;
	Vector2* hostPosition;
	Vector2 lastPosition;
};

#endif