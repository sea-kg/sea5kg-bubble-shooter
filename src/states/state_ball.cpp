#include "state_ball.h"
#include <SDL.h>
#include <chrono>

// ---------------------------------------------------------------------
// StateBall

StateBall::StateBall() {
    m_nX = 120;
    m_nY = 120;
    m_nRadius = 12;
}

float StateBall::getX() {
    return m_nX;
}

float StateBall::getY() {
    return m_nY;
}

void StateBall::setXY(float x, float y) {
    m_nX = x;
    m_nY = y;
}

int StateBall::getRadius() const {
    return m_nRadius;
}

void StateBall::setRadius(int nRadius) {
    m_nRadius = nRadius;
}