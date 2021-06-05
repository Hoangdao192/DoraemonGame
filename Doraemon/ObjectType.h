#pragma once
#include "MainFunction.h"
#include "BaseObject.h"


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
