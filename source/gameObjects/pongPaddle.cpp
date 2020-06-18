#include "../gameObject.hpp"
#include "../gameManager.hpp"

class PongPaddle : public GameObject
{

private:
    m3d::Color *color;
    m3d::Rectangle *PongRec;
    m3d::BoundingBox *paddleBox;

public:
    PongPaddle(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    void initialize() {
        color = new m3d::Color(0,100,0);
        PongRec = new m3d::Rectangle((int)x,(int)y,50,10,*color);
        paddlebox = PongRec->getBoundingBox();
    }

    void update() {

        if(m3d::buttons::buttonDown(m3d::buttons::Button::Down)) {
            moveTo(x, 1 * GameManager::getDeltaTime());
        }

        if(m3d::buttons::buttonDown(m3d::buttons::Button::Up)) {
            moveTo(x, -1 * GameManager::getDeltaTime());
        }

    }

    void draw() {
        m3d::Screen *screen = GameManager::getScreen();
        screen->drawTop(*PongRec);
    }

    void moveTo(double _x, double _y) {
        PongRec->setYPosition(y + (int)(_y + 0.5));
    }
    


};