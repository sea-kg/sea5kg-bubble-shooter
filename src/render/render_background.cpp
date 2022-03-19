
#include "render_background.h"

// ---------------------------------------------------------------------
// RenderBackground


RenderBackground::RenderBackground(int nPositionZ, SDL_Texture *pTexture) : RenderObject(nPositionZ) {
    m_rectSrcBall.x = 0;
    m_rectSrcBall.y = 0;
    m_rectSrcBall.w = 1024;
    m_rectSrcBall.h = 1024;
    m_rectDstBall = m_rectSrcBall;
    m_pTexture = pTexture;
}

RenderBackground::~RenderBackground() {
    // nothing
}

void RenderBackground::modify(const GameState& state, IRenderWindow* pRenderWindow) {
}

bool RenderBackground::canDraw(const GameState& state) {
    return true;
}

void RenderBackground::draw(SDL_Renderer* pRenderer) {
    SDL_RenderCopy(pRenderer, m_pTexture, &m_rectSrcBall, &m_rectDstBall);
}
