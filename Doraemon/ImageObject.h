#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Window.h"

class ImageObject
{
	public:
		ImageObject();
		ImageObject(std::string path);
		~ImageObject();

		void loadTexture(std::string path);
		void destroyTexture();
		SDL_Texture* getTexture() { return p_texture; }

		void setRenderRect(const int x, const int y, const int w = 0, const int h = 0);
		void render(SDL_Rect* clip = NULL);

		SDL_Rect getSrcRect() const { return src_rect; }
		SDL_Rect getRenderRect() const { return render_rect; }

		SDL_Rect* getClipRect() const { return clip_rect; }
		
		void operator = (ImageObject &other)
		{
			p_texture = other.getTexture();
			src_rect = other.getSrcRect();
			render_rect = other.getRenderRect();
			clip_rect = other.getClipRect();
		}
	private:
		SDL_Texture* p_texture;
		SDL_Rect src_rect;
		SDL_Rect render_rect;
		SDL_Rect* clip_rect;
};

