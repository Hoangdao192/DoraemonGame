#include "ImageObject.h"

ImageObject::ImageObject()
{
	p_texture = NULL;
	src_rect = { 0,0,0,0 };
	render_rect = { 0,0,0,0 };
	clip_rect = NULL;
}

ImageObject::~ImageObject()
{
	destroyTexture();
	src_rect = { 0,0,0,0 };
	render_rect = { 0,0,0,0 };
	clip_rect = NULL;
}

ImageObject::ImageObject(std::string path)
{
	p_texture = NULL;
	src_rect = { 0,0,0,0 };
	render_rect = { 0,0,0,0 };
	clip_rect = NULL;
	loadTexture(path);
}

void ImageObject::loadTexture(std::string path)
{
	if (path == "none")
	{
		std::cout << "Nothing to load";
		return;
	}

	SDL_Surface* temp_surface = NULL;
	temp_surface = IMG_Load(path.c_str());
	if (temp_surface == NULL)
	{
		std::cout << "\nError: cannot load file " << path;
	}
	else
	{
		std::cout << "\nLoad file " << path << " succes";
	}

	destroyTexture();
	p_texture = SDL_CreateTextureFromSurface(Window::renderer, temp_surface);
	if (p_texture == NULL)
	{
		std::cout << "\nError: cannot create texture from surface " << path;
	}
	else
	{
		std::cout << "\nCreate texture succes " << path << " succes";
	}

	//	Kích thước gốc của hình ảnh
	src_rect.w = temp_surface->w;
	src_rect.h = temp_surface->h;
	//	Mặc định kích thước in ra màn hình là kích thước gốc
	render_rect.w = temp_surface->w;
	render_rect.h = temp_surface->h;

	SDL_FreeSurface(temp_surface);
}

void ImageObject::destroyTexture()
{
	if (p_texture != NULL)
	{
		SDL_DestroyTexture(p_texture);
		std::cout << "\nTexture destroyed";
	}
	p_texture = NULL;
}

void ImageObject::setRenderRect(const int x, const int y, const int w, const int h)
{
	render_rect.x = x;
	render_rect.y = y;
	if (w != 0) render_rect.w = w;
	if (h != 0) render_rect.h = h;
}

void ImageObject::render(SDL_Rect* clip)
{
	Window::render(p_texture, clip, &render_rect);
}
