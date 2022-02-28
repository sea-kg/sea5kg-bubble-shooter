/*
    <kattMickisShooter>
    Bubble Shooter clone for kattMickis

    By: Erik Andersson
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "SDL.h"
#include "SDL_image.h"
#include <SDL_ttf.h>
#include "SDL_mixer.h"

#include "render_window.h"
#include "game.h"

extern "C" int main(int argc, char *argv[]) {
    // Seed random number generator
    srand(time(NULL));

    // Init SDL
    Uint32 init_flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO;
    // Uint32 screen_flags = SDL_HWSURFACE;

    if (SDL_Init(init_flags) < 0) {
        std::cout << "Error initializing SDL: " << SDL_GetError();
        return 1;
    }

    if (TTF_Init() < 0) {
        std::cout << "Error initializing TTF: " << TTF_GetError();
        return 2;
    }

    RenderWindow *pWindow = new RenderWindow("sea5kg-bubble-shooter", 1024, 1024);
    Game game = Game(pWindow);
    game.loop();

    return 0;
}
