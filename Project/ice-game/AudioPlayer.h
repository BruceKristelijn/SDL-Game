#pragma once
#include "default.h"
#include "SDL_mixer.h"

class AudioPlayer
{
public:
	//Cantructors
	void Init();
	~AudioPlayer();

	//Variables
	std::filesystem::path audioPath;

	//Functions
	void StartMusic(std::string clipName, bool loop);
	void PlayEffect(std::string clipName);

	static AudioPlayer* instance;

private: 
	Mix_Chunk* effect;
};

