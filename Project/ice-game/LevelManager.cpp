#include "pch.h"
#include "LevelManager.h" 


LevelManager* LevelManager::instance;

void LevelManager::Start()
{
	instance = this;
	printf("[Levelmanager] Start! \n");
	StartLevel(1);
}

void LevelManager::Update()
{
}

void LevelManager::OnFinishLevel()
{
	AudioPlayer::instance->PlayEffect("success.wav");
	delete currentLevel;

	if (currentLevelId > levelAmount) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Congratulations!", "Congratulations! You made it to the end!", NULL);
		quit = true;
	}
	else {
		StartLevel(currentLevelId);
	}

}
void LevelManager::StartLevel(int id) {
	currentLevel = new Level(id);
	currentLevel->GenerateTiles();

	currentLevelId++;

	if (Player::instance != nullptr) {
		Player::instance->RedrawPlayer();
	}
}