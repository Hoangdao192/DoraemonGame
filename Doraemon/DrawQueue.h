#pragma once
#include "MainFunction.h"
#include "Window.h"

/*
	Hàng đợi render được cài đặt như sau:
		Hàng đợi gồm 10 layer, mỗi layer sẽ là tập hợp các DrawNode
		Layer có chỉ số nhỏ hơn được render trước
		(thứ tự render: 1 -> 2 -> 3 -> 4 ... -> 10)

		Mỗi Layer chứa:
		-	Chứa thông tin về hình ảnh sẽ in ra và vị trí in ra màn hình của hình ảnh đó
			(Gọi là một DrawNode)
		-	Hình ảnh:
		   x1
		  y1* * * * * * * *
			*			  *
			*			  *
			* * * * * * * *y2
						  x2
		-	Các DrawNode được sắp xếp theo thứ tự từ nhỏ đến lớn theo y2
			(y2 lớn hơn đứng sau)
		-	DrawNode nào đứng trước được render trước
*/

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
	//	Pos ở đây chính là y2
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

		//	Chèn một layer vào vị trí đã định
		//	Nếu position lớn hơn vị trí lớn nhất -> chèn vào cuối
		//	Nếu position nhỏ hơn vị trí nhỏ nhất -> chèn vào đầu
		void insertLayer(std::vector<DrawNode> layer, const int position);

		int getQueueSize() const { return queue.size(); }
		int getLayerSize(const int layer);
		int getCurrentLayer() { return queue.size() - 1; }

		void render();
		void renderLayer(const int layer);

		void eraseQueue();

	private:
		std::vector<std::vector<DrawNode>> queue;
};

