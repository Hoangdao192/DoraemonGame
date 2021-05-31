#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

#include "Window.h"
#include "MainAcces.h"

enum Object_type
{
	BENCHE_FRONT = 1,
	BENCHE_LEFT = 2,
	BENCHE_RIGHT = 3,

	RIP_1 = 4,
	RIP_2 = 5,
	RIP_3 = 6,

	ROCK_COLUMN_1 = 7,
	ROCK_COLUMN_2 = 8,
	ROCK_COLUMN_3 = 9,
	ROCK_COLUMN_4 = 10,
	ROCK_COLUMN_5 = 11,

	TOMB_VERTICAL = 12,
	TOMB_HOZIROL = 13,

	ROCK_LAMP = 14,

	SIGN_LEFT = 15,
	SIGN_RIGHT = 16,

	BREAK_WELL = 17,

	JAR_1 = 18,
	JAR_2 = 19,
	JAR_3 = 20,

	CHEST_1 = 21
};

void writeLog(std::string log);