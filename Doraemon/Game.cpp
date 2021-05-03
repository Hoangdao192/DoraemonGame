#include "Game.h"

DrawQueue Game::draw_queue;
ObjectList Game::object_list;

Game::Game()
{
    running = true;
	game_start_time = SDL_GetTicks();
    object_list.clearList();
}

Game::~Game()
{
    draw_queue.~DrawQueue();
    object_list.~ObjectList();
}

void Game::update()
{
	fps_start_time = SDL_GetTicks();
	game_current_time = SDL_GetTicks();
    draw_queue.eraseQueue();
    Window::clearWindow();
}

void Game::doThing()
{

}

void Game::draw()
{
	draw_queue.render();
	Window::display();
	fps_current_time = SDL_GetTicks();
	if (fps_current_time - fps_start_time <= fps_time_delay)
	{
		SDL_Delay(fps_time_delay - (fps_current_time - fps_start_time));
	}
}

void mainGame()
{
	Game game;
    game.setFPS(30);


    GameMap map1, map2, map1s;
    GameMap::loadTile("acces/ground_tile/");
    GameMap::loadTileColision();

    map1.loadMap("acces/map1_layer1.txt");
    map1.setCameraPosition(0, 0, Window::getWindowWidth(), Window::getWindowHeight());
    map2.loadMap("acces/map1_layer2.txt");
    map1s.loadMap("acces/map1_layer1s.txt");

    MainObject player;

    BaseObject rock;
    rock.loadAnimationFromFile("acces/rock3.png");
    rock.setAnimation(1, 1, 52, 104);
    rock.setColisionBox(0, 72, 52, 32);
    rock.setPosition(30, 100);


    game.object_list.addObject(&rock);
    while (game.isRunning())
    {
        game.update();

        if (SDL_WaitEventTimeout(&game.window_event, 1) != 0)
        {
            if (game.window_event.type == SDL_QUIT) game.quitGame();
            if (game.window_event.type == SDL_KEYDOWN || game.window_event.type == SDL_KEYUP)
                player.handleInputAction(game.window_event);

        }

        player.doThing(map2);
        map1.cameraMove(0, 0);
        map1s.cameraMove(0, 0);

        map1.render();
        map1s.render();
        map2.render();

        player.render();
        rock.render();
        

        game.draw();
        
    }
}