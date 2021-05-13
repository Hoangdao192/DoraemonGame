#pragma once
#include <iostream>
#include <SDL.h>

enum Object_type
{

};

struct Frame_info
{
	int row;
	int col;
	int width;
	int height;
};

const Frame_info HEADSTONE_1 = { 1,1,52,80 };
const SDL_Rect HEADSTONE_1_COLIS = { 8, 46, 36, 34 };

void loadAcces();
