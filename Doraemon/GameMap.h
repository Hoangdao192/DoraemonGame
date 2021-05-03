#pragma once
#include "MainFunction.h"
#include "ImageObject.h"
#include "DrawQueue.h"

const int MAX_TILE = 350;
const int TILE_SIZE = 64;

struct Camera
{
	int start_x, start_y, end_x, end_y;
	int width, height;
};

struct Tile
{
	Tile()
	{
		type = -1;
		colision_box = { 0,0,0,0 };
		rect = { 0,0,0,0 };
		render_rect = { 0,0,0,0 };
	}
	int type;
	bool collision;
	SDL_Rect colision_box;
	SDL_Rect rect;
	SDL_Rect render_rect;
	void setTileColision();
};

class GameMap
{
	public:
		GameMap();
		~GameMap();

		void loadMap(std::string path);
		Tile getTile(int x, int y);

		void render();

		bool setCameraPosition(const int x1, const int y1, const int x2, const int y2);
		bool cameraMove(int x_val, int y_val);

		static void loadTile(std::string path);
		static void loadTileColision();
		static Camera getMapCamera() { return map_camera; }
	private:
		static ImageObject tile[MAX_TILE];
		static std::vector<SDL_Rect> TILE_COLISION;
		static Camera map_camera;

		std::vector<std::vector<Tile>> map;
		int render_x;
		int render_y;
		int start_x, start_y;
		int max_x, max_y;
};

