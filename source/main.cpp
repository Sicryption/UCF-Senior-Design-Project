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

void onClick(m3dCI::Button* b)
{
	b->setXPosition(b->getXPosition() + 1);
}

int main(int argc, char* argv[])
{
	//Create default Applet and Screen variables
    Applet app;
    Screen scr;
	
	//Create default Singleton instances of Utility class and ObjectManager class
	Util *util = Util::getInstance(&scr, &app);
	ObjectManager *om = ObjectManager::getInstance(&scr);
		
	m3dCI::Button* rect = om->CreateButton(50,50,100,10,m3d::Color(10,50,100));
	rect->OnHeld = onClick;
	
	m3dCI::Button* circle = om->CreateButton(0,0,20,m3d::Color(50,0,100));
	circle->OnHeld = onClick;
		
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
