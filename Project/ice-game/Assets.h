#pragma once
#include "pch.h"
#include <direct.h>
#include <stdio.h>
#include <iostream>
#include <filesystem>
#include "string"

class Assets
{
public:
	static Assets* instance;
	static std::filesystem::path AssetsPath();

	void Init(char *argv[]);

	std::filesystem::path* workingDirectory;
};