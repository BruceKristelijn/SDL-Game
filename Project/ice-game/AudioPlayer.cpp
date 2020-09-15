#include "pch.h"
#include "AudioPlayer.h"

AudioPlayer* AudioPlayer::instance = new AudioPlayer();

void AudioPlayer::Init()
{
	//Initalize mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "[Audiomanager] Could not initialize error:  " << Mix_GetError() << std::endl;
		return;
	}
	else {
		std::cout << "[Audioplayer] Initialized!" << std::endl;
	}

	//Setup path all audio is located
	audioPath = Assets::AssetsPath();
	audioPath.append("\Audio/");

	//Start music
	StartMusic("music.wav", true);
}

//Destory function
AudioPlayer::~AudioPlayer()
{
	Mix_CloseAudio();
}

void AudioPlayer::StartMusic(std::string clipName, bool loop)
{
	audioPath.replace_filename(clipName);

	Mix_Music *clip = Mix_LoadMUS(audioPath.string().c_str());

	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(clip, -1);
	}
}

void AudioPlayer::PlayEffect(std::string clipName)
{
	if (!Mix_Playing(1)) {
		//Free old audio from memory
		Mix_FreeChunk(effect);

		audioPath.replace_filename(clipName);

		effect = Mix_LoadWAV(audioPath.string().c_str());
		Mix_PlayChannel(1, effect, 0);
	}
}
