#pragma once

#include <SDL.h>
#include <iostream>

class Window
{
public:
	Window();
	~Window();

	static SDL_Renderer* renderer;
	void creatWindow(std::string title, int width, int height);
	void destroyWindow();
	void resizeWindow(const int width, const int height);

	static void clearWindow();
	static void delayWindow(const int time_ms) { SDL_Delay(time_ms); }
	static void render(SDL_Texture* pTexture, SDL_Rect* src, SDL_Rect* des);
	static void display();

	static int getWindowWidth() { return windowWidth; };
	static int getWindowHeight() { return windowHeight; };
private:
	SDL_Window* window;
	static int windowWidth;
	static int windowHeight;
	std::string windowTitle;
};

