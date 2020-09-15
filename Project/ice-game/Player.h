#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "default.h"
#include "sprite.h"
#include "spritesheet.h"
#include "SpritesheetAnimator.h"
#include "input.h"
#include "rigidbody.h"
#include "audioplayer.h"
#include "LevelManager.h"

enum class Direction {
	UP, DOWN, LEFT, RIGHT, STATIC
};

class Player : public BaseObject
{
public:
	static Player* instance;
	//Called on initialization of the object. If the object is permanant this will be the first gameloop.
	void Start();

	//Called every gameloop.
	void Update();
	void RedrawPlayer();
private:
	//Sprite* sprite;
	SpritesheetAnimator* spriteSheetAnimator;
	Spritesheet* spriteSheet;
	Rigidbody* rigidbody;
	Vector2* position;

	Direction currentDirection = Direction::STATIC;
	int speed = 5;
	bool isSliding = false;

	void CheckInput();
	void Move();
	void ApplyMovement(Vector2 desiredPosition);
};

#endif