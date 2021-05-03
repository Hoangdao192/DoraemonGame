#include "FrameSheet.h"

FrameSheet::FrameSheet()
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

FrameSheet::~FrameSheet()
{

}

void FrameSheet::setFrameSize(const int width, const int height)
{
	frame_width = width;
	frame_height = height;

	current_rect.w = frame_width;
	current_rect.h = frame_height;
}

void FrameSheet::setFrameSheet(const int row, const int col)
{
	frame_sheet[0] = row;
	frame_sheet[1] = col;
	total_frame = row * col;
}

void FrameSheet::frameIncrease()
{

	checkInit();

	++current_frame;
	if (current_frame == total_frame) current_frame = 0;
	int current_row = current_frame / frame_sheet[1];
	int current_col = current_frame % frame_sheet[1];

	current_rect.x = current_col * frame_width;
	current_rect.y = current_row * frame_height;
}

SDL_Rect FrameSheet::getCurrentRect()
{
	checkInit();

	return current_rect;
}

void FrameSheet::checkInit()
{
	if (frame_height == 0 || frame_width == 0)
	{
		std::cout << "Error: Frame size not set";
	}

	if (frame_sheet[0] == 0 || frame_sheet[1] == 0)
	{
		std::cout << "Error: Frame sheet not set";
	}
}
