#pragma once
#include "default.h"

class Input : public BaseObject
{
public:
	static Input* singleton;

	static bool up, down, left, right;

	bool Init();
	void Start();
	void Update();
private:
	SDL_Event events;
};