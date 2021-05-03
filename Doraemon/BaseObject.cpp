#include "BaseObject.h"
#include "Game.h"

BaseObject::BaseObject()
{
	x_pos = 0;
	y_pos = 0;
	width = 0;
	height = 0;
	map_x_pos = 0;
	map_y_pos = 0;
	colision_box = { 0,0,0,0 };
	visible = true;
}

BaseObject::~BaseObject()
{
	x_pos = 0;
	y_pos = 0;
	width = 0;
	height = 0;
	map_x_pos = 0;
	map_y_pos = 0;
	colision_box = { 0,0,0,0 };
	visible = false;
}

void BaseObject::loadAnimationFromFile(std::string path)
{
	image.loadTexture(path);
}

void BaseObject::setAnimation(const int frame_row, const int frame_col, const int frame_width, const int frame_height)
{
	animation.setFrameSheet(frame_row, frame_col);
	animation.setFrameSize(frame_width, frame_height);
	width = frame_width;
	height = frame_height;
	image.setRenderRect(x_pos, y_pos, frame_width, frame_height);
}

void BaseObject::setColisionBox(const int x, const int y, const int w, const int h)
{
	colision_box.x = x;
	colision_box.y = y;
	colision_box.w = w;
	colision_box.h = h;
}

void BaseObject::render()
{
	if (!visible) return;
	Camera map_camera = GameMap::getMapCamera();

	if (map_x_pos < map_camera.start_x && map_x_pos + width < map_camera.start_x || 
		map_x_pos > map_camera.end_x && map_x_pos + width > map_camera.end_x ||
		map_y_pos < map_camera.start_y && map_y_pos + height < map_camera.start_y || 
		map_y_pos > map_camera.end_y && map_y_pos + height > map_camera.end_y)
		return;

	animation.frameIncrease();
	image.setRenderRect(map_x_pos - map_camera.start_x, map_y_pos - map_camera.start_y);
	SDL_Rect clip = animation.getCurrentRect();

	Game::draw_queue.addToQueue(image.getTexture(), image.getRenderRect(), 3, clip);
	image.render(&clip);
}

bool BaseObject::checkColision(BaseObject& other_object)
{
	SDL_Rect this_obj = colision_box;
	SDL_Rect other_obj = other_object.getColisionBox();

	this_obj.x += x_pos;
	this_obj.y += y_pos;
	other_obj.x += other_object.getPositionX();
	other_obj.y += other_object.getPositionY();

	if (this_obj.x <= other_obj.x && other_obj.x <= this_obj.x + this_obj.w
		&& this_obj.y <= other_obj.y && other_obj.y <= this_obj.y+this_obj.h)
	{
		return true;
	}

	if (other_obj.x <= this_obj.x && this_obj.x <= other_obj.x + other_obj.w
		&& this_obj.y <= other_obj.y && other_obj.y <= this_obj.y + this_obj.h)
	{
		return true;
	}

	if (other_obj.x <= this_obj.x && this_obj.x <= other_obj.x + other_obj.w
		&& other_obj.y <= this_obj.y && this_obj.y <= other_obj.y + other_obj.h)
	{
		return true;
	}

	if (this_obj.x <= other_obj.x && other_obj.x <= this_obj.x + this_obj.w
		&& other_obj.y <= this_obj.y && this_obj.y <= other_obj.y + other_obj.h)
	{
		return true;
	}

	return false;
}

void BaseObject::setPosition(int x, int y) 
{ 
	map_x_pos = x; 
	map_y_pos = y; 
	//image.setRenderRect(x, y);
}
