#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

class TerminalObject : public GameObject
{

private:
    m3dCI::Sprite *texture;
    m3dCI::Sprite *sprite;
    bool (*wall)[12][20];
    int counter;
    //pointer to maze array 

public:
    TerminalObject(bool (*walls)[12][20])
    {
        wall =  walls;
        x = 20;
        y = 20;
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
        if( (x + _x) < 0 || (y + _y) < 0 || (x + _x) >= 40 || (y + _y) >= 24)
            return;
        /*
        if((*wall)[(int)(x + _x)][(int)(y + _y)]==0)
        {
            x += (_x * 10);
	        y += (_y * 10);
        }*/
        if(_y == 0)
        {
            if(_x > 0)
            {
                _x += x;
                for(int i = x; i < (int)_x; i++)
                {
                    if((*wall)[i][y] == 1)
                        break;
                    x += 10;
                }
            }
            if(_x < 0)
            {
                _x += x;
                for(int i = x; i > (int)_x; i--)
                {
                    if((*wall)[i][y] == 1)
                        break;
                    x -= 10;
                }
            }
            
        }
        if(_x==0)
        {
            if(_y > 0)
            {
                _y += y;
                for(int i = y; i < (int)_y; i++)
                {
                    if((*wall)[x][i] == 1)
                        break;
                    y += 10;
                }
            }
            if(_y < 0)
            {
                _y += y;
                for(int i = y; i > (int)_y; i--)
                {
                    if((*wall)[x][i] == 1)
                        break;
                    y -= 10;
                }
            }
        }
        
    };
    void Rotate(double deg){};
};
