#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

class TriangleObject : public GameObject
{

private:

    m3d::Triangle triangle;
    m3d::Color color;

    double radius;

public:
    TriangleObject( double t_x = 0, double t_y = 0 , 
                  double t_length = DEFAULT_SIZE, double t_angle = 0,
                  m3d::Color t_color = DEFAULT_COLOR)
    {
        x = t_x;
        y = t_y;
        xScale = t_length;
        yScale = t_length;
        angle = t_angle;
    }

    ~TriangleObject()
    {
        
    }

    void updateShape()
    {
        triangle.setPosition(x,y);
        
        triangle.setColor(color);        
    }

    void initialize()
    {
        updateShape();
    }

    void update() {


    }

    // TODO: Untested
    void updateShape()
    {   
        double theta = 90 + angle;

        triangle.setX1Pos( x + x_scale * cos(theta) );
        triangle.setY1Pos( y + y_scale * sin(theta) );

        theta = (theta + 120) % 360;
        triangle.setX2Pos( x + x_scale * cos(theta) );
        triangle.setY2Pos( y + y_scale * sin(theta) );
        
        theta = (theta + 120) % 360;
        triangle.setX3Pos( x + x_scale * cos(theta) );
        triangle.setY3Pos( y + y_scale * sin(theta) );

        triangle.setColor(color);        
    }

    void draw()
    {
        updateShape();
        m3d::Screen * screen = GameManager::getScreen();

        screen->drawTop(triangle);
    
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
