#pragma once
#include "MainFunction.h"
#include "ImageObject.h"
#include "FrameSheet.h"
#include "GameMap.h"
#include "BaseObject.h"

const int PLAYER_SPEED = 6;
const int MAIN_FRAME_HEIGHT = 57;
const int MAIN_FRAME_WIDTH = 39;
const int MAIN_COLISION_BOX = 64;

struct MoveType
{
	int left;
	int right;
	int up;
	int down;
};


class MainObject : public BaseObject
{
	public:
		MainObject();
		~MainObject();
		void loadAnimation();

		bool checkMapColision(GameMap& map_data);
		bool checkTileColision(Tile &tile);

		void move(GameMap& map_data);
		void doThing(GameMap& map_data);
		void handleInputAction(SDL_Event &window_event);

		void checkAnimation();
		virtual void render();



	private:
		int x_val;
		int y_val;

		ImageObject* main_img;
		FrameSheet* main_animation;

		int main_speed;

		MoveType movement;

		ImageObject walkdown_img;
		ImageObject walkup_img;
		ImageObject stand_img;
		ImageObject walkright_img;
		ImageObject walkleft_img;

		FrameSheet walkleft_animation;
		FrameSheet walkup_animation;
		FrameSheet walkdown_animation;
		FrameSheet walkright_animation;
		FrameSheet stand_animation;
		
};

