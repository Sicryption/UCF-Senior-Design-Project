#include "minigameSelect.hpp"
#include "../scenes/MazeScene.hpp"

MinigameSelect::MinigameSelect(m3d::Screen* screen) :
	Menu(screen)
{
	MinigameSelectTopText = new m3dCI::Text("Select a minigame");
	MinigameSelectTopText->setFontSize(1);
	MinigameSelectTopText->setFontWeight(1);
	MinigameSelectTopText->setColor(m3d::Color(0, 0, 0));

	int width = MinigameSelectTopText->getWidth();
	int height = MinigameSelectTopText->getHeight();
	
	int topScreenWidth = screen->getScreenWidth(m3d::RenderContext::ScreenTarget::Top);
	int bottomScreenWidth = screen->getScreenWidth(m3d::RenderContext::ScreenTarget::Bottom);
	int screenHeight = screen->getScreenHeight();

	MinigameSelectTopText->setPosition((topScreenWidth / 2) - (width / 2), (screenHeight / 2) - (height / 2));

	whiteBackground = new m3d::Rectangle(0, 0, 1000, 1000, m3d::Color(255, 255, 255));

	int ButtonWidth = 50;
	int ButtonHeight = 50;

	int Rows = MINIGAME_COUNT / 3;
	int Columns = MINIGAME_COUNT / 2;

	int rowPadding = ((screenHeight * 0.25) * Rows - (ButtonHeight * Rows)) / (Rows - 1);
	int columnPadding = ((bottomScreenWidth * 0.25) * Columns - (ButtonWidth * Columns)) / (Columns - 1);//45

	for (int i = 0; i < MINIGAME_COUNT; i++)
	{
		int row = i % Rows;
		int column = i % Columns;

		int x = (bottomScreenWidth * 0.25) / 2 + (columnPadding * column) + (ButtonWidth * column),
			y = (screenHeight * 0.25) + (rowPadding * row) + (ButtonHeight * row),
			w = ButtonWidth,
			h = ButtonHeight;

		m3dCI::Button* newButton = om->CreateButton(x, y, w, h, m3d::Color(255, 255, 255), m3d::Color(0, 0, 0), 3);
		newButton->OnRelease = [&, i]()
		{
			if(i == MINIGAME_LIST::MAZE)
				SceneManager::transitionTo(new MazeScene());

			MenuHandler::getInstance()->TransitionTo(MenuHandler::MenuState::MinigameTemplateMenu);
		};

		minigameOptions[column + (row * Columns)] = newButton;
	}

	OnUpdate();
}

void MinigameSelect::OnUpdate()
{
	if (util->IsConsoleDrawn())
		return;

	scr->drawTop(*whiteBackground, RenderContext::Mode::Flat);
	scr->drawBottom(*whiteBackground, RenderContext::Mode::Flat);
	scr->drawTop(*MinigameSelectTopText, RenderContext::Mode::Flat);

	for(int i = 0; i < MINIGAME_COUNT; i++)
		scr->drawBottom(*minigameOptions[i], RenderContext::Mode::Flat);
}

MinigameSelect::~MinigameSelect()
{
	for (int i = 0; i < MINIGAME_COUNT; i++)
		om->DeleteButton(minigameOptions[i]);
	delete(whiteBackground);
	delete(MinigameSelectTopText);
}