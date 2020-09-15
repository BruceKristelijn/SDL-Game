#include "pch.h"
#include "SpritesheetAnimator.h"

void SpritesheetAnimator::Animate(Spritesheet * spriteSheet)
{
	if (framesSkipped >= framesToSkip) {
		framesSkipped = 0;
		currentFrame++;
		int id = animationRange.x + currentFrame;
		if (id > animationRange.y) {
			id = animationRange.x;
		}

		spriteSheet->SetTexture(id);
	}
	else {
		framesSkipped++;
	}
}

void SpritesheetAnimator::PlayAnimation(Vector2 range)
{
	currentFrame = 0;
	animationRange = range;
}
