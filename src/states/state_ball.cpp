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

