#pragma once
#include "scene.hpp"

#include "../gameManager.hpp"
#include "../inputManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"
#include "../Menu/MenuItems/ButtonMenuItem.hpp"

class MainMenuScene : public Scene
{
	private:
		RectangleMenuItem* whiteBackground;

		TextMenuItem* StartupText;
		ButtonMenuItem* ClickHereToContinue = nullptr;
		SpriteMenuItem* apple;

		SpriteMenuItem* grass;
		SpriteMenuItem* bGrass;
		

	public:
		MainMenuScene();
		~MainMenuScene();

		void initialize();
		void draw();
		void update();

		void load() {};
		void unload() {};
		void onEnter() {};
		void onExit() {};
};
