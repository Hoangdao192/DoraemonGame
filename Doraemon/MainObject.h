#pragma once
#include "MainFunction.h"
#include "ImageObject.h"
#include "GameMap.h"
#include "BaseObject.h"
#include "ObjectList.h"

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

		bool checkColision(GameMap& map_data, ObjectList& obj_list);
		bool checkObjectListColision(ObjectList &object_list);
		bool checkMapColision(GameMap& map_data);
		bool checkTileColision(Tile &tile);

		void move(GameMap& map_data, ObjectList& obj_list);
		void doThing(GameMap& map_data, ObjectList &obj_list);
		void handleInputAction(SDL_Event &window_event);

		void checkAnimation();
		virtual void render(int layer = 0);



	private:

		Animation* main_ani;

		int main_speed;

		MoveType movement;

		Animation walkdown;
		Animation walkup;
		Animation stand;
		Animation walkright;
		Animation walkleft;		
};

