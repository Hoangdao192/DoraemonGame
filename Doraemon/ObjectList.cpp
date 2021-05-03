#include "ObjectList.h"

ObjectList::ObjectList()
{

}

ObjectList::~ObjectList()
{
	clearList();
}

void ObjectList::addObject(BaseObject* object_pointer)
{
	object_list.push_back(object_pointer);
}

void ObjectList::deleteObject(BaseObject* object_pointer)
{
	bool ret = false;
	for (int i = 0; i < object_list.size(); ++i)
	{
		if (object_pointer == object_list[i])
		{
			ret = true;
			object_list.erase(object_list.begin() + i);
			std::cout << "\nDelete object successed";
		}
	}

	if (!ret)
	{
		std::cout << "\nError: cannot find object " << object_pointer;
	}
}

void ObjectList::clearList()
{
	object_list.resize(0);
}
