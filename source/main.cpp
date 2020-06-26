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
#include "gameObjects/wall.cpp"
#include "scenes/startScene.cpp"
#include "scenes/MazeScene.hpp"
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

    m3dCI::Sprite* spr = ResourceManager::loadSpritesheet("gfx/commands").at(0);
    //spr->scale(-0.5,-0.5);
    
    uint8_t r = 255,b=128,g =0;
	m3d::Color color(r,g,b);

    std::vector<CommandObject*> commands =
    {
		new UserCommand("x = 1"),
        new UserCommand("y = 1"),
		new WhileCommand("x < 10"),
			new WhileCommand("y < 10"),
				new UserCommand("println(x*y)"),
				new UserCommand("y = y + 1"),
			new EndCommand(),
			new UserCommand("y = 1"),
			new UserCommand("x = x + 1"),
        new EndCommand()
    };

    std::string lua = "\n" + CommandObject::ConvertBulk(commands);
    //Util::Print(lua);
    sandbox->executeString(lua);

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

        r = (r+1) % 256;
        g = (g+1) % 256;
        b = (b+1) % 256;
        
        

        //spr->setTint(m3d::Color(r,g,b,255));

        
        
        
        //  Render the game screen
        //scr->drawTop(*spr);
        
        
		scr->render();
	}

    sandbox->close();

	delete (util);
	delete (mh);
	delete (om);
	return 0;
}
