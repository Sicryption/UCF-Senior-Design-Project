#pragma once
#include <m3dia.hpp>
#include <3ds.h>

#include "managers/gameManager.hpp"
#include "objects/gameObject.hpp"

class RectangleObject : public GameObject
{
private:
    m3d::Rectangle* shape;

    ~RectangleObject()
    {
        
    }
public:
    RectangleObject()
    {
        x = 0;
        y = 0;
        xScale = 20;
        yScale = 20;

        shape = new m3d::Rectangle(x, y, xScale, yScale, DEFAULT_OBJECT_COLOR);
    }

    void initialize();
    void update();

    void draw();
    void destroy();
    void moveTo(double x,double y);
    void Rotate(double deg);

};