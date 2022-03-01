#pragma once

#include <vector>
#include <iostream>
#include "coordxy.h"

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

    private:
        
        float m_nX;
        float m_nY;

        bool m_bTargetMove;
        float m_nTargetVectorX;
        float m_nTargetVectorY;
        int m_nRadius;
};