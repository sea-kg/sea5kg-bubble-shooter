#pragma once

#include <vector>
#include <iostream>
#include "coordxy.h"

long getCurrentTimeInMilliseconds();

class GameState {

    public:
        GameState(int windowWidth, int windowHeight);
        void init();
        void updateElapsedTime();
        long getElapsedTime() const;
        const CoordXY &getCoordLeftTop() const;
        void setCoordLeftTop(const CoordXY &);

        bool isChangedWindowSize() const;
        int getWindowWidth() const;
        int getWindowHeight() const;
        // const YRect &getWindowRect() const;
        void updateWindowSize(int w, int h);

        void setMouseCaptured(bool bMouseCaptured);
        bool isMouseCaptured() const;
        
        void setPlayMusic(bool bPlayMusic);
        void togglePlayMusic();
        bool isPlayMusic() const;

        void setMinPoint(const CoordXY &p);
        const CoordXY &getMinPoint();
        void setMaxPoint(const CoordXY &p);
        const CoordXY &getMaxPoint();

    private:
        bool m_bMouseCaptured;
        bool m_bPlayMusic;
        long m_nElapsedTime;
        long m_nStartTime;
        CoordXY m_coordLeftTop;
        CoordXY m_maxPoint;
        CoordXY m_minPoint;
        
        bool m_bIsChangedWindowSize;
        int m_nWindowWidth;
        int m_nWindowHeight;
};