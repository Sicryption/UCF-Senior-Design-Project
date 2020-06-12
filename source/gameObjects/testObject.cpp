#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

class TestObject : public GameObject
{

private:
    m3d::Texture *texture;
    m3d::Sprite *sprite;

public:
    TestObject()
    {
        x = 0;
        y = 0;
        xScale = 5;
        yScale = 5;
        angle = 0;
    }

    ~TestObject()
    {
        texture = NULL;
        delete(sprite);
    }

    void initialize() 
    {
        
        texture = ResourceManager::getTexture("gfx/error.png");
        sprite = new m3d::Sprite();
        sprite->setTexture(*texture);

        sprite->setScale(xScale,yScale);
    }

    void update() {

        //angle += 90 * GameManager::getDeltaTime();

        if(m3d::buttons::buttonDown(m3d::buttons::Right))
        {
            x -= 20 * GameManager::getDeltaTime();
        }
        if(m3d::buttons::buttonDown(m3d::buttons::Left))
        {
            x += 20 * GameManager::getDeltaTime();
        }
        if(m3d::buttons::buttonDown(m3d::buttons::Up))
        {
            y += 20 * GameManager::getDeltaTime();
        }
        if(m3d::buttons::buttonDown(m3d::buttons::Down))
        {
            y -= 20 * GameManager::getDeltaTime();
        }
    };
    
    void draw()
    {
        m3d::Screen * screen = GameManager::getScreen();
        double w = 20 * xScale;
        double h = 20 * yScale;
        m3d::BoundingBox box(x,y,w,h);
        m3d::BoundingBox ScreenBoundsTop(0,0,400,240);
        m3d::BoundingBox ScreenBoundsBottom(40,241,320,240);;
        
        //screen->drawTop(*sprite);
        m3d::Vector2f pos;

        if(ScreenBoundsTop.intersects(box))
        {
            pos.u = x - 0;
            pos.v = y - 0;
            sprite->setPosition(pos);
            
            screen->drawTop(*sprite);
        }
        
        //  GameManager::getScreenBounds(m3d::RenderContext::ScreenTarget::Bottom).intersects(box)
        if(ScreenBoundsBottom.intersects(box))
        {                       
            pos.u = x - 40;
            pos.v = y - 241;
            sprite->setPosition(pos); 
            
            screen->drawBottom(*sprite);
        }
        
    }

    void destroy(){ this->~TestObject(); }
    void moveTo(double x,double y){};
    void Rotate(double deg){};
};