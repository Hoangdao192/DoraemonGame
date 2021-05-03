#pragma once
#include "MainFunction.h"
#include "ImageObject.h"
#include "FrameSheet.h"
#include "GameMap.h"

class BaseObject
{
	public:
		BaseObject();
		~BaseObject();

		void loadAnimationFromFile(std::string path);
		void setAnimation(const int frame_row, const int frame_col, const int frame_width, const int frame_height);

		void setColisionBox(const int x, const int y, const int w, const int h);
		SDL_Rect getColisionBox() { return colision_box; }
		bool checkObjectColision(BaseObject& other_object);

		void setPosition(int x, int y);
		int getPositionX() { return x_pos; }
		int getPositionY() { return y_pos; }
		int getMapPositionX() { return map_x_pos; }
		int getMapPositionY() { return map_y_pos; }
		void render();

		void destroyObject() { visible = false; }
		
	protected:
		ImageObject image;
		FrameSheet animation;

		bool visible;

		SDL_Rect colision_box;

		int x_pos;
		int y_pos;
		int x_val;
		int y_val;
		int speed;
		int map_x_pos;
		int map_y_pos;
		int width;
		int height;
};

