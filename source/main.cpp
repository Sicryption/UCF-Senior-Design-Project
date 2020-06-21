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
#include "managers/gameManager.hpp"
#include "managers/sceneManager.hpp"
#include "gameObjects/testObject.cpp"
#include "scenes/startScene.cpp"
#include "inputManager.hpp"

using namespace m3d;

int main(int argc, char* argv[])
{
	//  Create default Applet and Screen variables
    Applet *app = new Applet();
    Screen *scr = new Screen(false);
	
    //  Create a Sandbox environment (done here for testing)
	LuaSandbox* sandbox = new LuaSandbox();

	//  Create default Singleton instances of Utility class and ObjectManager class
    GameManager::Initialize(app, scr);
    SceneManager::initialize();
	Util *util = Util::createInstance(scr, app);
	ObjectManager *om = ObjectManager::createInstance(scr);
	MenuHandler *mh = MenuHandler::createInstance(scr);
	ResourceManager::initialize();
    Input::initialize();
	
    sandbox->executeFile("sandbox_init.lua"); 
    
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
		
        //  Render the game screen
		scr->render();
	}

    sandbox->close(); 

	delete (util);
	delete (mh);
	delete (om);
	return 0;
}
