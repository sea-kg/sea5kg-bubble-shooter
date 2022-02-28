#pragma once

#include "render_object.h"
#include "state_ball.h"

enum class RenderBallColor {
    Random = -1,
    Red = 0,
    Green = 1,
    Yellow = 2,
    Blue = 3,
    Teal = 4,
    Purple = 5
};

class RenderBall : public RenderObject {

    public:
        RenderBall(int nPositionZ, SDL_Texture *pTexture, StateBall *pStateBall);
        virtual ~RenderBall();
        virtual void modify(const GameState& state, IRenderWindow* pRenderWindow) override;
        virtual bool canDraw(const GameState& state) override;
        virtual void draw(SDL_Renderer* pRenderer) override;

    private:
        int m_nBallWidth;
        int m_nBallHeight;
        int m_nHalf;
        SDL_Texture *m_pTexture;
        StateBall *m_pStateBall;

        RenderBallColor m_color;
        SDL_Rect m_rectSrcBall;
        SDL_Rect m_rectDstBall;
};