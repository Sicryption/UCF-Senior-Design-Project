#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h>
#include <m3dia.hpp>
#include "util.hpp"
#include "ObjectManager.hpp"
#include "m3diaLibCI/button.hpp"

using namespace m3d;

/*
    The Lua API is built in C.
    In a C++ program it has to be included like this.
*/
extern "C"
{
    #include "lua/lua.h"
    #include "lua/lualib.h"
    #include "lua/lauxlib.h"
}


//Dummy function for Dummy Button
void doSomething(m3dCI::Button* buttonClicked)
{
	ObjectManager *om = ObjectManager::getInstance(nullptr);
		
	om->CreateButton(100,100,20,20,m3d::Color(200,0,0),nullptr);
}

int main(int argc, char* argv[])
{
	//Create default Applet and Screen variables
    Applet app;
    Screen scr;
	
	//Create default Singleton instances of Utility class and ObjectManager class
	Util *util = Util::getInstance(&scr, &app);
	ObjectManager *om = ObjectManager::getInstance(&scr);
	
	//Create Dummy button for testing OnClick
	om->CreateButton(50,50,20,20,m3d::Color(100,0,0),doSomething);
		
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
