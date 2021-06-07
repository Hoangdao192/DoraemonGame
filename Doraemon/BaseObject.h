#pragma once
#include "MainFunction.h"
#include "ImageObject.h"
#include "GameMap.h"
#include "Animation.h"


class BaseObject
{
	public:
		BaseObject();
		// Tạo một object mới với mẫu có sẵn
		BaseObject(Object_type type_, int x = 0, int y = 0, bool visible = true);
		~BaseObject();

		void setObjectType(Object_type type) { this->type = type; }
		Object_type getObjectType() { return type; }

		void setVisible(bool is_visible) { visible = is_visible; }
		bool getVisible() { return visible; }

		//x và y là tọa độ so với ảnh nhân vật
		bool loadShadow(std::string path, int x = 0, int y = 0);
		bool loadAnimationFromFile(std::string path);
		void setAnimation(const int frame_row, const int frame_col, const int frame_width, const int frame_height);

		void setColisionBox(const int x, const int y, const int w, const int h);
		void setColisionBox(const SDL_Rect colision_box_rect);
		SDL_Rect getColisionBox() { return colision_box; }
		bool checkObjectColision(BaseObject& other_object);

		void setPosition(int x, int y);
		int getPositionX() { return x_pos; }
		int getPositionY() { return y_pos; }
		int getMapPositionX() { return map_x_pos; }
		int getMapPositionY() { return map_y_pos; }
		void render(int layer = 0);

		void destroyObject() { visible = false; }
		
	protected:

		Object_type type;

		bool have_shadow;
		Animation shadow;
		Animation animation;

		bool visible;

		SDL_Rect colision_box;

		int x_pos;
		int y_pos;

		int shadow_x;
		int shadow_y;

		int x_val;
		int y_val;
		int speed;
		int map_x_pos;
		int map_y_pos;

		int width;
		int height;
		int weight;
};

