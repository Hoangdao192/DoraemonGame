#pragma once
#include "ImageObject.h"
#include "MainFunction.h"
class Animation : public ImageObject
{
	public:
		Animation();
		~Animation();

		void setFrameSize(const int width, const int height);
		void setFrameSheet(const int row, const int col);
		void checkInit();

		int getFrameWidth() const { return frame_width; }
		int getFrameHeight() const { return frame_height; }

		//	Nhảy cóc đến một frame bất kì
		void gotoFrame(const int frame);

		int getCurrentFrame() const { return current_frame; }
		int getTotalFrame() const { return total_frame; }
		void frameIncrease();

		int getFrameRow() const { return frame_sheet[0]; }
		int getFrameCol() const { return frame_sheet[1]; }

		SDL_Rect getCurrentRect();

		void operator= (Animation& other)
		{
			current_rect = other.getCurrentRect();
			frame_width = other.getFrameWidth();
			frame_height = other.getFrameHeight();
			total_frame = other.getTotalFrame();
			current_frame = other.getCurrentFrame();
			frame_sheet[0] = other.getFrameRow();
			frame_sheet[1] = other.getFrameCol();
		}

	private:

		SDL_Rect current_rect;

		int frame_width;
		int frame_height;
		int total_frame;
		int current_frame;

		//	ROW COL
		int frame_sheet[2];
};

