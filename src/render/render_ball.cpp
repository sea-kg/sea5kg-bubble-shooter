
#include "render_ball.h"

// ---------------------------------------------------------------------
// RenderBall


RenderBall::RenderBall(int nPositionZ, SDL_Texture *pTexture, StateBall *pStateBall) : RenderObject(nPositionZ) {
    m_nBallWidth = pStateBall->getRadius() * 2;
    m_nBallHeight = pStateBall->getRadius() * 2;
    m_rectSrcBall.x = 0;
    m_rectSrcBall.y = 0;
    m_rectSrcBall.w = 100;
    m_rectSrcBall.h = 100;
    m_rectDstBall = m_rectSrcBall;
    m_rectDstBall.w = m_nBallWidth;
    m_rectDstBall.h = m_nBallWidth;
    m_pStateBall = pStateBall;
    m_nHalf = m_nBallWidth / 2 - m_rectDstBall.w / 2;

    m_pTexture = pTexture;
    m_color = RenderBallColor::Random;
    if (m_color == RenderBallColor::Random) {
        int random = rand() % 6;
        m_color = (RenderBallColor)random;
        // std::cout << "color > " << (int)color  << std::endl;
    }
    m_rectSrcBall.x = 100 * (int)m_color;
}

RenderBall::~RenderBall() {
    // nothing
}

void RenderBall::modify(const GameState& state, IRenderWindow* pRenderWindow) {
    
    m_nBallWidth = m_pStateBall->getRadius() * 2;
    m_nBallHeight = m_pStateBall->getRadius() * 2;
    m_nHalf = m_nBallWidth / 2 - m_rectDstBall.w / 2;

    m_rectDstBall.x = m_pStateBall->getX() - m_nHalf;
    m_rectDstBall.y = m_pStateBall->getY() - m_nHalf;
}

bool RenderBall::canDraw(const GameState& state) {
    return true;
}

void RenderBall::draw(SDL_Renderer* pRenderer) {
    SDL_RenderCopy(pRenderer, m_pTexture, &m_rectSrcBall, &m_rectDstBall);
}
