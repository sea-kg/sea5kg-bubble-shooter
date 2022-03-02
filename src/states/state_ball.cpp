#include "state_ball.h"
#include <SDL.h>
#include <chrono>

// ---------------------------------------------------------------------
// StateBall

StateBall::StateBall() {
    m_nX = 120;
    m_nY = 120;
    m_nRadius = 12;
    m_bTargetMove = false;
    m_nTargetVectorX = 0.0;
    m_nTargetVectorY = 0.0;
    m_bDestroy = false;
    setColor(RenderBallColor::Random);
}

float StateBall::getX() {
    return m_nX;
}

float StateBall::getY() {
    return m_nY;
}

void StateBall::setXY(float nX, float nY) {
    m_nX = nX;
    m_nY = nY;
}

int StateBall::getRadius() const {
    return m_nRadius;
}

void StateBall::setRadius(int nRadius) {
    m_nRadius = nRadius;
}

void StateBall::setTargetVector(float nX, float nY) {
    m_nTargetVectorX = nX;
    m_nTargetVectorY = nY;
    m_bTargetMove = true;
}

void StateBall::resetTargetMove() {
    m_bTargetMove = false;
}

bool StateBall::isTargetMove() {
    return m_bTargetMove;
}

float StateBall::getTargetVectorX() {
    return m_nTargetVectorX;
}

float StateBall::getTargetVectorY() {
    return m_nTargetVectorY;
}

RenderBallColor StateBall::getColor() {
    return m_nColor;
}

void StateBall::setColor(RenderBallColor nColor) {
    m_nColor = nColor;
    if (m_nColor == RenderBallColor::Random) {
        int random = rand() % 6;
        m_nColor = (RenderBallColor)random;
    }
}

void StateBall::destroy() {
    m_bDestroy = true;
}

bool StateBall::isDestroy() {
    return m_bDestroy;
}