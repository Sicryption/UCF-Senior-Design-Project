#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

class TextObject : public GameObject
{

private:

    m3dCI::Text* textObj;
    m3d::Color color;
    std::string text;

public:
    TextObject( double t_x = 0, double t_y = 0 , 
                     std::string t_text = "Hello", double t_angle = 0,
                     m3d::Color t_color = m3d::Color(0,0,0))
    {
        x = t_x;
        y = t_y;
        xScale = 1;
        yScale = 1;
        angle = t_angle;
        color = t_color;
        textObj = new m3dCI::Text("", m3d::Color(0,0,0));
    }

    ~TextObject()
    {
        textObj->~Text();
    }

    void updateShape()
    {
        textObj->setPosition(x,y);
        textObj->setFontSize(yScale);
        textObj->setFontWeight(xScale);
        textObj->setText(text);
        textObj->setColor(color);             
    }

    void initialize()
    {
        updateShape();
    }

    void update() {


    }

    void draw()
    {
        updateShape();
        m3d::Screen * screen = GameManager::getScreen();

        screen->drawTop(*textObj);
    
    }

    void destroy()
    { 
        this->~TextObject(); 
    }
    
    void moveTo(double t_x,double t_y)
    {
        x = t_x;
        y = t_y;
    }

    void Rotate(double deg){};
};
