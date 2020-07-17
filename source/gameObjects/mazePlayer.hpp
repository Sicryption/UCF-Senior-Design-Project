#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"
#include "../util.hpp"
#include <sstream>

#define DEBUG

#define mazeCellWidth 20
#define mazeCellHeight 20

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
        x = mazeCellWidth;
        y = mazeCellHeight;
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
        int i;
        int xc = (x/mazeCellWidth);
        int yc = (y/mazeCellHeight);
         /*

        
        if( (x + _x) < 0 || (y + _y) < 0 || (x + _x) >= 40 || (y + _y) >= 24)
            return;
        
        if((*wall)[(int)(x + _x)][(int)(y + _y)]==0)
        {
            x += (_x * 10);
	        y += (_y * 10);
        }*/
        //if( (xc + _x) < 0 || (yc + _y) < 0 || (xc + _x) >= 20 || (yc + _y) >= 12)
            //return;
        if(_y == 0)
        {
            if(_x > 0)
            {
                _x += xc;
                for( i = xc; i < (int)_x; i++)
                {
                    if((*wall)[yc][i + 1] == 1)
                    {
                        break;
                    }
                        
                    x = x + mazeCellWidth;
                }
            }
            if(_x < 0)
            {
                _x += xc;
                for(i = xc; i > (int)_x; i--)
                {
                    if((*wall)[yc][i - 1] == 1)
                        break;
                    x -= mazeCellWidth;
                }
            }
            
        }
        if(_x==0)
        {
            if(_y > 0)
            {
                _y += yc;
                for(i = yc; i < (int)_y; i++)
                {
                    if((*wall)[i+1][xc] == 1)
                        break;
                    y += mazeCellHeight;
                }
            }
            if(_y < 0)
            {
                _y += yc;
                for( i = yc; i > (int)_y; i--)
                {
                    if((*wall)[i - 1][xc] == 1)
                        break;
                    y -= mazeCellHeight;
                }
            }
        }
    /*
        #ifdef DEBUG
			std::stringstream coordinates;
			coordinates << "x =" << x ;
			Util::PrintLine(coordinates.str());
		#endif*/
        
    };
    void Rotate(double deg){};
    int winCond() 
	{
		if((x/mazeCellWidth) == 18 && (y/ mazeCellHeight) == 9)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	BoundingBox getAABB()
	{
		return sprite->getBoundingBox();
	}
};
