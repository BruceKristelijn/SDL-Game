#include "pch.h"
#include "Assets.h"

Assets* Assets::instance = new Assets();

//Init function for setting up the variables
void Assets::Init(char * argv[])
{
	//Setup the correct directory
	workingDirectory = new std::filesystem::path(argv[0]);
	workingDirectory->remove_filename();
	workingDirectory->append("Assets");
}
//Function to return path all assets are located inside.
std::filesystem::path Assets::AssetsPath() {
	return *Assets::instance->workingDirectory;
}