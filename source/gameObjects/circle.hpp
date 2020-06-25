#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

class CircleObject : public GameObject
{

private:

    m3d::Circle circle;
    m3d::Color color;

    double radius;

public:
    CircleObject( double t_x = 0, double t_y = 0 , 
                  double t_radius = DEFAULT_SIZE, double t_angle = 0,
                  m3d::Color t_color = DEFAULT_COLOR)
    {
        x = t_x;
        y = t_y;
        xScale = t_radius;
        yScale = t_radius;
        angle = t_angle;
    }

    ~CircleObject()
    {
        
    }

    void updateShape()
    {
        circle.setPosition(x,y);
        circle.setHeight(radius);
        circle.setWidth(radius);
        
        circle.setColor(color);        
    }

    void initialize()
    {
        updateShape();
    }

    void update() {


    }

    void updateShape()
    {
        circle.setPosition(x,y);
        circle.setRadius(xScale);        
        circle.setColor(color);        
    }

    void draw()
    {
        updateShape();
        m3d::Screen * screen = GameManager::getScreen();

        screen->drawTop(circle);
    
    }

    void destroy()
    { 
        this->~TestObject(); 
    }
    
    void moveTo(double t_x,double t_y)
    {
        x = t_x;
        y = t_y;
    }

    void Rotate(double deg){};
};
