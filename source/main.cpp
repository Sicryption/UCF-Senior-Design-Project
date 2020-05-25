#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h>
#include <m3dia.hpp>
#include <png.h>
#include "lua/lua.hpp"

#include "util.hpp"
#include "ObjectManager.hpp"
#include "sandbox.h"
#include "resources.h"

using namespace m3d;


int main(int argc, char* argv[])
{
	//  Create default Applet and Screen variables
    Applet app;
    Screen scr;
	
	//  Create default Singleton instances of Utility class and ObjectManager class
	Util *util = Util::createInstance(&scr, &app);
	ObjectManager *om = ObjectManager::createInstance(&scr);
    ResourceManager::initialize();

    //  Create a Sandbox environment (done here for testing)
    LuaSandbox* sandbox = new LuaSandbox();

    //m3d::Sprite spr;
    //m3d::Texture* tex = ResourceManager::getTexture("error.bmp");    
    //spr.setTexture(*tex);

	// Main loop
    while (app.isRunning())
	{
		//  Call OnUpdate Function for all Singletons.
		util->OnUpdate();
		om->OnUpdate();

        //scr.drawTop(spr);
        
        //  Render the game screen
		scr.render();
	}
	
    sandbox->close();
	return 0;
}
