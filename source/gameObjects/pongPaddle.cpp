#include "../gameObject.hpp"
#include "../gameManager.hpp"

class PongPaddle : public GameObject
{

private:
    m3d::Color *color;
    m3d::Rectangle *PongRec;

public:
    PongPaddle(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    void initialize() {
        color = new m3d::Color(0,100,0);
        PongRec = new m3d::Rectangle((int)x,(int)y,50,10,*color);
    }

    void update() {


    }

    void draw() {
        m3d::Screen *screen = GameManager::getScreen();
        screen->drawTop(*PongRec);
    }


};