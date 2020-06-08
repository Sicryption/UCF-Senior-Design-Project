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
#include "inputManager.hpp"

using namespace m3d;


int main(int argc, char* argv[])
{
	//  Create default Applet and Screen variables
    Applet app;
    Screen scr;
	m3d::Sprite spr;
    m3d::Texture * tex_ptr = new m3d::Texture();

	//  Create default Singleton instances of Utility class and ObjectManager class
	Util *util = Util::createInstance(&scr, &app);
	ObjectManager *om = ObjectManager::createInstance(&scr);
    ResourceManager::initialize();
    Input::initialize();     
    
    std::string id = "error";
    ResourceManager::loadTexture(tex_ptr,id, "error.png");    

    m3d::Texture * tex2 = ResourceManager::getTexture(id);

    spr.setTexture(*tex2);
    spr.setXScale(1);
    spr.setYScale(1);

    //  Create a Sandbox environment (done here for testing)
    LuaSandbox* sandbox = new LuaSandbox();

	// Main loop
    while (app.isRunning())
	{
		//  Call OnUpdate Function for all Singletons.
		util->OnUpdate();
		om->OnUpdate();

        Vector2f* pos = Input::touch();
        if(pos->u >= 0)
        {
            spr.setPosition(pos->u - (0.5f * spr.getXScale() * tex2->getWidth()), pos->v - (0.5f * spr.getYScale() * tex2->getHeight()));
        }

        scr.drawBottom(spr); // draw the sprite 

        //  Render the game screen
		scr.render();
	}
	
    sandbox->close();
	return 0;
}
