/*#include "MainFunction.h"
#include "ImageObject.h"
#include "FrameSheet.h"
#include "MainObject.h"
#include "GameMap.h"
#include "BaseObject.h"
#include "MainAcces.h"*/
#include "Game.h"

void initSDL();
void quitSDL();

int main(int argc, char* argv[])
{
    Window window;
    window.creatWindow("Doraemon", 1000, 600);
    loadAcces();

    mainGame();
    

    /*GameMap map1, map2, map1s;
    GameMap::loadTile("acces/ground_tile/");
    GameMap::loadTileColision();

    map1.loadMap("acces/map1_layer1.txt");
    map1.setCameraPosition(0, 0, window.getWindowWidth(), window.getWindowHeight());
    map2.loadMap("acces/map1_layer2.txt");
    map1s.loadMap("acces/map1_layer1s.txt");

    BaseObject rock;
    rock.loadAnimationFromFile("acces/rock3.png");
    rock.setAnimation(1, 1, 52, 104);

    rock.setPosition(30, 100);
    
    const int FPS = 30;
    const int time_delay = 1000 / FPS;
    MainObject player;
    
    bool quit = false;
    SDL_Event window_event;
    while (!quit)
    {
        int start_time = SDL_GetTicks();
        window.clearWindow();

        if (SDL_WaitEventTimeout(&window_event, 1) != 0)
        {
            if (window_event.type == SDL_QUIT) quit = true;
            if (window_event.type == SDL_KEYDOWN || window_event.type == SDL_KEYUP)
                player.handleInputAction(window_event);
            
        }
        player.doThing(map2);
        //player.doThing(map2);
        map1.cameraMove(0, 0);
        map1s.cameraMove(0, 0);
        map1.drawMap();
        map1s.drawMap();
        map2.drawMap();

        rock.show();
        player.show();


        int current_time = SDL_GetTicks() - start_time;
        window.display();
        if (time_delay > current_time)
        {
            window.delayWindow(time_delay - current_time);
        }
    }*/

	return 0;
}

void initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) std::cout << "SDL_Init failed" << std::endl;
    else std::cout << "\nSDL_Init succes";
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void quitSDL() {
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}