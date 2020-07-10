#pragma once

#include "scene.hpp"
#include "MinigameDescriptor.hpp"
#include "MazeScene.hpp"

#include "../gameManager.hpp"
#include "../inputManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"

#define MINIGAME_COUNT 6
#define xScale 1.3f
#define yScale 1.3f

class MinigameSelectScene : public Scene
{
	private:
		enum MINIGAME_LIST
		{
			MAZE = 0
		};

		//std::vector<MinigameDescriptor
		MinigameDescriptor minigames[MINIGAME_COUNT] =
		{
			MinigameDescriptor("Maze", "Navigate through a maze.\n\n\n\nAims to teach: Object Movement", "mazeSmall.png", "mazeLarge.png"),
			MinigameDescriptor("Pong", "Don't let the ball bounce\ninto your base!\n\n\nAims to teach: Conditionals", "pongSmall.png", "pongLarge.png"),
			MinigameDescriptor("Tic-Tac-Toe", "Get three X's in a row!\n\n\n\nAims to teach: Object Creation", "TTTSmall.png", "TTTLarge.png"),
			MinigameDescriptor(),
			MinigameDescriptor(),
			MinigameDescriptor()
		};

		int selectedMinigame = -1;

		RectangleMenuItem *whiteBackground;

		SpriteMenuItem *selectedMinigameLargeSprite = nullptr;
		TextMenuItem *MinigameSelectTopText = nullptr, *MinigameDescription = nullptr, *MinigameName = nullptr;
		ButtonMenuItem* minigameOptions[MINIGAME_COUNT];

	public:
		MinigameSelectScene();
		~MinigameSelectScene();

		void initialize();
		void draw();
		void update();

		void load() {};
		void unload() {};
		void onEnter() {};
		void onExit() {};

		void SelectMinigame(int index);
};
