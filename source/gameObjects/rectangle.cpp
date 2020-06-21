#include "objects/rectangle.hpp"

void RectangleObject::initialize()
{

}
    
void RectangleObject::update()
{
    shape->setPosition(x,y);
    shape->setWidth(yScale);
    shape->setHeight(yScale);
}

void RectangleObject::draw()
{
    GameManager::getScreen()->drawTop(*shape);
}

void RectangleObject::destroy()
{
    this->~RectangleObject();
}
void RectangleObject::moveTo(double x,double y)
{

}
void RectangleObject::Rotate(double deg)
{

}