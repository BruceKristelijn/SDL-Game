#include "pch.h"
#include "Rigidbody.h"


Rigidbody::Rigidbody(Vector2* position, Vector2 size)
{
	std::cout << position->x << std::endl;
	std::cout << position->y << std::endl;

	collider = new Collider(position, &size, CollisionType::Collision);

	hostPosition = position;
	lastPosition = { 100, 100 };
}

void Rigidbody::Update()
{
	if (collider != nullptr) {
		if (collider->CheckCollisions()) {
			hostPosition->x = lastPosition.x;
			hostPosition->y = lastPosition.y;
		}
		else {
			lastPosition = { hostPosition->x, hostPosition->y };
		}
	}
}

bool Rigidbody::CanMove(Vector2 desiredPosition)
{
	//save original position.
	Vector2 oldPosition = { collider->position->x, collider->position->y };

	//Set position olf collider to desired position.
	collider->position->x = desiredPosition.x;
	collider->position->y = desiredPosition.y;

	//Check if this intersects with other colliders and save to variable.
	bool hasCollision = !collider->CheckCollisions();

	//Move the collider back to its original state.
	collider->position->x = oldPosition.x;
	collider->position->y = oldPosition.y;

	//Return variable stored earlier.
	return hasCollision;
}

bool Rigidbody::HitsTrigger(Vector2 desiredPosition)
{
	//save original position.
	Vector2 oldPosition = { collider->position->x, collider->position->y };

	//Set position olf collider to desired position.
	collider->position->x = desiredPosition.x;
	collider->position->y = desiredPosition.y;

	//Check if this intersects with other colliders and save to variable.
	bool hasCollision = collider->CheckTriggers();

	//Move the collider back to its original state.
	collider->position->x = oldPosition.x;
	collider->position->y = oldPosition.y;

	//Return variable stored earlier.
	return hasCollision;
}

bool Rigidbody::HasHitFinish(Vector2 desiredPosition)
{
	//save original position.
	Vector2 oldPosition = { collider->position->x, collider->position->y };

	//Set position olf collider to desired position.
	collider->position->x = desiredPosition.x;
	collider->position->y = desiredPosition.y;

	//Check if this intersects with other colliders and save to variable.
	bool hasCollision = collider->CheckFinish();

	//Move the collider back to its original state.
	collider->position->x = oldPosition.x;
	collider->position->y = oldPosition.y;

	//Return variable stored earlier.
	return hasCollision;
}
