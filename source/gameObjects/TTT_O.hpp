/**
 *  @file TTT_O.hpp
 *  @brief Defines the Tic-Tac_toe Naughts Object
 */
#include "../gameObjects/gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

/**
 *  @class TTT_O "gameObjects/circle.hpp"
 *  @brief
 *  
 */
class TTT_O : public GameObject
{

private:

    m3d::Circle* circle;
    m3d::Color color;

    double radius;

public:
    /**
     *  @brief Constructor of the Circle object
     * 
     *  @param t_x,t_y position of the object
     *  @param t_radius radius of the circle
     *  @param t_angle angle of the circle
     *  @param t_color color of the circle
     */
    TTT_O( double t_x = 0, double t_y = 0 , 
                  double t_radius = DEFAULT_SIZE, double t_angle = 0,
                  m3d::Color t_color = DEFAULT_COLOR)
    {
        x = t_x;
        y = t_y;
        xScale = t_radius;
        yScale = t_radius;
        angle = t_angle;
        circle = new m3d::Circle(x,y,xScale,color);
    }

    ~TTT_O()
    {
        
    }

    void initialize()
    {
        updateShape();
    }

    void update() {}

    void updateShape()
    {
        circle->setPosition(x,y);
        circle->setRadius(xScale);        
        circle->setColor(color);        
    }

    void draw()
    {
        updateShape();
        m3d::Screen * screen = GameManager::getScreen();

        screen->drawTop(*circle);
    
    }

    void destroy()
    { 
        this->~CircleObject(); 
    }
    
    void moveTo(double t_x,double t_y)
    {
        x = t_x;
        y = t_y;
    }

    void Rotate(double deg){};
};
