#pragma once

#include <vector>
#include <iostream>
#include "coordxy.h"

class StateBall {

    public:
        StateBall();
        float getX();
        float getY();
        void setXY(float x, float y);
        int getRadius() const;
        void setRadius(int nRadius);

    private:
        float m_nX;
        float m_nY;
        int m_nRadius;
};