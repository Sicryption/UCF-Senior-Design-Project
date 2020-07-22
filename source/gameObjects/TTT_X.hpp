/**
 *  @file TTT_Token.hpp
 *  @brief Defines the Tic-Tac_toe Naughts Object
 */
#include "../gameObjects/gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

/**
 *  @class TTT_X "gameObjects/circle.hpp"
 *  @brief
 *  
 */
class TTT_Token : public GameObject
{

private:

    m3dCI::Sprite* m_sprite;

public:
    /**
     *  @brief Constructor of the Circle object
     * 
     *  @param t_x,t_y position of the object
     *  @param t_radius radius of the circle
     *  @param t_angle angle of the circle
     *  @param t_color color of the circle
     */
    TTT_Token(bool t_cross = true, double t_x = 0, double t_y = 0 , 
                  double t_radius = DEFAULT_SIZE, double t_angle = 0,
                  m3d::Color t_color = DEFAULT_COLOR)
    {
        // TODO custom positioning 
        x = t_x;
        y = t_y;
        xScale = t_radius;
        yScale = t_radius;
        angle = t_angle;
        m_color = t_color;
        m_sprite = new m3dCI::Sprite(ResourceManager::getSprite( (t_cross) ? "TTT_X.png":"TTT_O.png" ));
    }

    ~TTT_Token()
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

        screen->drawTop(*m_sprite);
    
    }

    void destroy()
    { 
        this->~TTT_Piece(); 
    }
    
    void moveTo(double t_x,double t_y)
    {
        x = t_x;
        y = t_y;
    }

    void Rotate(double deg){};
};
