#include "Game.h"

void initSDL();
void quitSDL();

int main(int argc, char* argv[])
{
    Window window;
    window.creatWindow("Doraemon", 1280, 720);
    loadAcces();
    mainGame();

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