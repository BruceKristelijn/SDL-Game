#include "pch.h"
#include "Input.h"

bool Input::up = false;
bool Input::down = false;
bool Input::left = false;
bool Input::right = false;

Input* Input::singleton = new Input();

bool Input::Init()
{
	printf("[Input] Initailizing input module \n");
	Input::singleton = this;

	return true;
}

void Input::Start()
{

}

void Input::Update()
{
	printf("[Input] Updating input module \n");

	while (SDL_PollEvent(&events) != 0) {
		if (events.type == SDL_QUIT) {
			quit = true;
		}
	}


	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	up = currentKeyStates[SDL_SCANCODE_W];
	down = currentKeyStates[SDL_SCANCODE_S];
	left = currentKeyStates[SDL_SCANCODE_A];
	right = currentKeyStates[SDL_SCANCODE_D];
}