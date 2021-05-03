#pragma once
#include "MainFunction.h"
#include "ImageObject.h"
#include "FrameSheet.h"
#include "MainObject.h"
#include "GameMap.h"
#include "BaseObject.h"
#include "MainAcces.h"
#include "DrawQueue.h"

class Game
{
	public:
		Game();
		~Game();

		void setFPS(const int fps_) { fps = fps_; fps_time_delay = 1000 / fps; }
		int getFPS() const { return fps; }

		void update();
		void doThing();
		void draw();

		void quitGame() { running = false; }

		bool isRunning() const { return running; }

		static DrawQueue draw_queue;

		SDL_Event window_event;
	private:
		bool running;

		int fps;
		int fps_time_delay;
		int fps_start_time;
		int fps_current_time;

		int game_start_time;
		int game_current_time;

		
};

void mainGame();

