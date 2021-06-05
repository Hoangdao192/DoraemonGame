#include "ObjectList.h"

ObjectList::ObjectList()
{

}

ObjectList::~ObjectList()
{
	clear();
}

void ObjectList::addObject(BaseObject* object_pointer)
{
	object_list.push_back(object_pointer);
}

bool ObjectList::erase(BaseObject* object_pointer)
{
	std::vector<BaseObject*>::iterator it = std::find(object_list.begin(), object_list.end(), object_pointer);

	if (it == object_list.end())
	{
		std::stringstream ss;
		ss << "Cannot find this object " << object_pointer << " (object_list.erase)";
		writeLog(ss.str());
		return false;
	}


	object_list.erase(it);
	std::stringstream ss;
	ss << "Delete object succesful " << object_pointer;
	writeLog(ss.str(), 1);
	return true;
}

void ObjectList::clearList()
{
	object_list.resize(0);
}

void ObjectList::clear()
{
	object_list.clear();
}

void ObjectList::renderAllObject()
{
	for (BaseObject* p_obj : object_list)
	{
		p_obj->render(3);
	}
}
