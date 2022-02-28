#include "state_game.h"
#include <SDL.h>
#include <chrono>

long getCurrentTimeInMilliseconds() {
    long nTimeStart = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return nTimeStart;
}

// ---------------------------------------------------------------------
// GameState

GameState::GameState(int windowWidth, int windowHeight) {
    m_nStartTime = 0;
    m_nElapsedTime = 0;
    m_nWindowWidth = windowWidth;
    m_nWindowHeight = windowHeight;
    // m_windowRect = YRect(YPos(0, 0), YPos(windowWidth, windowHeight));
    m_bIsChangedWindowSize = true;
    m_bPlayMusic = false;
}

void GameState::init() {
    m_nStartTime = getCurrentTimeInMilliseconds();
}

void GameState::updateElapsedTime() {
    m_nElapsedTime = getCurrentTimeInMilliseconds() - m_nStartTime;
}

long GameState::getElapsedTime() const {
    return m_nElapsedTime;
}

const CoordXY &GameState::getCoordLeftTop() const {
    return m_coordLeftTop;
}

void GameState::setCoordLeftTop(const CoordXY &newCoordLeftTop) {
    m_coordLeftTop = newCoordLeftTop;
}

bool GameState::isChangedWindowSize() const {
    return m_bIsChangedWindowSize;
}

int GameState::getWindowWidth() const {
    return m_nWindowWidth;
}

int GameState::getWindowHeight() const {
    return m_nWindowHeight;
}

// const YRect &GameState::getWindowRect() const {
//     return m_windowRect;
// }

void GameState::updateWindowSize(int w, int h) {
    m_bIsChangedWindowSize = true;
    m_nWindowWidth = w;
    m_nWindowHeight = h;
    // m_windowRect = YRect(YPos(0, 0), YPos(w, h));
}

// TODO move to MainController
void GameState::setMouseCaptured(bool bMouseCaptured) {
    m_bMouseCaptured = bMouseCaptured;
    SDL_SetRelativeMouseMode(m_bMouseCaptured ? SDL_TRUE : SDL_FALSE);
}

bool GameState::isMouseCaptured() const {
    return m_bMouseCaptured;
}

void GameState::setPlayMusic(bool bPlayMusic) {
    m_bPlayMusic = bPlayMusic;
}

void GameState::togglePlayMusic() {
    m_bPlayMusic = !m_bPlayMusic;
}

bool GameState::isPlayMusic() const {
    return m_bPlayMusic;
}

void GameState::setMinPoint(const CoordXY &p) {
    m_minPoint = p;
}

const CoordXY &GameState::getMinPoint() {
    return m_minPoint;
}

void GameState::setMaxPoint(const CoordXY &p) {
    m_maxPoint = p;
}

const CoordXY &GameState::getMaxPoint() {
    return m_maxPoint;
}