#pragma once

//The default header. Here I include / reference things I globally need in the objects I derrive from BaseObject.cpp
#include "SDL.h"

#include "BaseObject.h"
#include "Assets.h"

extern bool quit;
//extern Game* game;
//extern std::vector<BaseObject*> objects;

struct Vector2 {
	int x;
	int y;
};