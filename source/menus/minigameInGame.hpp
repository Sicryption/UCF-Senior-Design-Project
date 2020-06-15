#pragma once

#include "menu.hpp"

class MinigameInGame : public Menu
{
	private:

	public:
		MinigameInGame(m3d::Screen* screen);
		virtual ~MinigameInGame();

		void OnUpdate();
};