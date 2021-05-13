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
    rock.loadShadow("acces/rock3_shadow.png");

    BaseObject rock2;
    rock2.loadAnimationFromFile("acces/rock2.png");
    rock2.setAnimation(1, 1, 52, 132);
    rock2.setColisionBox(0, 100, 52, 32);
    rock2.setPosition(198, -4);
    rock2.loadShadow("acces/rock2_shadow.png");

    BaseObject rock3;
    rock3.loadAnimationFromFile("acces/rock1.png");
    rock3.setAnimation(1, 1, 52, 76);
    rock3.setColisionBox(0, 46, 52, 30);
    rock3.setPosition(198, 245);
    rock3.loadShadow("acces/rock1_shadow.png");

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
    rock_benches.loadShadow("acces/gheda2_shadow.png");

    BaseObject rock_column1;
    rock_column1.loadAnimationFromFile("acces/rock_column.png");
    rock_column1.setAnimation(1, 1, 64, 154);
    rock_column1.setColisionBox(0, 100, 64, 54);
    rock_column1.setPosition(1060, 62);
    rock_column1.loadShadow("acces/rock_column_shadow.png");

    BaseObject rock_column2;
    rock_column2.loadAnimationFromFile("acces/rock_column.png");
    rock_column2.setAnimation(1, 1, 64, 154);
    rock_column2.setColisionBox(0, 100, 64, 54);
    rock_column2.setPosition(1060, 326);
    rock_column2.loadShadow("acces/rock_column_shadow.png");

    BaseObject rock_column3;
    rock_column3.loadAnimationFromFile("acces/rock_column.png");
    rock_column3.setAnimation(1, 1, 64, 154);
    rock_column3.setColisionBox(0, 100, 64, 54);
    rock_column3.setPosition(521, 326);
    rock_column3.loadShadow("acces/rock_column_shadow.png");

    BaseObject rock_well;
    rock_well.loadAnimationFromFile("acces/break_rock_well.png");
    rock_well.setAnimation(1, 1, 110, 98);
    rock_well.setColisionBox(0, 0, 110, 98);
    rock_well.setPosition(-23, 286);
    rock_well.loadShadow("acces/break_rock_well_shadow.png");

    BaseObject break_rock_col;
    break_rock_col.loadAnimationFromFile("acces/break_rock_column.png");
    break_rock_col.setAnimation(1, 1, 64, 114);
    break_rock_col.setColisionBox(0, 60, 64, 54);
    break_rock_col.setPosition(717, 366);
    break_rock_col.loadShadow("acces/break_rock_column_shadow.png");

    BaseObject rock_bench;
    rock_bench.loadAnimationFromFile("acces/gheda1.png");
    rock_bench.setAnimation(1, 1, 112, 82);
    rock_bench.setColisionBox(0, 38, 112, 44);
    rock_bench.setPosition(264, 587);
    rock_bench.loadShadow("acces/gheda1_shadow.png");

    BaseObject rock_bench1;
    rock_bench1.loadAnimationFromFile("acces/gheda1.png");
    rock_bench1.setAnimation(1, 1, 112, 82);
    rock_bench1.setColisionBox(0, 38, 112, 44);
    rock_bench1.setPosition(456, 587);
    rock_bench1.loadShadow("acces/gheda1_shadow.png");

    BaseObject flag;
    flag.loadAnimationFromFile("acces/notice_board_left.png");
    flag.setAnimation(1, 1, 54, 64);
    flag.setColisionBox(24, 58, 12, 6);
    flag.setPosition(405, 699);
    flag.loadShadow("acces/notice_board_left_shadow.png");

    BaseObject rip;
    rip.loadAnimationFromFile("acces/rip1.png");
    rip.setAnimation(1, 1, 52, 80);
    rip.setColisionBox(8, 46, 36, 34);
    rip.setPosition(774, 794);
    rip.loadShadow("acces/rip1_shadow.png");

    BaseObject rip1;
    rip1.loadAnimationFromFile("acces/rip.png");
    rip1.setAnimation(1, 1, 60, 82);
    rip1.setColisionBox(0, 48, 60, 34);
    rip1.setPosition(834, 742);
    rip1.loadShadow("acces/rip_shadow.png");

    BaseObject rip2;
    rip2.loadAnimationFromFile("acces/headstone.png");
    rip2.setAnimation(1, 1, 60, 58);
    rip2.setColisionBox(0, 18, 60, 40);
    rip2.setPosition(962, 824);
    rip2.loadShadow("acces/headstone_shadow.png");

    BaseObject tomb;
    tomb.loadAnimationFromFile("acces/tom_ver.png");
    tomb.setAnimation(1, 1, 64, 114);
    tomb.setColisionBox(0, 22, 64, 92);
    tomb.setPosition(1184, 480);
    tomb.loadShadow("acces/tom_ver_shadow.png");

    BaseObject lamp;
    lamp.loadAnimationFromFile("acces/rock_lamp.png");
    lamp.setAnimation(1, 1, 44, 76);
    lamp.setColisionBox(0, 42, 44, 32);
    lamp.setPosition(1215, 688);
    lamp.loadShadow("acces/rock_lamp_shadow.png");

    BaseObject jar;
    jar.loadAnimationFromFile("acces/jar.png");
    jar.setAnimation(1, 1, 42, 68);
    jar.setColisionBox(0, 52, 42, 16);
    jar.setPosition(982, 537);
    jar.loadShadow("acces/jar_shadow.png");

    BaseObject jar2;
    jar2.loadAnimationFromFile("acces/jar2.png");
    jar2.setAnimation(1, 1, 50, 54);
    jar2.setColisionBox(0, 30, 50, 24);
    jar2.setPosition(1056, 608);
    jar2.loadShadow("acces/jar2_shadow.png");

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