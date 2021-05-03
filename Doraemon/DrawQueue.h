#pragma once
#include "MainFunction.h"
#include "Window.h"

struct DrawNode
{
	DrawNode(SDL_Texture* texture_pointer, SDL_Rect rect_, SDL_Rect clip_ = { 0,0,0,0 })
	{
		p_texture = texture_pointer; 
		rect = rect_;
		clip = clip_;
		pos = rect.y + rect.h;
	}
	SDL_Texture* p_texture;
	SDL_Rect rect;
	SDL_Rect clip;
	int pos;
};

class DrawQueue
{
	public:
		DrawQueue();
		~DrawQueue();

		//	Thêm đối tượng render vào hàng đợi tại layer , layer = -1 tức là tạo một layer mới trên cùng
		void addToQueue(SDL_Texture* texture_pointer, SDL_Rect rect_, const int layer = -1, SDL_Rect clip_ = { 0,0,0,0 });
		//	Xóa một layer, layer = -1: xóa layer trên cùng
		void deleteLayer(const int layer = -1);
		//	Xóa một đối tượng khỏi một layer
		void deleteNode(const int node, const int layer);

		int getQueueSize() const { return queue.size(); }
		int getLayerSize(const int layer);
		int getCurrentLayer() { return queue.size() - 1; }

		void render();
		void renderLayer(const int layer);

		void eraseQueue();

	private:
		std::vector<std::vector<DrawNode>> queue;
		//	Sắp xếp thứ tự hiển thị trước sau trong một layer
};

