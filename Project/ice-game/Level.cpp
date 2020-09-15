#include "pch.h"
#include "Level.h"

Level::Level(int id)
{
	currentLevel = id;
}

Level::~Level()
{
	//Remove tiles
	for (size_t y = 0; y < tiles.size(); y++)
	{
		for (size_t x = 0; x < tiles[y].size(); x++)
		{
			delete tiles[y][x];
		}
	}
}

void Level::GenerateTiles()
{
	for (size_t y = 0; y < 500 / 25; y++)
	{
		std::vector<Tile*> horizontalTiles;

		for (size_t x = 0; x < 500 / 25; x++)
		{
			Vector2* tilepos = new Vector2();
			tilepos->x = x * 25;
			tilepos->y = y * 25;

			TileType tileType;

			if (x == 0 || y == 0) {
				tileType = TileType::Wall;
			}
			else if (x == 19 || y == 19) {
				tileType = TileType::Wall;
			}
			else {
				tileType = TileType::Walkable;
			}
			horizontalTiles.push_back(new Tile(tileType, tilepos));
		}

		tiles.push_back(horizontalTiles);
	}

	SetupLevel();
}

//Here we build the level and change out tiles for different tiles.
void Level::SetupLevel()
{
	//Open level file
	std::ifstream file;
	std::filesystem::path fullPath = Assets::AssetsPath();
	fullPath.append("\Levels/");
	//Create a string with the name of the desired file
	std::stringstream fileName;
	fileName << "level_" << currentLevel << ".txt";

	std::cout << fileName.str();

	//Add the filename to the path.
	fullPath.replace_filename(fileName.str());
	//Open file.
	file.open(fullPath);

	//vector with all lines of the file.
	std::vector<std::string> lines;
	//Local variables to load the strings.
	std::string str; int i = 0;
	while (std::getline(file, str))
	{
		lines.push_back(str);
	}
	//Loop through all tiles except the outline.
	for (size_t y = 1; y < tiles.size() - 1; y++)
	{
		std::string horizontalLine = lines[y];
		for (size_t x = 1; x < tiles[y].size() - 1; x++)
		{
			if(lines[y].at(x) == 'x'){
				tiles[y][x]->type = TileType::Walkable;
			}
			if (lines[y].at(x) == 'w') {
				tiles[y][x]->type = TileType::Wall;
			}
			if (lines[y].at(x) == 's') {
				tiles[y][x]->type = TileType::Slide;
			}
			if (lines[y].at(x) == '%') {
				tiles[y][x]->type = TileType::End;
			}
		}
	}

	StartLevel();
}
void Level::StartLevel()
{
	for (size_t y = 0; y < tiles.size(); y++)
	{
		for (size_t x = 0; x < tiles[y].size(); x++)
		{
			tiles[y][x]->Init();
		}
	}
} 