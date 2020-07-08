#pragma once
#include "scene.hpp"

#include "../ObjectManager.hpp"
#include "../gameManager.hpp"
#include "../inputManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"

class MainMenuScene : public Scene
{
	private:
		m3d::Rectangle* whiteBackground;

		m3dCI::Text* StartupText;
		m3dCI::Button* ClickHereToContinue;
		m3dCI::Sprite* apple;

	public:
		MainMenuScene();

		void initialize();
		void draw();
		void onExit();

		void load() {};
		void unload() {};
		void update() {};
		void onEnter() {};
};
