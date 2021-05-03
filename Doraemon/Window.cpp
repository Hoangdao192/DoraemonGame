#include "Window.h"

SDL_Renderer* Window::renderer = NULL;
int Window::windowWidth = 0;
int Window::windowHeight = 0;

Window::Window()
{
	window = NULL;
	windowTitle = " ";
}

Window::~Window()
{
	destroyWindow();
}

void Window::destroyWindow()
{
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}
	if (window != NULL)
	{
		SDL_DestroyWindow(window);
		window = NULL;
	}
}

void Window::creatWindow(std::string title, const int width, const int height)
{
	/// <summary>
	/// Create a window
	/// </summary>
	
	windowHeight = height;
	windowWidth = width;
	windowTitle = title;

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "\nError: Cannot creat window";
	}
	else std::cout << "\nCreate window succesed";

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "\nError: Cannot create renderer";
	}
	else std::cout << "\nCreate renderer succesed";

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	SDL_RenderSetLogicalSize(renderer, windowWidth, windowHeight);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
}

void Window::clearWindow()
{
	SDL_RenderClear(renderer);
}

void Window::render(SDL_Texture* pTexture, SDL_Rect* src, SDL_Rect* des)
{
	SDL_RenderCopy(renderer, pTexture, src, des);
}

void Window::display()
{
	SDL_RenderPresent(renderer);
}

void Window::resizeWindow(const int width, const int height)
{
	destroyWindow();
	creatWindow(windowTitle, width, height);
}
