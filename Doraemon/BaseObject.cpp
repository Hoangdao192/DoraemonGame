#include "BaseObject.h"
#include "Game.h"
#include "ObjectType.h"

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

BaseObject::BaseObject(Object_type type_, int x, int y, bool visible)
{
	if (type_ < 1 || type_ > MAX_OBJECT_TYPE)
	{
		writeLog("No object type");
		return;
	}

	setObjectType(type_);
	ObjectTypeSet obj_set = ObjectType::getObjectTypeSet(type);

	loadAnimationFromFile(obj_set.animation_path);
	loadShadow(obj_set.shadow_path);
	setPosition(x, y);
	setColisionBox(obj_set.colision_box);
	setAnimation(obj_set.animation.frame_row, obj_set.animation.frame_col, obj_set.animation.frame_width, obj_set.animation.frame_height);
	setVisible(visible);
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

bool BaseObject::loadShadow(std::string path, int x, int y)
{
	////////////////////////////////////////////////////////////////////////
	//	Hàm load bóng của object với x và y là tọa độ so với ảnh của object
	//	Mặc định x = 0, y = 0
	////////////////////////////////////////////////////////////////////////
	if(shadow.loadTexture(path));
	{
		SDL_SetTextureAlphaMod(shadow.getTexture(), SHADOW_ALPHA);
		have_shadow = true;
		shadow_x = x;
		shadow_y = y - 1;
		return true;
	}
	return false;
}

bool BaseObject::loadAnimationFromFile(std::string path)
{
	return animating.loadTexture(path);
}

void BaseObject::setAnimation(const int frame_row, const int frame_col, const int frame_width, const int frame_height)
{
	animating.setFrameSheet(frame_col, frame_row);
	animating.setFrameSize(frame_width, frame_height);

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

	// Nếu object không nằm trong vùng của camera thì không render
	if (map_x_pos < map_camera.start_x && map_x_pos + width < map_camera.start_x ||
		map_x_pos > map_camera.end_x && map_x_pos + width > map_camera.end_x ||
		map_y_pos < map_camera.start_y && map_y_pos + height < map_camera.start_y ||
		map_y_pos > map_camera.end_y && map_y_pos + height > map_camera.end_y)
	{
		return;
	}

	animating.frameIncrease();
	
	animating.setRenderRect(map_x_pos - map_camera.start_x, map_y_pos - map_camera.start_y);
	
	SDL_Rect clip = animating.getCurrentRect();

	//	Thêm vào hàng đợi render
	Game::draw_queue.addToQueue(animating.getTexture(), animating.getRenderRect(), layer, clip);
	if (have_shadow)
	{
		shadow.setRenderRect(animating.getRenderRect().x + shadow_x, animating.getRenderRect().y + shadow_y);
		Game::draw_queue.addToQueue(shadow.getTexture(), shadow.getRenderRect(), layer);
	}
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
	///////////////////////////////////
	//	Đặt tọa độ của object trên map
	///////////////////////////////////
	map_x_pos = x; 
	map_y_pos = y; 
}
