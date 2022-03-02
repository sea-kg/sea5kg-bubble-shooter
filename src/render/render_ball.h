#pragma once

#include "render_object.h"
#include "state_ball.h"

class RenderBall : public RenderObject {

    public:
        RenderBall(int nPositionZ, SDL_Texture *pTexture, StateBall *pStateBall);
        virtual ~RenderBall();
        virtual void modify(const GameState& state, IRenderWindow* pRenderWindow) override;
        virtual bool canDraw(const GameState& state) override;
        virtual void draw(SDL_Renderer* pRenderer) override;

        StateBall *getState();

    private:
        int m_nBallWidth;
        int m_nBallHeight;
        int m_nHalf;
        SDL_Texture *m_pTexture;
        StateBall *m_pStateBall;

        SDL_Rect m_rectSrcBall;
        SDL_Rect m_rectDstBall;
};