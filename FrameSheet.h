#pragma once

#include "MainFunction.h"

class FrameSheet
{
	public:
		FrameSheet();
		~FrameSheet();

		void setFrameSize(const int width, const int height);
		void setFrameSheet(const int row, const int col);
		void checkInit();

		int getFrameWidth() const { return frame_width; }
		int getFrameHeight() const { return frame_height; }

		void gotoFrame(const int frame) { current_frame = frame; }
		int getCurrentFrame() const { return current_frame; }
		int getTotalFrame() const { return total_frame; }
		void frameIncrease();

		int getFrameRow() const { return frame_sheet[0]; }
		int getFrameCol() const { return frame_sheet[1]; }

		SDL_Rect getCurrentRect();

		void operator= (FrameSheet &other)
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

