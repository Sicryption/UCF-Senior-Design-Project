#pragma once
#include "../gameManager.hpp"
#include "../sceneManager.hpp"
#include "../MenuHandler.hpp"
#include "../scene.hpp"
#include "../resources.h"
#include "../sandbox.h"
#include "../minigame.hpp"
#include "../gameObjects/mazePlayer.hpp"

class MazeScene : public Minigame
{
	private:
		m3dCI::Sprite *wallpaper;
		m3dCI::Sprite *texture;
		m3d::Rectangle *winScreen;
        m3d::Rectangle *loseScreen;
		m3d::Color *colorRec;
		m3d::Color *colorText;
		m3d::Text *prompt;
		LuaSandbox *box;
        TerminalObject *runner;
        int x;
		int y;
        bool walls[24][40] ={ { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1}};
            //2d array acting as map of array
        bool (*wallHolder)[40] = walls;

		enum MazeState
		{
			TutorialMessage,
			Requesting,
			Execute,
			Win,
			Lose
		};
		MazeState currentState;
	public:
		MazeScene()
		{
            //array traversers
            x = 1.0;
			y = 0.0;
		}
		void initialize(){
            box = new LuaSandbox();
            //box->executeFile("lua/init_scene.lua");
        //loads and gets maze texture
            ResourceManager::loadSpritesheet("gfx/mazeSprites");
			//texture = new m3dCI::Sprite(*(ResourceManager::getSprite("wall.png")));
            //sprite* spr = new m3d::Sprite();
       //initialize playable character
            runner = new TerminalObject(*wallHolder);
            runner->initialize();
			//addObject(runner);
       //Load text and bottom screen background color
			colorRec = new m3d::Color(150,150,150);
			colorText = new m3d::Color(0,0,0);
       //initializes text and bottom screen background
			winScreen = new m3d::Rectangle(0,0,320,240,*colorRec);
			prompt = new m3d::Text("Maze",*colorText);
			prompt->setPosition(160,120);
			wallpaper = new m3dCI::Sprite(*(ResourceManager::getSprite("maze.png")));
		    //wallpaper->setTexture(*texture);
		    wallpaper->setCenter(0,0);
		    wallpaper->setScale(10,10);

			currentState = MazeState::TutorialMessage;
		}
		void draw(){
			m3d::Screen * screen = GameManager::getScreen();

		    wallpaper->setPosition(0,0);
			//screen->drawBottom(*bwallpaper);
			//screen->drawBottom(*prompt);

            screen->drawTop(*wallpaper);
            runner->draw();

		}
        void load(){}; //any data files
        void unload(){};
        void update(){

			switch (currentState)
			{
				case MazeState::TutorialMessage:
					if (buttons::buttonDown(buttons::Start))
					{
						currentState = MazeState::Requesting;

						std::vector<CommandObject*> startingCommands =
						{
							new RightCommand("1")
						};

						MenuHandler::RequestUserCode(startingCommands, [&](std::vector<CommandObject*> commands) { SubmitMazeCode(commands); });
					}
					break;
				case MazeState::Execute:
					break;
			}
        };

		void SubmitMazeCode(std::vector<CommandObject*> luaCode)
		{
			//box->executeString(luaCode);
			currentState = MazeState::Execute;
		}

        void onEnter(){};
        void onExit(){};
        bool checkWinCond(){return true;};
        void loadScene(){};
        void loadWinScr(){};
        void loadLoseScr(){};
        void requestUI(){};
        void closeGame(){};
};
