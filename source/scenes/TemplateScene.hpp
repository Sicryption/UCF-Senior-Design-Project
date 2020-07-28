#pragma once
#include "../gameManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"
#include "../scenes/scene.hpp"
#include "../scenes/MainMenuScene.hpp"
#include <array>

#ifdef DEBUG
#endif

class TemplateScene : public Minigame
{
	/**
		@brief A blank template for building a new minigame scene. 
	**/
	private:
		
	public:
		
		TemplateScene();
		~TemplateScene();
		void initialize();
		void draw();
		void load();
		void unload();
		void reset();
		void update();
		void SubmitTemplateCode(std::vector<CommandObject*> luaCode);
		void onEnter();
		void onExit();
		bool checkWinCond();
		void loadScene();
		void loadWinScr();
		void loadLoseScr();
		void requestUI();
		void closeGame();
};
