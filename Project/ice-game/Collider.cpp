#include "pch.h"
#include "Collider.h"

std::vector<Collider*> Collider::colliders;

Collider::Collider(Vector2* _position, Vector2* size, CollisionType _type)
{
	collisionRect = new SDL_Rect();
	collisionRect->x = _position->x;
	collisionRect->y = _position->y;
	collisionRect->w = size->x;
	collisionRect->h = size->y;

	type = _type;
	position = _position;

	colliders.push_back(this);
}

Collider::~Collider()
{
	for (size_t i = 0; i < Collider::colliders.size(); i++)
	{
		if (Collider::colliders[i] == this) {
			Collider::colliders.erase(Collider::colliders.begin() + i);
			break;
		}
	}
}

bool Collider::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

//Returns true if a collision is made.
bool Collider::CheckCollisions() {
	collisionRect->x = position->x;
	collisionRect->y = position->y;

	for (size_t i = 0; i < Collider::colliders.size(); i++)
	{
		if (Collider::colliders[i] != this && Collider::colliders[i]->type == CollisionType::Collision) {
			Collider* otherCollider = Collider::colliders[i];

			if (CheckCollision(*otherCollider->collisionRect, *collisionRect)) {
				return true;
			}
		}
	}
	return false;
}

//Returns true if a collision with a trigger is made.
bool Collider::CheckTriggers() {
	collisionRect->x = position->x;
	collisionRect->y = position->y;

	for (size_t i = 0; i < Collider::colliders.size(); i++)
	{
		//(Collider::colliders[i]->type == CollisionType::Trigger || Collider::colliders[i]->type == CollisionType::Finish)
		if (Collider::colliders[i] != this) {
			Collider* otherCollider = Collider::colliders[i];

			if (CheckCollision(*otherCollider->collisionRect, *collisionRect)) {
				if (otherCollider->type == CollisionType::Trigger) {
					return true;
				}
			}
		}
	}
	return false;
}

//Returns true if a collision with a trigger is made.
bool Collider::CheckFinish() {
	collisionRect->x = position->x;
	collisionRect->y = position->y;

	for (size_t i = 0; i < Collider::colliders.size(); i++)
	{
		//(Collider::colliders[i]->type == CollisionType::Trigger || Collider::colliders[i]->type == CollisionType::Finish)
		if (Collider::colliders[i] != this) {
			Collider* otherCollider = Collider::colliders[i];

			if (CheckCollision(*otherCollider->collisionRect, *collisionRect)) {
				if (otherCollider->type == CollisionType::Finish) {
					return true;
				}
			}
		}
	}
	return false;
}