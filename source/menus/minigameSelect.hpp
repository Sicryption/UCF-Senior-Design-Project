#pragma once

#include "menu.hpp"

#define MinigameCount 6
#define Rows 2
#define Columns 3

class MinigameSelect : public Menu
{
	private:

		m3d::Rectangle* whiteBackground;

		m3dCI::Text* MinigameSelectTopText;
		m3dCI::Button* minigameOptions[MinigameCount];
	public:
		MinigameSelect(m3d::Screen* screen);
		virtual ~MinigameSelect();
		
		void OnUpdate();
};