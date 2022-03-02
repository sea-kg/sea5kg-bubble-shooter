#pragma once

#include <vector>
#include <iostream>
#include "coordxy.h"

enum class RenderBallColor {
    Random = -1,
    Red = 0,
    Green = 1,
    Yellow = 2,
    Blue = 3,
    Teal = 4,
    Purple = 5
};

class StateBall {

    public:
        StateBall();
        float getX();
        float getY();
        void setXY(float nX, float nY);
        int getRadius() const;
        void setRadius(int nRadius);

        void setTargetVector(float nX, float nY);
        void resetTargetMove();
        bool isTargetMove();
        float getTargetVectorX();
        float getTargetVectorY();
        
        RenderBallColor getColor();
        void setColor(RenderBallColor nColor);
        void destroy();
        bool isDestroy();

    private:
        
        float m_nX;
        float m_nY;

        bool m_bTargetMove;
        float m_nTargetVectorX;
        float m_nTargetVectorY;
        int m_nRadius;
        RenderBallColor m_nColor;
        bool m_bDestroy;
};