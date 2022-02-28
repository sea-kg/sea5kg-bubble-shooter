#pragma once

#include "SDL.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <algorithm>
#include <cmath>
#define PI 3.14159265
#include "state_game.h"

class RenderColor {
    public:
        RenderColor(int nR, int nG, int nB, int nA);
        void changeRenderColor(SDL_Renderer* renderer);

    private:
        int m_nR;
        int m_nG;
        int m_nB;
        int m_nA;
};

class RenderObject;

class IRenderWindow {
    public:
        virtual void addGameObject(RenderObject *pObject) = 0;
};

class RenderObject {

    public:
        RenderObject(int nPositionZ);
        virtual ~RenderObject();
        int getPositionZ();
        bool isDestroyed();
        void destroy();
        virtual void modify(const GameState& state, IRenderWindow* pRenderWindow);
        virtual bool canDraw(const GameState& state) = 0;
        virtual void draw(SDL_Renderer* pRenderer) = 0;
        int randomNoise();

    protected:
        bool m_bDestroyed;

    private:
        int m_nPositionZ;
};