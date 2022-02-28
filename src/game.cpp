#include <iostream>
#include <algorithm>

#include "SDL_mixer.h"
#include "SDL_image.h"

#include "game.h"

#include "render_ball.h"

Game::Game() {
    std::cout << "Game() called" << std::endl;
}

Game::Game(RenderWindow *pWindow) {
    m_bRunning = true;
    m_bIsPlaying = false;
    m_pTextureBall = nullptr;
    m_pWindow = pWindow;
    pWindow->getWindowSize(&m_nWindowWidth, &m_nWindowHeight);

    m_pTextureBall = m_pWindow->loadTexture("data/textures/ball.png");

    m_pGameState = new GameState(m_nWindowWidth, m_nWindowHeight);

    // init balls
    for (int i = 0; i < 500; i++) {
        StateBall *pStateBall = new StateBall();
        // pStateBall->setRadius(rand() % 15 + 5);
        pStateBall->setRadius(16);
        pStateBall->setXY(
            rand() % m_nWindowWidth,
            rand() % m_nWindowHeight / 2
        );
        m_vBalls.push_back(pStateBall);
        RenderBall *pBall = new RenderBall(1000, m_pTextureBall, pStateBall);
        pWindow->addGameObject(pBall);
    }

    // Init FPS capping
    m_nFps = 50;
    m_nLastTicks = 0;
}

void Game::loop() {
    while (m_bRunning) {
        m_pWindow->clear(97, 113, 115, 255);
        handleEvents();
        m_pWindow->modifyObjects(*m_pGameState);
        m_pWindow->drawObjects(*m_pGameState);
        updateStateBalls();
        cap();
    }
}

void Game::cap() {
    Uint32 curr_ticks = SDL_GetTicks();
    int time_passed = curr_ticks - m_nLastTicks;
    int delay = 0;

    if (m_nFps > 0) {
        delay = (1000 / m_nFps) - time_passed;
        if (delay > 0) {
            SDL_Delay(delay);
            time_passed += delay;
        }
    }

    m_nLastTicks = curr_ticks;

    if (delay > 0) {
        time_passed -= delay;
    }
}

void Game::handleEvents() {
    while (SDL_PollEvent(&m_event)) {
        // Handle the sprites' events
        if (m_event.type == SDL_QUIT) {
            m_bRunning = false;
            break;
        }
        if (m_event.type == SDL_MOUSEMOTION) {
            // std::cout << "SDL_MOUSEMOTION" << std::endl;
            // TODO
            // mouse move
            // event.motion.x, event.motion.y
        } else if (m_event.type == SDL_MOUSEBUTTONDOWN) {
            std::cout << "TODO: SDL_MOUSEBUTTONDOWN" << std::endl;
            // TODO
            // mouse down == onclick
            // event.motion.x, event.motion.y
        }
    }
}

void Game::updateStateBalls() {
    std::vector<float> newCoordX;
    std::vector<float> newCoordY;
    float nStrongAttraction = 8000.0 * m_vBalls.size();
    for (int x = 0; x < m_vBalls.size(); x++) {
        float nX1 = m_vBalls[x]->getX();
        float nY1 = m_vBalls[x]->getY();
        float nRadius1 = m_vBalls[x]->getRadius();

        float new_x = 0.0;
        float new_y = 0.0;
        for (int y = 0; y < m_vBalls.size(); y++) {
            if (y == x) {
                continue;
            }
            float nRadius2 = m_vBalls[y]->getRadius();
            float dx = m_vBalls[y]->getX() - nX1;
            float dy = m_vBalls[y]->getY() - nY1;
            float nDist = std::sqrt(dx*dx + dy*dy);
            float nAngel = std::asin(dx / nDist);
            float nR2 = (nRadius2 + nRadius1) + 5.0;

            if (nDist < 1.0) {
                float nAngel2 = float(rand() % 600 - 300) / 100.0;
                // new_x -= nR2 / 2.0 * std::cos(nAngel2);
                // new_y -= nR2 / 2.0 * std::sin(nAngel2);
                new_x -= nRadius1 / 2.0 * std::cos(nAngel2);
                new_y -= nRadius1 / 2.0 * std::sin(nAngel2);
            } else if (nDist <= nR2) {
                new_x -= dx / 100.0;
                new_y -= dy / 100.0;
            } else if (nDist > nR2) {
                new_x += dx / nStrongAttraction;
                new_y += dy / nStrongAttraction;
            }
        }

        // attration to top
        new_y -= nY1 / nStrongAttraction;
        // attration to left
        new_x += nX1 / nStrongAttraction;
        // attration to width
        new_x -= (m_nWindowWidth - nX1) / nStrongAttraction;

        new_x = nX1 + new_x;
        new_y = nY1 + new_y;

        if (new_x < nRadius1) {
            new_x = nRadius1;
        }
        if (new_x > m_nWindowWidth - (nRadius1*2)) {
            new_x = m_nWindowWidth - (nRadius1*2);
        }
        if (new_y < 0.0) {
            new_y = 0.0;
        }
        newCoordX.push_back(new_x);
        newCoordY.push_back(new_y);
    }
    // std::cout
    //     << "  newCoords[x].x() = " << newCoords[0].x()
    //     << "  newCoords[x].y() = " << newCoords[0].y()
    //     << "  m_nWidthWindow = " << m_nWidthWindow
    //     << std::endl;
    for (int x = 0; x < m_vBalls.size(); x++) {
        m_vBalls[x]->setXY(
            newCoordX[x],
            newCoordY[x]
        );
    }
    
}