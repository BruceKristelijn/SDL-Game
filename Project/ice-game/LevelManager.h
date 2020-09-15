#pragma once

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "level.h"
#include "AudioPlayer.h"
#include "Player.h";

class LevelManager  : public BaseObject
{
public:
	static LevelManager* instance;
	static bool levelCompleted;

	void Start();
	void Update();
	void OnFinishLevel();
	void StartLevel(int id);
private:
	//Pointer to current level.
	Level* currentLevel;

	int levelAmount = 2; //<- Start counting at 1.
	int currentLevelId = 1;
};

#endif