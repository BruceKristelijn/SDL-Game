#include "pch.h"
#include "Game.h"

//List of all objects recieving update calls.
std::vector<BaseObject*> Game::objects;

//Constructor
Game::Game(char *argv[])
{
	//If initialization works start game
	if (init(argv)) {
		//Who welcome message
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Welcome!", "Welcome! You have to travel across this frozen land. Make your way to the end (green square) \n by usign the WASD keys. But be aware, the ice blocks make you slide!", NULL);
		
		//Before starting loop call start functions.
		broadCastStart();

		//Start gameloop.
		loop();

		//Call clenaup function
		close();
	}
}

//Frees media and shuts down SDL.
void Game::close()
{
	delete audioPlayer;
	delete renderer;

	SDL_Quit();
}


//Tell all objects to start.
void Game::broadCastStart() {
	for (BaseObject* object : objects) {
		object->Start();
	}
}

//Tell all objects another loop/frame has happened.
void Game::broadCastLoop() {
	for (BaseObject* object : objects) {
		object->Update();
	}
}

//Starts up SDL and creates window.
bool Game::init(char *argv[])
{
	bool success = false;

	std::cout << "[Game] Starting SDL" << std::endl;
	//Initialize all SDL systems.
	SDL_Init(SDL_INIT_VIDEO);
	SDL_InitSubSystem(SDL_INIT_AUDIO);
	SDL_InitSubSystem(SDL_INIT_EVENTS);
	SDL_InitSubSystem(SDL_INIT_TIMER);

	//Call a successfull initialization
	std::cout << "[Game] SDL Could initialize" << std::endl;

	//Setup assets system.
	Assets::instance->Init(argv);

	//Setup audio system
	AudioPlayer::instance->Init();

	//Setup mayor game components like render and input modules.
	renderer = new Renderer();
	input = new Input();

	//Add objects to mayor object pool.
	objects.push_back(renderer);
	objects.push_back(input);

	//Start GameClasses
	objects.push_back(new LevelManager());
	objects.push_back(new Player());

	//Call init function to setup these mayor components.
	success = renderer->Init();
	success = input->Init();

	//Return success variable.
	return success;
}

//Main gameplay loop.
void Game::loop() {
	const int FPS = 30;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	while (!quit) {
		frameStart = SDL_GetTicks();

		broadCastLoop();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}