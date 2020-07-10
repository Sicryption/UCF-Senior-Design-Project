#pragma once
#include "scene.hpp"

#include "../ObjectManager.hpp"
#include "../gameManager.hpp"
#include "../inputManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"
#include "../Menu/MenuItems/ButtonMenuItem.hpp"

class MainMenuScene : public Scene
{
	private:
		m3d::Rectangle* whiteBackground;

		m3dCI::Text* StartupText;
		ButtonMenuItem* ClickHereToContinue = nullptr;
		m3dCI::Sprite* apple;

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
