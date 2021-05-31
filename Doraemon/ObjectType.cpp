#include "ObjectType.h"

std::map<Object_type, ObjectTypeSet> ObjectType::object_map;
void ObjectType::loadObjectMap()
{
	//////////////////////////////////////////////////////////////////////////////////
	//Load đường dẫn ảnh và thông số về animation và colision box cho từng loại object
	//////////////////////////////////////////////////////////////////////////////////

	std::fstream file("acces/ObjectTypeSet.txt", std::ios::in);
	std::string line;
	std::getline(file, line);
	while (!file.eof())
	{
		std::getline(file, line);
		std::stringstream ss(line);

		ObjectTypeSet new_set;
		ss >> new_set.type_name;
		int code;
		ss >> code;

		ss >> new_set.animation_path;
		ss >> new_set.shadow_path;

		ss >> new_set.animation.frame_col >> new_set.animation.frame_row >> new_set.animation.frame_width >> new_set.animation.frame_height;
		ss >> new_set.colision_box.x >> new_set.colision_box.y >> new_set.colision_box.w >> new_set.colision_box.h;

		std::cout << new_set.type_name << " " << new_set.animation_path << " " << new_set.shadow_path << "\n";
		std::cout << new_set.animation.frame_col << " " << new_set.animation.frame_row << " " << new_set.animation.frame_width << " " << new_set.animation.frame_height << "\n";
		std::cout << new_set.colision_box.x << " " << new_set.colision_box.y << " " << new_set.colision_box.w << " " << new_set.colision_box.h << "\n";

		object_map[(Object_type) code] = new_set;
	}
}

ObjectTypeSet ObjectType::getObjectTypeSet(Object_type type)
{
	//////////////////////////////
	//	Lấy set của 1 loại object
	//////////////////////////////
	return object_map[type];
}

BaseObject createObject(Object_type type, int x, int y, bool visible)
{
	ObjectTypeSet obj_set = ObjectType::getObjectTypeSet(type);

	BaseObject *new_obj = new BaseObject;
	new_obj->loadAnimationFromFile(obj_set.animation_path);
	new_obj->loadShadow(obj_set.shadow_path);
	new_obj->setPosition(x, y);
	new_obj->setColisionBox(obj_set.colision_box);
	new_obj->setAnimation(obj_set.animation.frame_row, obj_set.animation.frame_col, obj_set.animation.frame_width, obj_set.animation.frame_height);
	new_obj->setVisible(visible);

	return *new_obj;
}