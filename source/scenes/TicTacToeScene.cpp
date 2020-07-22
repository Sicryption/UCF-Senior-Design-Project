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

    rectangleTest = new RectangleMenuItem(50,130,50,50,*colorRec);
    menu->AddItem(rectangleTest);

    winPrompt = new TextMenuItem("You Win!",*colorText);
	menu->AddItem(winPrompt);
	winPrompt->setPosition(90,30);
	winPrompt->setFontSize(.5);
	winPrompt->setFontWeight(.5);
	winPrompt->setPosition(160,120);

    prompt = new TextMenuItem("Welcome to Tic Tac Toe",*colorText);
	menu->AddItem(prompt);
	prompt->setPosition(90,30);
	prompt->setFontSize(.5);
	prompt->setFontWeight(.5);
	wallpaper = new SpriteMenuItem(*(ResourceManager::getSprite("TTT_BG.png")));
	menu->AddItem(wallpaper);

    popup = new SpriteMenuItem(*(ResourceManager::getSprite("menu_popup.png")));
	menu->AddItem(popup);
	popup->setPosition(80,20);

	wallpaper->setCenter(0,0);
	wallpaper->setScale(1,1);

	currentState = TTTState::TutorialMessage;
}

void TicTacToeScene::draw() {
    Minigame::draw();

    m3d::Screen *screen = GameManager::getScreen();

    wallpaper->setPosition(0,0);
    screen->drawTop(*wallpaper);
    screen->drawtop(*rectangleTest);

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

void TicTacToeScene::runEnemyAI()
{
    
}
