#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "default.h"
#include "tile.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

class Level
{
public:
	Level(int id);
	~Level();

	void GenerateTiles();
	void SetupLevel();
	void StartLevel();

	std::vector< std::vector <Tile*> > tiles;

private:
	int currentLevel;
};

#endif