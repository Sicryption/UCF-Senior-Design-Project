#include "util.hpp"
#include "ObjectManager.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>

#include <m3dia.hpp>

#include "lua/lua.hpp"

#include "sandbox.h"

using namespace m3d;


int main(int argc, char* argv[])
{
	//Create default Applet and Screen variables
    Applet app;
    Screen scr;
	
	//Create default Singleton instances of Utility class and ObjectManager class
	Util *util = Util::createInstance(&scr, &app);
	ObjectManager *om = ObjectManager::createInstance(&scr);
	
    // Create a Sandbox environment (here for testing)
    LuaSandbox* sandbox = new LuaSandbox();
    

	// Main loop
    while (app.isRunning())
	{
		//Call OnUpdate Function for all Singletons.
		util->OnUpdate();
		om->OnUpdate();
	
		//Render the game screen
		scr.render();
	}
	
	return 0;
}
