#include "TicTacToeScene.hpp"
#include "MinigameSelectScene.hpp"

#define t(x) AddCommand(x)
#define func(a) [&]() { t(a); }
#define PAIR(name, command) { name, [&]() { t(command); }}
#define NULLPartialPAIR(name) { name, nullptr }
#define NULLPAIR PAIR("", nullptr)
#define COLORPAIR(name, r, g, b) PAIR(name, new ColorCommand(name, m3d::Color(r,g,b,255)))

TicTacToeScene::TicTacToeScene()
{
	commandLister->OverrideTabCommandListObjects(
		{
			PAIR("Naught", new TTT_O_Command()),
			PAIR("Cross", new TTT_X_Command())
		}, 0
	);
	for (int i = 1; i < NUM_TABS; i++)
	{
		commandLister->OverrideTabCommandListObjects({}, i);
		commandLister->SetTabState(i, false);
	}
}

TicTacToeScene::~TicTacToeScene()
{

}

void TicTacToeScene::initialize() {
    Minigame::initialize();

    colorRec = new m3d::Color(150,150,150);
	colorText = new m3d::Color(0,0,0);

    topLeftTest = new RectangleMenuItem(220,40,40,40,*colorRec);
    topMidTest = new RectangleMenuItem(280,40,40,40,*colorRec);
    topRightTest = new RectangleMenuItem(340,40,40,40,*colorRec);

    menu->AddItem(topLeftTest);
    menu->AddItem(topRightTest);
    menu->AddItem(topMidTest);

    midLeftTest = new RectangleMenuItem(220,100,40,40,*colorRec);
    midMidTest = new RectangleMenuItem(280,100,40,40,*colorRec);
    midRightTest = new RectangleMenuItem(340,100,40,40,*colorRec);

    menu->AddItem(midLeftTest);
    menu->AddItem(midRightTest);
    menu->AddItem(midMidTest);

    botLeftTest = new RectangleMenuItem(220,160,40,40,*colorRec);
    botMidTest = new RectangleMenuItem(280,160,40,40,*colorRec);
    botRightTest = new RectangleMenuItem(340,160,40,40,*colorRec);

    menu->AddItem(botLeftTest);
    menu->AddItem(botRightTest);
    menu->AddItem(botMidTest);

    /*topLeftBB = topLeftTest->getBoundingBox();
    topMidBB = topMidTest->getBoundingBox();
    topRightBB = topRightTest->getBoundingBox();

    midLeftBB = midLeftTest->getBoundingBox();
    midMidBB = midMidTest->getBoundingBox();
    midRightBB = midRightTest->getBoundingBox();

    botLeftBB = botLeftTest->getBoundingBox();
    botMidBB = botMidTest->getBoundingBox();
    botRightBB = botRightTest->getBoundingBox();
    */

    cTL = new m3d::Circle(240,60,20,*colorText);
    cTM = new m3d::Circle(300,60,20,*colorText);
    cTR = new m3d::Circle(360,60,20,*colorText);

    cML = new m3d::Circle(240,120,20,*colorText);
    cMM = new m3d::Circle(300,120,20,*colorText);
    cMR = new m3d::Circle(360,120,20,*colorText);

    cBL = new m3d::Circle(240,180,20,*colorText);
    cBM = new m3d::Circle(300,180,20,*colorText);
    cBR = new m3d::Circle(360,180,20,*colorText);

    /*cTLBB= cTL->getBoundingBox();
    cTMBB= cTM->getBoundingBox();
    cTRBB= cTR->getBoundingBox();

    cMLBB= cML->getBoundingBox();
    cMMBB= cMM->getBoundingBox();
    cMRBB= cMR->getBoundingBox();
    
    cBLBB= cBL->getBoundingBox();
    cBMBB= cBM->getBoundingBox();
    cBRBB= cBR->getBoundingBox();
    */
    

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
    screen->drawTop(*topLeftTest);
    screen->drawTop(*topMidTest);
    screen->drawTop(*topRightTest);

    screen->drawTop(*midLeftTest);
    screen->drawTop(*midMidTest);
    screen->drawTop(*midRightTest);

    screen->drawTop(*botLeftTest);
    screen->drawTop(*botMidTest);
    screen->drawTop(*botRightTest);

    screen->drawTop(*cTL);
    screen->drawTop(*cTM);
    screen->drawTop(*cTR);

    screen->drawTop(*cML);
    screen->drawTop(*cMM);
    screen->drawTop(*cMR);

    screen->drawTop(*cBL);
    screen->drawTop(*cBM);
    screen->drawTop(*cBR);

    if (topLeftTest->getBoundingBox().intersects(cTL->getBoundingBox()))
    {
        winPrompt->setPosition(20,20);
        screen->drawTop(*winPrompt);
    }
    if (topMidTest->getBoundingBox().intersects(cTM->getBoundingBox()))
    {
        winPrompt->setPosition(20,30);
        screen->drawTop(*winPrompt);
    }
    if (topRightTest->getBoundingBox().intersects(cTR->getBoundingBox()))
    {
        winPrompt->setPosition(20,40);
        screen->drawTop(*winPrompt);
    }
    if (midLeftTest->getBoundingBox().intersects(cML->getBoundingBox()))
    {
        winPrompt->setPosition(20,50);
        screen->drawTop(*winPrompt);
    }
    if (midMidTest->getBoundingBox().intersects(cMM->getBoundingBox()))
    {
        winPrompt->setPosition(20,60);
        screen->drawTop(*winPrompt);
    }
    if (midRightTest->getBoundingBox().intersects(cMR->getBoundingBox()))
    {
        winPrompt->setPosition(20,70);
        screen->drawTop(*winPrompt);
    }
    if (botLeftTest->getBoundingBox().intersects(cBL->getBoundingBox()))
    {
        winPrompt->setPosition(20,80);
        screen->drawTop(*winPrompt);
    }
    if (botMidTest->getBoundingBox().intersects(cBM->getBoundingBox()))
    {
        winPrompt->setPosition(20,90);
        screen->drawTop(*winPrompt);
    }
    if (botRightTest->getBoundingBox().intersects(cBR->getBoundingBox()))
    {
        winPrompt->setPosition(20,100);
        screen->drawTop(*winPrompt);
    }
    
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
