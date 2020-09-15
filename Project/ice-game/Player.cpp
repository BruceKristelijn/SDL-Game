#include "pch.h"
#include "Player.h"

Player* Player::instance;

void Player::Start()
{
	//Setup instance.
	instance = this;

	//Setup position
	position = new Vector2();
	position->y = 25;
	position->x = 25;

	currentDirection = Direction::STATIC;

	//Set sprite (We use the rect of the sprite for collision. We always change this so no need to do it again.
	spriteSheet = new Spritesheet("player_sheet.bmp", position, { 24, 24 }, { 64, 64 }, { 9, 4 });
	spriteSheetAnimator = new SpritesheetAnimator();
	rigidbody = new Rigidbody(position, {24, 24});
}

void Player::Update()
{
	if (currentDirection == Direction::STATIC) {
		//Check input
		CheckInput();
	}
	else {
		//Move player
		Move();
	}

	spriteSheetAnimator->Animate(spriteSheet);

	if (rigidbody->HasHitFinish(*position))
	{
		LevelManager::instance->OnFinishLevel();
	}
}

void Player::CheckInput() {
	if (Input::right) {
		currentDirection = Direction::RIGHT;
		spriteSheetAnimator->PlayAnimation({ 27, 27 + 3 });
	}
	else if (Input::left) {
		currentDirection = Direction::LEFT;
		spriteSheetAnimator->PlayAnimation({ 0, 0 + 3 });

	}
	else if (Input::up) {
		currentDirection = Direction::UP;
		spriteSheetAnimator->PlayAnimation({ 9, 9 + 3 });

	}
	else if (Input::down) {
		currentDirection = Direction::DOWN;
		spriteSheetAnimator->PlayAnimation({ 18, 18 + 3 });
	}
}
void Player::Move() {
	rigidbody->lastPosition = *position;

	//TODO: Move these 2 if statements into 1 dynamic function. 

	//Check if the moving direction is UP or DOWN
	if (currentDirection == Direction::UP || currentDirection == Direction::DOWN) {
		//If so calculate the velocity/amount the player should move.
		int velocity = (currentDirection == Direction::UP ? -1 : 1) * speed;

		//Check the rigidbody for the ability to move to this position.
		Vector2 desiredposition = { position->x , position->y + velocity };
		ApplyMovement(desiredposition);

		//Check if position is for and idle/static state.
		if (position->y % 25 == 0 && !isSliding) {
			//Set the direction to static.
			currentDirection = Direction::STATIC;
		}
	}

	//Do the same.
	else if(currentDirection == Direction::LEFT || currentDirection == Direction::RIGHT){
		int velocity = (currentDirection == Direction::LEFT ? -1 : 1) * speed;

		//Check the rigidbody for the ability to move to this position.
		Vector2 desiredposition = { position->x + velocity, position->y };
		ApplyMovement(desiredposition);

		if (position->x % 25 == 0 && !isSliding) {
			currentDirection = Direction::STATIC;
		}
	}
}
void Player::ApplyMovement(Vector2 desiredposition) {
	if (rigidbody->CanMove(desiredposition)) {
		//Check sliding
		if (rigidbody->HitsTrigger(desiredposition)) {
			isSliding = true;
		}
		else {
			isSliding = false;
		}

		//If so move player
		position->x = desiredposition.x;
		position->y = desiredposition.y;
		if (!isSliding) {
			AudioPlayer::instance->PlayEffect("walk.wav");
		}
		else {
			AudioPlayer::instance->PlayEffect("slide.wav");
		}
	}
	else {
		AudioPlayer::instance->PlayEffect("bump.wav");
		isSliding = false;
	}
}
void Player::RedrawPlayer() {
	//Set sprite (We use the rect of the sprite for collision. We always change this so no need to do it again.
	spriteSheet = new Spritesheet("player_sheet.bmp", position, { 24, 24 }, { 64, 64 }, { 9, 4 });
	spriteSheetAnimator = new SpritesheetAnimator();
}