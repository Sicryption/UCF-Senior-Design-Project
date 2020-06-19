#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h>
#include <m3dia.hpp>
#include <png.h>
#include "lua/lua.hpp"

#include "util.hpp"
#include "ObjectManager.hpp"
#include "MenuHandler.hpp"
#include "sandbox.h"
#include "resources.h"
#include "gameManager.hpp"
#include "sceneManager.hpp"
#include "gameObjects/testObject.cpp"
#include "scenes/startScene.cpp"
#include "inputManager.hpp"

using namespace m3d;

int main(int argc, char* argv[])
{
	//  Create default Applet and Screen variables
    Applet *app = new Applet();
    Screen *scr = new Screen(false);
    GameManager::Initialize(app, scr);

    //  Create a Sandbox environment (done here for testing)
	LuaSandbox* sandbox = new LuaSandbox();

	//  Create default Singleton instances of Utility class and ObjectManager class
	Util *util = Util::createInstance(&scr, &app);
	ObjectManager *om = ObjectManager::createInstance(&scr);
	MenuHandler *mh = MenuHandler::createInstance(&scr);
	ResourceManager::initialize();
	
    //  Create a Sandbox environment (done here for testing)
	LuaSandbox* sandbox = new LuaSandbox();
  
	Util *util = Util::createInstance(scr, app);
	ObjectManager *om = ObjectManager::createInstance(scr);
    ResourceManager::initialize();
    MenuHandler *mh = MenuHandler::createInstance(scr);
    Input::initialize();     

    ResourceManager::loadTexture(id);  
    ResourceManager::loadFile("lua/init_scene.lua"); 
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
		
        if(Input::isTouchDragging())
        {
            Vector2f dragDist = Input::getTouchDragVector();

            if(m3d::buttons::buttonDown(m3d::buttons::Touch))
                Util::PrintLine( "frame ("+ std::to_string(app->getCurrentFrame()) + 
                                ")drag -  x: " + std::to_string(dragDist.u) + 
                                        " y: " + std::to_string(dragDist.v) );
        }
    
        //  Render the game screen
		scr->render();
	}

    sandbox->close();

	delete (util);
	delete (mh);
	delete (om);
	return 0;
}
