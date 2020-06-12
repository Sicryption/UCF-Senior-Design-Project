#pragma once
#include "time.h"

#include <3ds.h>
#include <m3dia.hpp>

#include "scene.hpp"


class GameManager
{
private:
    static GameManager * instance;
    
    static m3d::Applet *applet;
    static m3d::Screen *screen;

    time_t lastTime;
    time_t curTime;
    double deltaTime;

    GameManager()
    {
        applet = new m3d::Applet();
        screen = new m3d::Screen();
        lastTime = curTime = time(NULL);
        deltaTime = 0;
    }

    ~GameManager()
    {
        
    }

public:
    static m3d::BoundingBox* ScreenBoundsTop;
    static m3d::BoundingBox* ScreenBoundsBottom;

    static void Initialize();
    static void Update();
    static double getDeltaTime()
    {
        return instance->deltaTime;
    }

    static m3d::Vector2f getScreenOrigin(m3d::RenderContext::ScreenTarget );
    static m3d::BoundingBox getScreenBounds(m3d::RenderContext::ScreenTarget);

    static m3d::Applet* getApplet(){return applet;}
    static m3d::Screen* getScreen(){return screen;}

    

};