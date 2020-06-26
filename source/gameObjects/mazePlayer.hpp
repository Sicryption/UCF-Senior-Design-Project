#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

class TerminalObject : public GameObject
{

private:
    m3dCI::Sprite *texture;
    m3dCI::Sprite *sprite;
    bool* wall;
    //pointer to maze array 

public:
    TerminalObject(bool* walls)
    {
        wall =  walls;
        x = 10;
        y = 0;
        xScale = 1;
        yScale = 1;
        angle = 0;
    }

    ~TerminalObject()
    {
        texture = NULL;
    }

    void initialize()
    {
        sprite = new m3dCI::Sprite(*(ResourceManager::getSprite("terminal.png")));
        sprite->setScale(xScale,yScale);
        sprite->setPosition(x,y);
    }

    void update() {
        
    };

    void draw()
    {
        m3d::Screen * screen = GameManager::getScreen();

		sprite->setPosition(x, y);
        screen->drawTop(*sprite);
    }

    void destroy(){ this->~TerminalObject(); }
    void moveTo(double _x,double _y)
    {
        /*if(*(wall[(int)x]+(int)y)==0)
            {
               x = _x;
               y = _y; 
            }*/

		x += _x;
		y += _y;
    };
    void Rotate(double deg){};
};
