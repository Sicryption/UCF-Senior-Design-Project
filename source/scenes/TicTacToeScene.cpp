#include "TicTacToeScene.hpp"
#include "MinigameSelectScene.hpp"

TicTacToeScene::TicTacToeScene()
{

}

TicTacToeScene::~TicTacToeScene()
{

}

void TicTacToeScene::initialize() {
    Minigame::initialize();

    colorRec = new m3d::Color(150,150,150);
	colorText = new m3d::Color(0,0,0);

    winPrompt = new TextMenuItem("You Win!",*colorText);
	winPrompt->setPosition(90,30);
	winPrompt->setFontSize(.5);
	winPrompt->setFontWeight(.5);
	winPrompt->setPosition(160,120);
	menu->AddItem(winPrompt);

    prompt = new TextMenuItem(" Use move commands to traverse \n the maze. In order to add a move \n command select Add, then go to\n the tab with the arrows. There\n you can select up, down, left \n or right as a direction to\n move in the maze. You can then\n change the amount of spaces you\n want to move by selecting it and\n clicking edit. Be sure to enter all\n commands you will need to get to\n the end of the maze before running.",*colorText);
	prompt->setPosition(90,30);
	prompt->setFontSize(.5);
	prompt->setFontWeight(.5);
	menu->AddItem(prompt);

	wallpaper = new SpriteMenuItem(*(ResourceManager::getSprite("tictactoe1.png")));
	wallpaper->setCenter(0, 0);
	wallpaper->setScale(1, 1);
	menu->AddItem(wallpaper);

    popup = new SpriteMenuItem(*(ResourceManager::getSprite("menu_popup.png")));
	popup->setPosition(80, 20);
	menu->AddItem(popup);

	currentState = TTTState::TutorialMessage;
}

void TicTacToeScene::draw() {
    Minigame::draw();

    m3d::Screen *screen = GameManager::getScreen();

    wallpaper->setPosition(0,0);
    screen->drawTop(*wallpaper);

    /*if(currentState == TTTState::TutorialMessage)
    {   
        screen->drawTop(*popup);
		screen->drawTop(*prompt);
		//use m3dci for prompt
    }*/
}

void TicTacToeScene::load(){Minigame::load();};

void TicTacToeScene::unload(){Minigame::unload();};

void TicTacToeScene::update()
{
    Minigame::update();
    switch (currentState)
    {
    case TutorialMessage:
        /* code */
        break;
    case Requesting:
        break;
    case Execute:
        break;
    case EnemyTurn:
        break; 
    case Win:
        break;
    case Lose:
        break;
    default:
        break;
    }
};

void TicTacToeScene::SubmitTTTCode(std::vector<CommandObject*> luaCode)
{

}

void TicTacToeScene::onEnter(){Minigame::onEnter();};
void TicTacToeScene::onExit(){Minigame::onExit();};
bool TicTacToeScene::checkWinCond() 
{
    return true;
    
    return false;
}

void TicTacToeScene::loadScene() { Minigame::loadScene(); };
void TicTacToeScene::loadWinScr() { Minigame::loadWinScr(); };
void TicTacToeScene::loadLoseScr() { Minigame::loadLoseScr(); };
void TicTacToeScene::requestUI() { Minigame::requestUI(); };
void TicTacToeScene::closeGame() { Minigame::closeGame(); };
