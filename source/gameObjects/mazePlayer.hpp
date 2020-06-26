#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

class TerminalObject : public GameObject
{

private:
    m3dCI::Sprite *texture;
    m3dCI::Sprite *sprite;
    bool (*wall)[24][40];
    //pointer to maze array 

public:
    TerminalObject(bool (*walls)[24][40])
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
        screen->drawTop(*sprite);
    }

    void destroy(){ this->~TerminalObject(); }
    void moveTo(double _x,double _y)
    {
        if((*wall)[(int)x][(int)y]==0)
            {
               x = _x;
               y = _y; 
               sprite->setPosition(x,y);
            }
    };
    void Rotate(double deg){};
};
