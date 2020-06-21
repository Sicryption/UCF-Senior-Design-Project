#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h>
#include <m3dia.hpp>
#include <png.h>
#include "lua/lua.hpp"

#include "menus/MenuHandler.hpp"
#include "sandbox.h"
#include "managers/resources.h"
#include "managers/util.hpp"
#include "managers/ObjectManager.hpp"
#include "managers/gameManager.hpp"
#include "managers/sceneManager.hpp"
#include "managers/inputManager.hpp"
#include "gameObjects/testObject.cpp"
#include "scenes/startScene.cpp"

using namespace m3d;

int main(int argc, char* argv[])
{

    Applet *app = new Applet();
    Screen *scr = new Screen(false);
    
    
    

	m3d::Sprite spr;
    m3d::Texture * tex_ptr;
    std::string id = "gfx/error.png";

    //  Create a Sandbox environment (done here for testing)
	LuaSandbox* sandbox = new LuaSandbox();

	//  Create default Singleton instances of Utility class and ObjectManager class
    GameManager::Initialize(app, scr);
    SceneManager::initialize();
	Util *util = Util::createInstance(scr, app);
	ObjectManager *om = ObjectManager::createInstance(scr);
    ResourceManager::initialize();
    MenuHandler *mh = MenuHandler::createInstance(scr);
    Input::initialize();     

    ResourceManager::loadTexture(id);  
    sandbox->executeFile("sandbox_init.lua"); 
    
    tex_ptr = ResourceManager::getTexture(id);  

    spr.setTexture(*tex_ptr);
    spr.setXScale(10);
    spr.setYScale(10);  

  
	// Main loop
	while (app->isRunning())
	{
        
		//  Call OnUpdate Function for all Singletons.
        GameManager::Update();
        //SceneManager::draw();
        Input::update();
		util->OnUpdate();
		om->OnUpdate();
		mh->OnUpdate();

        sandbox->executeString("tick()");
        
      
		//scr->drawTop(spr); // draw the sprite 
    
        //  Render the game screen
		scr->render();
	}

    sandbox->close(); 

	delete (util);
	delete (om);
	delete (mh);
    
	return 0;
}
