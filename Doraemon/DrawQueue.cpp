#include "DrawQueue.h"

DrawQueue::DrawQueue()
{
	queue.resize(10);
}

DrawQueue::~DrawQueue()
{
	eraseQueue();
}

void DrawQueue::addToQueue(SDL_Texture* texture_pointer, SDL_Rect rect_, const int layer, SDL_Rect clip_)
{
	DrawNode new_node(texture_pointer, rect_, clip_);

	//	Layer không tồn tại
	if (layer > queue.size() - 1 && layer != - 1)
	{
		std::cout << "\nError: layer " << layer << " is not exists";
		return;
	}

	//	Tạo layer mới
	if (layer == -1)
	{
		std::vector<DrawNode> temp;
		temp.push_back(new_node);
		queue.push_back(temp);
		return;
	}

	//	Sắp xếp node vào vị trí phù hợp theo thứ tự tăng dần của vị trí y
	if (queue[layer].size() > 0)
	{
		//Thêm vào đầu layer
		if (new_node.pos <= queue[layer][0].pos)
		{
			queue[layer].insert(queue[layer].begin(), new_node);
			return;
		}
		//Thêm vào cuối layer
		if (new_node.pos >= queue[layer][queue[layer].size()-1].pos)
		{
			queue[layer].push_back(new_node);
			return;
		}
		//	Thêm vào giữa layer
		for (int i = 0; i < queue[layer].size()-1; ++i)
		{
			if (queue[layer][i].pos <= new_node.pos <= queue[layer][i + 1].pos)
			{
				queue[layer].insert(queue[layer].begin() + i + 1, new_node);
				return;
			}
		}
	}

	//	Trường hợp layer không có gì
	queue[layer].push_back(new_node);
}

void DrawQueue::deleteLayer(const int layer)
{
	if (layer >= queue.size())
	{
		std::cout << "\nError: layer " << layer << " is not exists";
		return;
	}

	if (layer == -1)
	{
		queue.pop_back();
		return;
	}

	queue.erase(queue.begin() + layer);
}

void DrawQueue::deleteNode(const int node, const int layer)
{
	if (layer >= queue.size())
	{
		std::cout << "\nError: layer " << layer << " is not exists";
		return;
	}

	if (node >= queue[layer].size())
	{
		std::cout << "Error: Node layer is not exists";
		return;
	}

	queue[layer].erase(queue[layer].begin() + node);
}

void DrawQueue::insertLayer(std::vector<DrawNode> layer, const int position)
{
	if (position < 0)
	{
		queue.insert(queue.begin(), layer);
		return;
	}
	if (position >= queue.size())
	{
		queue.push_back(layer);
		return;
	}
	queue.insert(queue.begin() + position, layer);
}

int DrawQueue::getLayerSize(const int layer)
{
	if (layer >= queue.size())
	{
		std::cout << "\nError: layer " << layer << " is not exists";
		return 0;
	}

	return queue[layer].size();
}

void DrawQueue::render()
{
	//Render toàn bộ hàng đợi

	for (int i = 0; i < queue.size(); ++i)
	{
		renderLayer(i);
	}
}

void DrawQueue::renderLayer(const int layer)
{
	//	Render từng layer

	if (layer >= queue.size())
	{
		std::cout << "\nError: layer " << layer << " is not exists";
		return;
	}

	for (int i = 0; i < queue[layer].size(); ++i)
	{
		if (queue[layer][i].clip.w == 0)
			Window::render(queue[layer][i].p_texture, NULL, &queue[layer][i].rect);
		else Window::render(queue[layer][i].p_texture, &queue[layer][i].clip, &queue[layer][i].rect);
	}
}

void DrawQueue::eraseQueue()
{
	for (int i = 0; i < queue.size(); ++i)
	{
		
		while (queue[i].size() > 0 )
		{
			queue[i].pop_back();
		}
	}
}