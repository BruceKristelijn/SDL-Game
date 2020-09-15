#pragma once
#include "default.h"
#include "Spritesheet.h"

class SpritesheetAnimator
{
public:
	void Animate(Spritesheet* spriteSheet);
	void PlayAnimation(Vector2 range);
private:
	int currentFrame = 0;
	int framesSkipped = 0;
	int framesToSkip = 2;

	Vector2 animationRange;
};

