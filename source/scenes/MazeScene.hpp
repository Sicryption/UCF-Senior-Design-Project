#pragma once
#include "../gameManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"
#include "../gameObjects/mazePlayer.hpp"
#include "../scenes/scene.hpp"
#include "../scenes/MainMenuScene.hpp"

#ifdef DEBUG
#define DEBUG_MAZE
#endif


class MazeScene : public Minigame
{
	private:
		SpriteMenuItem *wallpaper, *texture, *popup, *wPopup;
		SpriteMenuItem *tutorial[5];
		int tutCount;
		RectangleMenuItem *winScreen, *loseScreen;
		m3d::Color *colorRec, *colorText;
		TextMenuItem *prompt, *winPrompt;
        TerminalObject *runner;
		int x, y, runnerID;
        bool walls[12][20] ={{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
							{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
							{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
							{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
							{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
							{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
							{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
							{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
							{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
							{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
							{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
							{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};


			
            //2d array acting as map of array
        bool (*wallHolder)[12][20] = &walls;
		//wallHolder = &walls;

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
		MazeScene();
		~MazeScene();

		void initialize();

		void draw();
		
		void load();
        
		void unload();
        
		void update();

		void SubmitMazeCode(std::vector<CommandObject*> luaCode);

		void onEnter();
		void onExit();
		bool checkWinCond();
		void loadScene();
		void loadWinScr();
		void loadLoseScr();
		void requestUI();
		void closeGame();
};
