#include "GameMap.h"
#include "Game.h"
#include <fstream>
#include <sstream>


Camera GameMap::map_camera;
std::vector<SDL_Rect> GameMap::TILE_COLISION(MAX_TILE, { 0,0,0,0 });
ImageObject GameMap::tile[MAX_TILE];

void Tile::setTileColision()
{

}

GameMap::GameMap()
{
	map_camera.start_x = 0;
	map_camera.start_y = 0;
	map_camera.end_x = Window::getWindowWidth();
	map_camera.end_y = Window::getWindowHeight();

	start_x = 0;
	start_y = 0;
	max_x = 1;
	max_y = 1;
}

GameMap::~GameMap()
{
	
}

void GameMap::loadMap(std::string path)
{
	std::fstream file_map(path.c_str(), std::ios::in);

	while (!file_map.eof())
	{
		std::vector<Tile> temp;
		std::string line;
		std::getline(file_map, line);
		std::stringstream sstr(line);

		while (!sstr.eof())
		{
			Tile temp_tile;
			sstr >> temp_tile.type;
			temp_tile.type--;
			//if (temp_tile.type != 1) temp_tile.collision = 1;
			temp_tile.collision = 0;

			temp.push_back(temp_tile);
		}

		map.push_back(temp);
	}

	std::cout << std::endl;
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			std::cout << map[i][j].type << " ";
			map[i][j].rect.x = j * TILE_SIZE;
			map[i][j].rect.y = i * TILE_SIZE;
			map[i][j].rect.w = TILE_SIZE;
			map[i][j].rect.h = TILE_SIZE;

			map[i][j].render_rect = map[i][j].rect;
			
			if (map[i][j].type != -1)
			{
				map[i][j].colision_box.x = TILE_COLISION[map[i][j].type].x;
				map[i][j].colision_box.y = TILE_COLISION[map[i][j].type].y;
				map[i][j].colision_box.w = TILE_COLISION[map[i][j].type].w;
				map[i][j].colision_box.h = TILE_COLISION[map[i][j].type].h;
			}
				
		}
		std::cout << "\n";
	}

	file_map.close();

	max_x = map[0].size()-1;
	max_y = map.size()-1;
}

void GameMap::loadTile(std::string path)
{
	for (int i = 0; i < MAX_TILE; ++i)
	{
		tile[i].loadTexture(path + std::to_string(i) + ".png");
		if (i >= 235 && i <= 349)
			SDL_SetTextureAlphaMod(tile[i].getTexture(), 50);
	}
}

void GameMap::loadTileColision()
{
	TILE_COLISION[2] = { 0,0,64,64 };
	TILE_COLISION[3] = { 5,0,60,64 };
	TILE_COLISION[4] = { 0,0,64,64 };
	TILE_COLISION[5] = { 5,0,60,64 };
	TILE_COLISION[6] = { 0,0,64,64 };
	TILE_COLISION[7] = { 0,0,64,64 };
	TILE_COLISION[8] = { 0,0,64,64 };
	TILE_COLISION[9] = { 0,0,64,64 };
	TILE_COLISION[10] = { 0,0,64,64 };
	TILE_COLISION[11] = { 0,0,64,64 };
	TILE_COLISION[13] = { 0,0,64,64 };
	TILE_COLISION[14] = { 0,0,64,64 };
	TILE_COLISION[15] = { 0,0,64,64 };
	TILE_COLISION[16] = { 0,0,16,64 };
	TILE_COLISION[17] = { 0,0,16,64 };
	TILE_COLISION[92] = { 0,0,64,64 };
	TILE_COLISION[93] = { 48,0,16,64 };
	TILE_COLISION[94] = { 48,0,16,64 };
	TILE_COLISION[95] = { 0,0,64,64 };
	TILE_COLISION[96] = { 0,0,64,64 };
	TILE_COLISION[98] = { 0,0,64,64 };
	TILE_COLISION[99] = { 5,0,60,64 };
	TILE_COLISION[100] = { 0,0,64,64 };
	TILE_COLISION[101] = { 0,0,60,64 };
	TILE_COLISION[102] = { 0,0,64,16 };
	TILE_COLISION[103] = { 48,0,16,64 };
	TILE_COLISION[104] = { 0,0,16,64 };
	TILE_COLISION[105] = { 5,0,60,64 };
	TILE_COLISION[106] = { 0,0,64,64 };
	TILE_COLISION[108] = { 0,0,60,64 };
	TILE_COLISION[109] = { 48,0,16,16 };
	TILE_COLISION[110] = { 0,0,64,16 };
	TILE_COLISION[111] = { 0,0,64,64 };
	TILE_COLISION[112] = { 0,0,64,16 };
	TILE_COLISION[113] = { 0,0,64,16 };
	TILE_COLISION[114] = { 0,0,16,16 };
	TILE_COLISION[115] = { 48,0,64,16 };
	TILE_COLISION[116] = { 0,0,64,16 };
	TILE_COLISION[117] = { 0,0,64,64 };
	TILE_COLISION[119] = { 0,0,64,64 };
	TILE_COLISION[120] = { 0,0,64,64 };
	TILE_COLISION[121] = { 0,0,64,64 };
	TILE_COLISION[122] = { 0,0,64,64 };
	TILE_COLISION[123] = { 0,0,64,64 };
	TILE_COLISION[124] = { 0,0,64,64 };
	TILE_COLISION[125] = { 0,0,64,64 };
	TILE_COLISION[126] = { 0,0,64,64 };
	TILE_COLISION[127] = { 0,0,64,64 };
	TILE_COLISION[128] = { 0,0,64,64 };
	TILE_COLISION[129] = { 0,0,16,64 };
	TILE_COLISION[130] = { 0,0,16,64 };
	TILE_COLISION[131] = { 48,0,16,64 };
	TILE_COLISION[132] = { 0,0,16,64 };
	TILE_COLISION[133] = { 48,0,16,64 };
	TILE_COLISION[134] = { 0,0,16,64 };
	TILE_COLISION[135] = { 48,0,16,64 };
	TILE_COLISION[136] = { 0,0,16,64 };
	TILE_COLISION[137] = { 48,0,16,64 };
	TILE_COLISION[138] = { 0,0,16,64 };
	TILE_COLISION[139] = { 48,0,16,64 };
	TILE_COLISION[140] = { 0,0,16,64 };
	TILE_COLISION[141] = { 48,0,16,64 };
	TILE_COLISION[142] = { 48,0,16,64 };
	TILE_COLISION[143] = { 0,0,16,64 };
	TILE_COLISION[144] = { 48,0,16,64 };
	TILE_COLISION[145] = { 0,0,16,64 };
	TILE_COLISION[146] = { 48,0,16,64 };
	TILE_COLISION[147] = { 0,0,16,64 };
	TILE_COLISION[148] = { 48,0,16,64 };
	TILE_COLISION[149] = { 0,0,16,64 };
	TILE_COLISION[150] = { 48,0,16,64 };
	TILE_COLISION[151] = { 0,0,64,64 };
	TILE_COLISION[152] = { 0,0,16,64 };
	TILE_COLISION[153] = { 0,0,64,64 };
	TILE_COLISION[154] = { 0,0,64,64 };
	TILE_COLISION[155] = { 0,0,64,64 };
	TILE_COLISION[156] = { 0,0,16,64 };
	TILE_COLISION[157] = { 48,0,16,64 };
	TILE_COLISION[158] = { 0,0,16,64 };
	TILE_COLISION[159] = { 48,0,16,64 };
	TILE_COLISION[160] = { 0,0,34,64 };
	TILE_COLISION[161] = { 30,0,34,64 };
	TILE_COLISION[162] = { 0,0,34,64 };
	TILE_COLISION[163] = { 48,0,16,64 };
	TILE_COLISION[164] = { 30,0,34,64 };
	TILE_COLISION[165] = { 0,0,16,64 };
	TILE_COLISION[166] = { 48,0,16,64 };
	TILE_COLISION[167] = { 0,0,16,64 };
	TILE_COLISION[168] = { 48,0,16,64 };
	TILE_COLISION[169] = { 48,0,16,10 };
	TILE_COLISION[170] = { 0,0,16,10 };
	TILE_COLISION[171] = { 0,0,16,64 };
	TILE_COLISION[172] = { 48,0,16,64 };
	TILE_COLISION[173] = { 0,0,16,64 };
	TILE_COLISION[174] = { 48,0,16,64 };
	TILE_COLISION[175] = { 0,0,16,64 };
	TILE_COLISION[176] = { 0,0,16,64 };
	TILE_COLISION[177] = { 0,48,64,16 };
	TILE_COLISION[178] = { 0,48,64,16 };
	TILE_COLISION[179] = { 0,48,64,16 };
	TILE_COLISION[180] = { 48,0,16,64 };
	TILE_COLISION[181] = { 0,0,16,64 };
	TILE_COLISION[182] = { 48,0,16,64 };
	TILE_COLISION[183] = { 0,0,16,64 };
	TILE_COLISION[184] = { 48,0,16,64 };
	TILE_COLISION[185] = { 0,0,64,64 };
	TILE_COLISION[186] = { 0,0,64,64 };
	TILE_COLISION[187] = { 0,0,64,64 };
	TILE_COLISION[188] = { 0,0,64,64 };
	TILE_COLISION[189] = { 0,0,64,64 };
	TILE_COLISION[190] = { 0,0,64,64 };
	TILE_COLISION[191] = { 0,0,64,64 };
	TILE_COLISION[192] = { 0,0,64,64 };
	TILE_COLISION[193] = { 0,0,64,64 };
	TILE_COLISION[194] = { 0,0,64,64 };
	TILE_COLISION[195] = { 0,0,64,64 };
	TILE_COLISION[196] = { 0,0,64,64 };
	TILE_COLISION[197] = { 0,0,64,64 };
	TILE_COLISION[198] = { 0,0,64,64 };
	TILE_COLISION[199] = { 0,0,64,64 };
	TILE_COLISION[200] = { 0,0,64,64 };
	TILE_COLISION[201] = { 0,0,64,64 };
	TILE_COLISION[202] = { 0,0,64,64 };
	TILE_COLISION[203] = { 0,0,64,64 };
	TILE_COLISION[204] = { 0,0,64,64 };
	TILE_COLISION[205] = { 0,0,64,64 };
	TILE_COLISION[206] = { 0,0,64,64 };
	TILE_COLISION[207] = { 0,0,64,64 };
	TILE_COLISION[208] = { 0,0,64,64 };
	TILE_COLISION[209] = { 0,0,64,64 };
	TILE_COLISION[210] = { 0,0,64,64 };
	TILE_COLISION[211] = { 0,0,64,64 };
	TILE_COLISION[212] = { 0,0,64,64 };
	TILE_COLISION[213] = { 0,0,64,64 };
	TILE_COLISION[214] = { 0,0,64,64 };
	TILE_COLISION[215] = { 0,0,64,64 };
	TILE_COLISION[216] = { 0,0,64,64 };
	TILE_COLISION[217] = { 0,0,64,64 };
	TILE_COLISION[218] = { 0,0,64,64 };
	TILE_COLISION[219] = { 0,0,64,64 };
	TILE_COLISION[220] = { 0,0,64,64 };
	TILE_COLISION[221] = { 0,0,64,64 };
	TILE_COLISION[222] = { 0,0,64,64 };
	TILE_COLISION[223] = { 0,0,64,64 };
	TILE_COLISION[224] = { 0,0,64,64 };
	TILE_COLISION[225] = { 0,0,64,64 };
	TILE_COLISION[226] = { 0,0,64,64 };
	TILE_COLISION[227] = { 0,0,64,64 };
	TILE_COLISION[228] = { 0,0,64,64 };
	TILE_COLISION[229] = { 0,0,64,64 };
	TILE_COLISION[230] = { 0,0,64,64 };
	TILE_COLISION[231] = { 0,0,64,64 };
	TILE_COLISION[232] = { 0,0,64,64 };
	TILE_COLISION[233] = { 0,0,64,64 };
	TILE_COLISION[234] = { 0,0,64,64 };
}

void GameMap::render(int layer)
{
	for (int i = start_y; i <= max_y; ++i)
	{
		for (int j = start_x; j <= max_x; ++j)
		{
			int type = map[i][j].type;
			if (type == -1) continue;
			SDL_Rect tile_rect = map[i][j].render_rect;
			tile[type].setRenderRect(tile_rect.x - render_x, tile_rect.y - render_y, tile_rect.w, tile_rect.h);

			Game::draw_queue.addToQueue(tile[type].getTexture(), tile[type].getRenderRect(), layer);
			//tile[type].render();

		}
	}
}

Tile GameMap::getTile(int x, int y) 
{ 
	if (x < map[0].size() && y < map.size())
		return map.at(y).at(x); 
	return map[0][0];
}

bool GameMap::setCameraPosition(const int x1, const int y1, const int x2, const int y2) 
{
	bool ret = false;
	if (x1 >= 0 && y1 >= 0 && x2 <= map[0].size() * TILE_SIZE 
		&& y2 <= map.size() * TILE_SIZE)
	{
		ret = true;
		map_camera.start_x = x1;
		map_camera.start_y = y1;
		map_camera.end_x = x2;
		map_camera.end_y = y2;
	}
	else
	{
		if (x1 < 0)  map_camera.start_x = 0;
		if (y1 < 0)  map_camera.start_y = 0;
		if (x2 > map[0].size() * TILE_SIZE) map_camera.end_x = map[0].size() * TILE_SIZE;
		if (y2 > map.size() * TILE_SIZE) map_camera.end_y = map.size() * TILE_SIZE;
	}

	map_camera.width = map_camera.end_x - map_camera.start_x;
	map_camera.height = map_camera.end_y - map_camera.start_y;

	start_x = map_camera.start_x / TILE_SIZE;
	start_y = map_camera.start_y / TILE_SIZE;
	if (start_x < 0) start_x = 0;
	if (start_x >= map[0].size()) start_x = map[0].size() - 1;
	if (start_y < 0) start_y = 0;
	if (start_y >= map.size()) start_y = map.size() - 1;

	max_x = map_camera.end_x / TILE_SIZE;
	max_y = map_camera.end_y / TILE_SIZE;
	if (max_x < 0) max_x = 0;
	if (max_x >= map[0].size()) max_x = map[0].size() - 1;
	if (max_y < 0) max_y = 0;
	if (max_y >= map.size()) max_y = map.size() - 1;

	render_x = map_camera.start_x;
	render_y = map_camera.start_y;

	return ret;
}

bool GameMap::cameraMove(int x_val, int y_val)
{
	return setCameraPosition(map_camera.start_x + x_val, map_camera.start_y + y_val, map_camera.end_x + x_val, map_camera.end_y + y_val);
}
