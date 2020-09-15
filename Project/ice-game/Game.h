#pragma once
#include "levelmanager.h"
#include "BaseObject.h"
#include "renderer.h"
#include "input.h"
#include "assets.h"
#include "Sprite.h"
#include "AudioPlayer.h"
#include "player.h"

class Game
{
public:
	//(De-)constructor
	Game(char *argv[]);
	//~Game(); TODO

	//Global modules. These are important.
	AudioPlayer* audioPlayer;
	Renderer* renderer;
	Input* input;
	Assets* assets;

	static std::vector<BaseObject*> objects;
private:
	bool init(char *argv[]);

	void loop();
	void broadCastStart();
	void broadCastLoop();
	void close();
};