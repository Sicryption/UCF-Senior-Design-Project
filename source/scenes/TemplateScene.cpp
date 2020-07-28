#include "TemplateScene.hpp"
#include "MinigameSelectScene.hpp"

#include "../sandbox.hpp"

#define t(x) AddCommand(x)
#define func(a) [&]() { t(a); }
#define PAIR(name, command) { name, [&]() { t(command); }}
#define NULLPartialPAIR(name) { name, nullptr }
#define NULLPAIR PAIR("", nullptr)
#define COLORPAIR(name, r, g, b) PAIR(name, new ColorCommand(name, m3d::Color(r,g,b,255)))


TemplateScene::TemplateScene()
{
	/**
		RECOMMENDED CODING PRACTICES

		SPRITES:
		- use sprites for backgrounds by adding the file to gfx/assets
		- add the filename to a configured .t3s file 
		- load the .t3s file in the resource manager's initialize() in resources.cpp 
		- load the filename in initialize() via the resource's manager getSprite() 
		
		STATES: 
		- use game states regulate what occurs during different stages within in the game (e.g. tutorial, win, lose, etc.)
		- implement game states as an enum and have a switch statement transition between states

		GENERAL:
		- display game objects using sorting layers to the screen via screen's drawTop()
		- create game objects to represent different drawable elements of the game (e.g. ball, paddle, etc.) 
		- assign buttons that the user can press to begin entering code, restart the game or return to the main menu
		- display the tutorial as sequential popup windows the user can traverse through with a button press 
		- convert the user's code to a string that can be run on the sandbox's queue in SubmitTemplateCode()
	**/
}

TemplateScene::~TemplateScene() {};


void TemplateScene::load(){ Minigame::load(); };

void TemplateScene::initialize() { Minigame::initialize(); };

void TemplateScene::unload(){ Minigame::unload(); };

void TemplateScene::reset() {};


void TemplateScene::update() {};




void TemplateScene::SubmitTemplateCode(std::vector<CommandObject*> luaCode) {};

void TemplateScene::onEnter(){ Minigame::onEnter(); };
void TemplateScene::onExit() { Minigame::onExit(); };
bool TemplateScene::checkWinCond()
{
	
			
};
void TemplateScene::loadScene() { Minigame::loadScene(); };
void TemplateScene::loadWinScr() { Minigame::loadWinScr(); };
void TemplateScene::loadLoseScr() { Minigame::loadLoseScr(); };
void TemplateScene::requestUI() { Minigame::requestUI(); };
void TemplateScene::closeGame() { Minigame::closeGame(); };