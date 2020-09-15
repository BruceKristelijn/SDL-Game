// SourceCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SDL.h>
#include <vector>

#include "game.h"

//Main loop flag.
bool quit = false;
//Pointer to the game instance
Game* game;

int main(int argc, char *argv[])
{
	//Create instance to the game
	game = new Game(argv);

	return 0;
}




