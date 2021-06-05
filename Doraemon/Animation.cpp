#include "Animation.h"
Animation::Animation()
{
	current_rect = { 0,0,0,0 };

	frame_width = 0;
	frame_height = 0;
	total_frame = 0;
	current_frame = 0;

	//	ROW COL
	frame_sheet[0] = 0;
	frame_sheet[1] = 0;
}

Animation::~Animation()
{

}

void Animation::setFrameSize(const int width, const int height)
{
	frame_width = width;
	frame_height = height;

	current_rect.w = frame_width;
	current_rect.h = frame_height;
}

void Animation::setFrameSheet(const int row, const int col)
{
	frame_sheet[0] = row;
	frame_sheet[1] = col;
	total_frame = row * col;
}

void Animation::frameIncrease()
{

	checkInit();

	++current_frame;
	if (current_frame == total_frame) current_frame = 0;

	int current_row = current_frame / frame_sheet[1];
	int current_col = current_frame % frame_sheet[1];

	current_rect.x = current_col * frame_width;
	current_rect.y = current_row * frame_height;
}

SDL_Rect Animation::getCurrentRect()
{
	checkInit();
	return current_rect;
}

void Animation::checkInit()
{
	if (frame_height == 0 || frame_width == 0)
	{
		writeLog("Frame size not set", 0);
	}

	if (frame_sheet[0] == 0 || frame_sheet[1] == 0)
	{
		writeLog("Frame sheet not set", 0);
	}
}


void Animation::gotoFrame(const int frame) 
{
	///////////////////////////////////////////////////
	//	Nhảy cóc đến một frame bất kì nếu frame tồn tại
	//	Ngược lại báo lỗi và không làm gì cả
	///////////////////////////////////////////////////
	if (current_frame < 0 || current_frame >= total_frame)
	{
		writeLog("This animation does not have this frame", 0);
		return;
	}
	current_frame = frame; 
}
