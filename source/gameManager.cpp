#include "gameManager.hpp"

GameManager* GameManager::instance = NULL;
m3d::Applet* GameManager::applet = NULL;
m3d::Screen* GameManager::screen = NULL;

m3d::BoundingBox* GameManager::ScreenBoundsTop = NULL;
m3d::BoundingBox* GameManager::ScreenBoundsBottom = NULL;



void GameManager::Initialize()
{
    if(instance == NULL)
    {
        instance = new GameManager();
    }
    
    ScreenBoundsTop = new m3d::BoundingBox(0,0,400,240);
    ScreenBoundsBottom = new m3d::BoundingBox(40,241,320,240);;
}

void GameManager::Update()
{
    instance->lastTime = instance->curTime;
    instance->curTime = time(0);
    instance->deltaTime = difftime(instance->lastTime, instance->curTime);

    if (buttonDown(m3d::buttons::Button::Start) && buttonDown(m3d::buttons::Button::Select))
    {
        applet->exit();
    }
	
}

m3d::Vector2f GameManager::getScreenOrigin(m3d::RenderContext::ScreenTarget target)
{
    m3d::Vector2f origin;
    if(target == m3d::RenderContext::ScreenTarget::Bottom)
    {
        origin.u = 40;
        origin.v = 240;
    }else
    {
        origin.u = 0;
        origin.v = 0;
    }
    
    return origin;
}

m3d::BoundingBox GameManager::getScreenBounds(m3d::RenderContext::ScreenTarget target)
{
   
    if(target == m3d::RenderContext::ScreenTarget::Bottom)
    {
         m3d::BoundingBox box(40,250,320,240);         
         return box;
    }else
    {
         m3d::BoundingBox box(0,0,400,240);
         return box;
    }
}
