#pragma once
#include "MainFunction.h"
#include "BaseObject.h"
#include "MainObject.h"

//////////////////////////////////////////////////////////////////////////
//	Lưu trữ danh sách các con trỏ trỏ đến các đối tượng hiện có trong game
//////////////////////////////////////////////////////////////////////////

class ObjectList
{
	public:
		ObjectList();
		~ObjectList();
		void addObject(BaseObject* object_pointer);
		void deleteObject(BaseObject* object_pointer);
		void clearList();
		std::vector<BaseObject*> object_list;
};

