#include "BaseObject.h"
#include "Game.h"

BaseObject::BaseObject()
{
	x_pos = 0;
	y_pos = 0;
	x_val = 0;
	y_val = 0;
	width = 0;
	height = 0;
	map_x_pos = 0;
	map_y_pos = 0;
	colision_box = { 0,0,0,0 };
	have_shadow = false;
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

void BaseObject::loadShadow(std::string path, int x, int y)
{
	have_shadow = true;
	shadow.loadTexture(path);
	SDL_SetTextureAlphaMod(shadow.getTexture(), 50);
	shadow_x = x;
	shadow_y = y-1;
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
}

void BaseObject::setColisionBox(const int x, const int y, const int w, const int h)
{
	colision_box.x = x;
	colision_box.y = y;
	colision_box.w = w;
	colision_box.h = h;
}

void BaseObject::setColisionBox(const SDL_Rect colision_box_rect)
{
	colision_box.x = colision_box_rect.x;
	colision_box.y = colision_box_rect.y;
	colision_box.w = colision_box_rect.w;
	colision_box.h = colision_box_rect.h;
}

void BaseObject::render(int layer)
{
	if (!visible) return;
	Camera map_camera = GameMap::getMapCamera();

	//	Kiểm tra xem đối tượng có nằm trong vùng màn hình hiển thị không
	if (map_x_pos < map_camera.start_x && map_x_pos + width < map_camera.start_x ||
		map_x_pos > map_camera.end_x && map_x_pos + width > map_camera.end_x ||
		map_y_pos < map_camera.start_y && map_y_pos + height < map_camera.start_y ||
		map_y_pos > map_camera.end_y && map_y_pos + height > map_camera.end_y)
	{
		return;
	}

	animation.frameIncrease();
	image.setRenderRect(map_x_pos - map_camera.start_x, map_y_pos - map_camera.start_y);
	SDL_Rect clip = animation.getCurrentRect();

	//	Thêm vào hàng đợi render
	
	Game::draw_queue.addToQueue(image.getTexture(), image.getRenderRect(), layer, clip);
	if (have_shadow)
	{
		shadow.setRenderRect(image.getRenderRect().x + shadow_x, image.getRenderRect().y + shadow_y);
		Game::draw_queue.addToQueue(shadow.getTexture(), shadow.getRenderRect(), layer);
	}
	//image.render(&clip);
}

bool BaseObject::checkObjectColision(BaseObject& other_object)
{
	/////////////////////////////////////////
	//	Kiểm tra va chạm với đối tượng khác
	/////////////////////////////////////////

	//	Lấy tọa độ của hộp va chạm
	SDL_Rect this_obj = colision_box;
	SDL_Rect other_obj = other_object.getColisionBox();
	//	Tính toán tọa độ trên map của hộp va chạm
	this_obj.x += map_x_pos +x_val;
	this_obj.y += map_y_pos +y_val;
	other_obj.x += other_object.getMapPositionX();
	other_obj.y += other_object.getMapPositionY();

	//	Va chạm phải dưới
	if (this_obj.x <= other_obj.x && other_obj.x <= this_obj.x + this_obj.w
		&& this_obj.y <= other_obj.y && other_obj.y <= this_obj.y+this_obj.h)
	{
		return true;
	}
	//	Va chạm trái dưới
	if (other_obj.x <= this_obj.x && this_obj.x <= other_obj.x + other_obj.w
		&& this_obj.y <= other_obj.y && other_obj.y <= this_obj.y + this_obj.h)
	{
		return true;
	}
	//	Va chạm trái trên
	if (other_obj.x <= this_obj.x && this_obj.x <= other_obj.x + other_obj.w
		&& other_obj.y <= this_obj.y && this_obj.y <= other_obj.y + other_obj.h)
	{
		return true;
	}
	//	Va chạm phải trên
	if (this_obj.x <= other_obj.x && other_obj.x <= this_obj.x + this_obj.w
		&& other_obj.y <= this_obj.y && this_obj.y <= other_obj.y + other_obj.h)
	{
		return true;
	}

	return false;
}

void BaseObject::setPosition(int x, int y) 
{ 
	//	Đặt tọa độ của đối tượng trên map
	map_x_pos = x; 
	map_y_pos = y; 
}
