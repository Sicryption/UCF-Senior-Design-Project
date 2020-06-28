#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <thread>
#include <chrono>

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
int consoleThreadState = 1;
std::stringstream con;
m3d::Thread* consoleThread;

void readConsole( m3d::Parameter param)
{
    std::string line;
    int* state = param.get<int*>();
    if(state == NULL)
        return;

    while(true){
        
        std::getline(con,line);
        if(line.size() > 0)
            Util::PrintLine(line);
        //Util::PrintLine("done");
        if(*state == 0){
            return;
        }
    }
}


int main(int argc, char* argv[])
{
	//  Create default Applet and Screen variables
    Applet app;
    Screen scr;
    std::streambuf* coutStreamBuffer = std::cout.rdbuf();
    std::streambuf* consoleStreamBuffer = con.rdbuf();
    std::cout.rdbuf(consoleStreamBuffer);
    //con.sync_with_stdio(true);
    std::cout.sync_with_stdio(true);
	consoleThread = new m3d::Thread(readConsole,&consoleThreadState);


    //  Create a Sandbox environment (done here for testing)
	LuaSandbox* sandbox = new LuaSandbox();

	//  Create default Singleton instances of Utility class and ObjectManager class
    GameManager::Initialize(&app, &scr);
	Util *util = Util::createInstance(&scr, &app);
	ObjectManager *om = ObjectManager::createInstance(&scr);
	MenuHandler *mh = MenuHandler::createInstance(&scr);
	ResourceManager::initialize();
    Input::initialize();
	SceneManager::OnInitialize();
    consoleThread->start();
    cout << "Yar Har\n";
    fprintf(stdout,"Fiddle di dee!\n");

    sandbox->executeString("print(\"Do what you want cus a pirate is free!\")");
    //sandbox->executeString("co = coroutine.create(function () print(\"hi\") end");
    //m3d::Thread::sleep(2000);

	// Main loop
	while (app.isRunning())
	{
        if( m3d::buttons::buttonDown(m3d::buttons::Start) && m3d::buttons::buttonPressed(m3d::buttons::Select) ||
            m3d::buttons::buttonDown(m3d::buttons::Select) && m3d::buttons::buttonPressed(m3d::buttons::Start))
        {
            app.exit();
            //break;
        }

		//  Call OnUpdate Function for all Singletons.
        GameManager::Update();
        //SceneManager::draw();
        Input::update();
		om->OnUpdate();
		mh->OnUpdate();
		SceneManager::OnUpdate();

		SceneManager::OnDraw();
		util->OnUpdate();

		scr.render();
	}
    consoleThreadState = 0;
    sandbox->close();
	delete (util);
	delete (mh);
	delete (om);

	return 0;
}
