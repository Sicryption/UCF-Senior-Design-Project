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
	Util *util = Util::createInstance(scr, app);
	ObjectManager *om = ObjectManager::createInstance(scr);
	MenuHandler *mh = MenuHandler::createInstance(scr);
	ResourceManager::initialize();
    Input::initialize();
	
    ResourceManager::loadSpritesheet("gfx/menuSprites");

    m3dCI::Sprite* test1= ResourceManager::getSprite("tab1.png");
    m3dCI::Sprite* test2= ResourceManager::getSprite("tab2.png");
    m3dCI::Sprite* test3= ResourceManager::getSprite("tab3.png");
    m3dCI::Sprite* test4= ResourceManager::getSprite("tab4.png");
    m3dCI::Sprite* test5= ResourceManager::getSprite("tab5.png");

    test1->setXPosition(48*0);
    test2->setXPosition(48*1);
    test3->setXPosition(48*2);
    test4->setXPosition(48*3);
    test5->setXPosition(48*4);
	
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


        scr->drawTop(*test1);
        scr->drawTop(*test2);
        scr->drawTop(*test3);
        scr->drawTop(*test4);
        scr->drawTop(*test5);

        //  Render the game screen
		scr->render();
	}

    sandbox->close();

	delete (util);
	delete (mh);
	delete (om);
	return 0;
}
