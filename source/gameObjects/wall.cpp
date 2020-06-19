#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"

class TerminalObject : public GameObject
{

private:
    m3d::Texture *texture;
    m3d::Sprite *sprite;

public:
    TerminalObject()
    {
        x = 10;
        y = 0;
        xScale = 1;
        yScale = 1;
        angle = 0;
    }

    ~TerminalObject()
    {
        texture = NULL;
        //delete(sprite);
    }

    void initialize()
    {

        texture = ResourceManager::loadTexture("gfx/Terminal.png");
        sprite = new m3d::Sprite();
        sprite->setTexture(*texture);
        //sprite->setSpriteSheet("gfx/Terminal.png",1);
        //sprite->setCenter(10,10);
        sprite->setScale(xScale,yScale);
        sprite->setPosition(x,y);
    }

    void update() {

        if(m3d::buttons::buttonPressed(m3d::buttons::Right))
        {
            x += 10;
        }
        if(m3d::buttons::buttonPressed(m3d::buttons::Left))
        {
            x -= 10;
        }
        if(m3d::buttons::buttonPressed(m3d::buttons::Up))
        {
            y -= 10;
            if(y<0)
            {
              y=0;
            }
        }
        if(m3d::buttons::buttonPressed(m3d::buttons::Down))
        {
            y += 10;
            if(y>230)
            {
              y=230;
            }

        }/*
        if(m3d::buttons::buttonDown(m3d::buttons::Right))
        {
            x += 1 * GameManager::getDeltaTime();
        }
        if(m3d::buttons::buttonDown(m3d::buttons::Left))
        {
            x -= 1 * GameManager::getDeltaTime();
        }
        if(m3d::buttons::buttonDown(m3d::buttons::Up))
        {
            y -= 1 * GameManager::getDeltaTime();
        }
        if(m3d::buttons::buttonDown(m3d::buttons::Down))
        {
            y += 1 * GameManager::getDeltaTime();
        }*/
        sprite->setPosition(x,y);

    };

    void draw()
    {
        m3d::Screen * screen = GameManager::getScreen();

        //sprite->setPosition(x,y);
        screen->drawTop(*sprite);

    }

    void destroy(){ this->~TerminalObject(); }
    void moveTo(double x,double y){};
    void Rotate(double deg){};
};



/*#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"
#include <list>
#include <iterator>

class WallObject : public GameObject
{

private:
    m3d::Texture *texture;
    m3d::Sprite *sprite;
    m3d::Color *colorWall;
    std::list <m3d::Rectangle*> *walls;
    std::list <m3d::BoundingBox*> *wallsb;
    //std::map<unsigned int, GameObject*> m_hashmap;
    m3d::Rectangle *wall1, *wall2, *wall3, *wall4, *wall5, *wall6, *wall7, *wall8,
                   *wall9, *wall10, *wall11, *wall12, *wall13, *wall14, *wall15, *wall16,
                   *wall17, *wall18, *wall19, *wall20, *wall21, *wall22, *wall23, *wall24,
                   *wall25, *wall26, *wall27, *wall28, *wall29, *wall30, *wall31, *wall32;
    m3d::BoundingBox *wall1b, *wall2b, *wall3b, *wall4b, *wall5b, *wall6b, *wall7b, *wall8b,
                   *wall9b, *wall10b, *wall11b, *wall12b, *wall13b, *wall14b, *wall15b, *wall16b,
                   *wall17b, *wall18b, *wall19b, *wall20b, *wall21b, *wall22b, *wall23b, *wall24b,
                   *wall25b, *wall26b, *wall27b, *wall28b, *wall29b, *wall30b, *wall31b, *wall32b;
    m3d::BoundingBox temp;

public:
    WallObject()
    {
    };

    ~WallObject()
    {
        texture = NULL;
        //delete(sprite);
    };

    void initialize()
    {
        colorWall = new m3d::Color(150,150,150);
        walls = new std::list<m3d::Rectangle*> ;
        wallsb = new std::list<m3d::BoundingBox*> ;

        wall1 = new m3d::Rectangle(33,0,367,3, *colorWall);
        temp = wall1->getBoundingBox();
        wall1b = &temp;
        wallsb->push_back(wall1b);
        walls->push_back(wall1);
        wall2 = new m3d::Rectangle(0,0,3,240, *colorWall);
        wall2b = wall2->getBoundingBox();
        wallsb->push_back(wall2b);
        walls->push_back(wall2);
        wall3 = new m3d::Rectangle(0,237,367,3, *colorWall);
        wall3b = wall3->getBoundingBox();
        wallsb->push_back(wall3b);
        walls->push_back(wall3);
        wall4 = new m3d::Rectangle(397,0,3,240, *colorWall);
        wall3b = wall3->getBoundingBox();
        wallsb->push_back(wall3b);
        walls->push_back(wall4);
        wall5 = new m3d::Rectangle(0,60,75,3, *colorWall);
        wall5b = wall5->getBoundingBox();
        wallsb->push_back(wall5b);
        walls->push_back(wall5);
        wall6 = new m3d::Rectangle(75,60,3,75, *colorWall);
        wall6b = wall6->getBoundingBox();
        wallsb->push_back(wall6b);
        walls->push_back(wall6);
        wall7 = new m3d::Rectangle(75,135,100,3, *colorWall);
        wall7b = wall7->getBoundingBox();
        wallsb->push_back(wall7b);
        walls->push_back(wall7);
        wall8 = new m3d::Rectangle(175,45,3,93, *colorWall);
        wall8b = wall8->getBoundingBox();
        wallsb->push_back(wall8b);
        walls->push_back(wall8);
        wall9 = new m3d::Rectangle(175,45,40,3, *colorWall);
        wall9b = wall9->getBoundingBox();
        wallsb->push_back(wall9b);
        walls->push_back(wall9);
        wall10 = new m3d::Rectangle(215,45,3,50, *colorWall);
        wall10b = wall10->getBoundingBox();
        wallsb->push_back(wall10b);
        walls->push_back(wall10);
        wall11 = new m3d::Rectangle(215,95,43,3, *colorWall);
        wall11b = wall11->getBoundingBox();
        wallsb->push_back(wall11b);
        walls->push_back(wall11);
        wall12 = new m3d::Rectangle(255,45,3,53, *colorWall);
        wall12b = wall12->getBoundingBox();
        wallsb->push_back(wall12b);
        walls->push_back(wall12);
        wall13 = new m3d::Rectangle(258,45,90,3, *colorWall);
        wall13b = wall13->getBoundingBox();
        wallsb->push_back(wall13b);
        walls->push_back(wall13);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);
        wall = new m3d::Rectangle(x,y,xpos,ypos, *colorWall);

        walls.push_back(g)
    };

    void update() {

    };

    void draw()
    {
        m3d::Screen * screen = GameManager::getScreen();
        m3d::Rectangle *printer;
        std::list<m3d::Rectangle*>::iterator i;
        for(i = walls->begin();i != walls->end();i++)
        {
          printer = *i;
          screen->drawTop(*printer);
          screen->drawTop(*wall2);
          screen->drawTop(*wall3);
          screen->drawTop(*wall4);
        };

    };

    void destroy(){ this->~WallObject(); };
    void moveTo(double x,double y){};
    void Rotate(double deg){};
};*/
