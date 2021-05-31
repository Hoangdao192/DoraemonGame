#include "Game.h"
#include "ObjectType.h"

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

    ObjectType::loadObjectMap();


    GameMap map1, map2, map1s;
    GameMap::loadTile("acces/ground_tile/");
    GameMap::loadTileColision();

    map1.loadMap("acces/map1_layer1.txt");
    map1.setCameraPosition(0, 0, Window::getWindowWidth(), Window::getWindowHeight());
    map2.loadMap("acces/map1_layer2.txt");
    map1s.loadMap("acces/map1_layer1s.txt");

    MainObject player;

    BaseObject rock = createObject(ROCK_COLUMN_3, 70, 88);
    BaseObject rock2 = createObject(ROCK_COLUMN_2, 198, -4);
    BaseObject rock3 = createObject(ROCK_COLUMN_1, 198, 245);
    BaseObject chest1 = createObject(CHEST_1, 544, 109);
    BaseObject rock_benches = createObject(BENCHE_LEFT, 842, -12);
    BaseObject rock_column1 = createObject(ROCK_COLUMN_4, 1060, 62);
    BaseObject rock_column2 = createObject(ROCK_COLUMN_4, 1060, 326);
    BaseObject rock_column3 = createObject(ROCK_COLUMN_4, 521, 326);
    BaseObject rock_well = createObject(BREAK_WELL, -23, 286);
    BaseObject break_rock_col = createObject(ROCK_COLUMN_5, 717, 366);
    BaseObject rock_bench = createObject(BENCHE_FRONT, 264, 587);
    BaseObject rock_bench1 = createObject(BENCHE_FRONT, 456, 587);
    BaseObject flag = createObject(SIGN_LEFT, 405, 699);
    BaseObject rip = createObject(RIP_1, 774, 794);
    BaseObject rip1 = createObject(RIP_2, 834, 742);
    BaseObject rip2 = createObject(RIP_3, 962, 824);
    BaseObject tomb = createObject(TOMB_VERTICAL, 1184, 480);
    BaseObject lamp = createObject(ROCK_LAMP, 1215, 688);
    BaseObject jar = createObject(JAR_1, 982, 537);
    BaseObject jar2 = createObject(JAR_2, 1056, 608);

    game.object_list.addObject(&rock);
    game.object_list.addObject(&rock2);
    game.object_list.addObject(&rock3);
    game.object_list.addObject(&chest1);
    game.object_list.addObject(&rock_benches);
    game.object_list.addObject(&rock_column1);
    game.object_list.addObject(&rock_column2);
    game.object_list.addObject(&rock_column3);
    game.object_list.addObject(&break_rock_col);
    game.object_list.addObject(&rock_well);
    game.object_list.addObject(&rock_bench);
    game.object_list.addObject(&rock_bench1);
    game.object_list.addObject(&flag);
    game.object_list.addObject(&rip);
    game.object_list.addObject(&rip1);
    game.object_list.addObject(&rip2);
    game.object_list.addObject(&tomb);
    game.object_list.addObject(&lamp);
    game.object_list.addObject(&jar);
    game.object_list.addObject(&jar2);

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
        rock_column3.render(3);
        rock_well.render(3);
        break_rock_col.render(3);
        rock_bench.render(3);
        rock_bench1.render(3);
        flag.render(3);
        rip.render(3);
        rip1.render(3);
        rip2.render(3);
        tomb.render(3);
        lamp.render(3);
        jar.render(3);
        jar2.render(3);
        

        game.draw();
    }
}