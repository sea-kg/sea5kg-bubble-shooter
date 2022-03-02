#pragma once

#include "render_window.h"
#include "render_ball.h"

#include <queue>

const int GAME_FPS = 50;
const int PAUSE_FPS = 50;

class BallsGrid;
class Arrow;
class Sprite;
class Background;
class Points;
class Menu;
class Music;

class Game {
    public:
        Game();
        Game(RenderWindow *pWindow);

        // Getters

        void cap();

        // Game
        void loop();
        void handleEvents();

    private:

        SDL_Texture *m_pTextureBall;

        // SDL_Surface *_screen;
        // SDL_Surface *_buffer;
        SDL_Event m_event;

        TTF_Font *_font;

        int m_nFps;
        Uint32 m_nLastTicks;

        std::vector<RenderBall*> m_vRenderBalls;
        std::vector<RenderBall*> m_vRenderPlayerBalls;

        // This flag indicates whether the everything needs to be redrawn
        bool m_bRunning;

        bool m_bIsPlaying;

        RenderWindow *m_pWindow;
        GameState *m_pGameState;
        int m_nWindowWidth;
        int m_nWindowHeight;

        void updateStateBalls();

        void appendPlayerBells();
        void resetLatestBall();
};
