#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h>
#include <m3dia.hpp>
#include <vector>
#include "lua/lua.hpp"

#include "util.hpp"
#include "ObjectManager.hpp"
#include "MenuHandler.hpp"
#include "sandbox.h"
#include "resources.h"
#include "gameManager.hpp"
#include "sceneManager.hpp"
#include "inputManager.hpp"
#include "commands/commands.h"


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
	Util *util = Util::createInstance(scr, app);
	ObjectManager *om = ObjectManager::createInstance(scr);
	MenuHandler *mh = MenuHandler::createInstance(scr);
	ResourceManager::initialize();
    Input::initialize();
	SceneManager::OnInitialize();

    ResourceManager::loadSpritesheet("gfx/commands").at(0);

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
		SceneManager::OnUpdate();

		SceneManager::OnDraw();
        
		scr->render();
	}

    sandbox->close();

	delete (util);
	delete (mh);
	delete (om);
	return 0;
}
