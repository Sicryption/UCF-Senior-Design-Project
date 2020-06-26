#pragma once

#include "menu.hpp"
#include "../sceneManager.hpp"
#include "MinigameDescriptor.hpp"

#define MINIGAME_COUNT 6

class MinigameSelect : public Menu
{
	private:
		//std::vector<MinigameDescriptor
		MinigameDescriptor minigames[MINIGAME_COUNT] =
		{
			MinigameDescriptor("Maze", "Navigate through this ezpz", "mazeSmall.png", "mazeLarge.png")
		};
		
		m3d::Rectangle* whiteBackground;

		m3dCI::Text* MinigameSelectTopText;
		m3dCI::Button* minigameOptions[MINIGAME_COUNT];
	public:
		MinigameSelect(m3d::Screen* screen);
		virtual ~MinigameSelect();
		
		void OnUpdate();
};