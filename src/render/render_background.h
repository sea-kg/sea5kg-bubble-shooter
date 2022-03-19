#pragma once

#include "render_object.h"

class RenderBackground : public RenderObject {

    public:
        RenderBackground(int nPositionZ, SDL_Texture *pTexture);
        virtual ~RenderBackground();
        virtual void modify(const GameState& state, IRenderWindow* pRenderWindow) override;
        virtual bool canDraw(const GameState& state) override;
        virtual void draw(SDL_Renderer* pRenderer) override;

    private:
        SDL_Texture *m_pTexture;

        SDL_Rect m_rectSrcBall;
        SDL_Rect m_rectDstBall;
};