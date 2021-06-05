#pragma once
#include "MainFunction.h"
#include "BaseObject.h"

//////////////////////////////////////////////////////////////////////////
//	Lưu trữ danh sách các con trỏ trỏ đến các object hiện có trong game
//////////////////////////////////////////////////////////////////////////

class ObjectList
{
	public:
		ObjectList();
		~ObjectList();
		void addObject(BaseObject* object_pointer);
		int size() { return object_list.size(); }
		void push_back(BaseObject* object_pointer) { object_list.push_back(object_pointer); }
		void pop_back() { object_list.pop_back(); }
		bool erase(BaseObject* object_pointer);
		void clearList();
		void clear();
		void renderAllObject();
		std::vector<BaseObject*> object_list;
};

