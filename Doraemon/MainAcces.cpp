#include "MainAcces.h"

const int MAIN_TILE_SIZE = 64;

void loadAcces()
{
	COIN_IMG.loadTexture("acces/9.png");
	COIN_FRAME.setFrameSheet(1, 24);
	COIN_FRAME.setFrameSize(MAIN_TILE_SIZE, MAIN_TILE_SIZE);
}