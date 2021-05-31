#pragma once
#include "MainFunction.h"
#include "BaseObject.h"

struct Animation_info
{
	int frame_col;
	int frame_row;
	int frame_width;
	int frame_height;
};

struct ObjectTypeSet
{
	std::string type_name;
	std::string animation_path;
	std::string shadow_path;
	Animation_info animation;
	SDL_Rect colision_box;
};

const int MAX_OBJECT_TYPE = 20;

class ObjectType
{
	public:
		ObjectType() {};
		~ObjectType() {};
		static void loadObjectMap();
		static ObjectTypeSet getObjectTypeSet(Object_type type);
	private:	
		static std::map<Object_type, ObjectTypeSet> object_map;
};

BaseObject createObject(Object_type type, int x = 0, int y = 0, bool visivle = true);
