#include "../gameObject.hpp"
#include "../gameManager.hpp"

class Circle : public GameObject
{

private:
    m3d::Color *color;
    m3d::Circle *cir;

public:
    Circle(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    void initialize() {
        color = new m3d::Color(0,100,0);
        cir = new m3d::Circle((int)x,(int)y,50,*color);
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
        screen->drawTop(*cir);
    }

    void moveTo(double _x, double _y) {
        cir->setYPosition(y + (int)(_y + 0.5));
    }

};
