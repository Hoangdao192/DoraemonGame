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
    rock.setPosition(70, 88);

    BaseObject rock2;
    rock2.loadAnimationFromFile("acces/rock2.png");
    rock2.setAnimation(1, 1, 52, 132);
    rock2.setColisionBox(0, 100, 52, 32);
    rock2.setPosition(198, -4);

    BaseObject rock3;
    rock3.loadAnimationFromFile("acces/rock1.png");
    rock3.setAnimation(1, 1, 52, 76);
    rock3.setColisionBox(0, 46, 52, 30);
    rock3.setPosition(198, 245);

    BaseObject chest1;
    chest1.loadAnimationFromFile("acces/chest.png");
    chest1.setAnimation(1, 1, 64, 62);
    chest1.setColisionBox(0, 37, 64, 25);
    chest1.setPosition(544, 109);

    BaseObject rock_benches;
    rock_benches.loadAnimationFromFile("acces/gheda2.png");
    rock_benches.setAnimation(1, 1, 54, 122);
    rock_benches.setColisionBox(0, 22, 54, 100);
    rock_benches.setPosition(842, -12);

    BaseObject rock_column1;
    rock_column1.loadAnimationFromFile("acces/rock_column.png");
    rock_column1.setAnimation(1, 1, 64, 154);
    rock_column1.setColisionBox(0, 100, 64, 54);
    rock_column1.setPosition(1060, 62);

    BaseObject rock_column2;
    rock_column2.loadAnimationFromFile("acces/rock_column.png");
    rock_column2.setAnimation(1, 1, 64, 154);
    rock_column2.setColisionBox(0, 100, 64, 54);
    rock_column2.setPosition(1060, 326);

    BaseObject rock_column3;
    rock_column3.loadAnimationFromFile("acces/rock_column.png");
    rock_column3.setAnimation(1, 1, 64, 154);
    rock_column3.setColisionBox(0, 100, 64, 54);
    rock_column3.setPosition(1060, 326);

    game.object_list.addObject(&rock);
    game.object_list.addObject(&rock2);
    game.object_list.addObject(&rock3);
    game.object_list.addObject(&chest1);
    game.object_list.addObject(&rock_benches);
    game.object_list.addObject(&rock_column1);
    game.object_list.addObject(&rock_column2);

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

        map1.render(0);
        map1s.render(1);
        map2.render(2);

        player.render(3);
        rock.render(3);
        rock2.render(3);
        rock3.render(3);
        chest1.render(3);
        rock_benches.render(3);
        rock_column1.render(3);
        rock_column2.render(3);
        

        game.draw();
    }
}