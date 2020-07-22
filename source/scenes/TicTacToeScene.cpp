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

    topLeftBB = topLeftTest->getBoundingBox();
    topMidBB = topMidTest->getBoundingBox();
    topRightBB = topRightTest->getBoundingBox();

    midLeftBB = midLeftTest->getBoundingBox();
    midMidBB = midMidTest->getBoundingBox();
    midRightBB = midRightTest->getBoundingBox();

    botLeftBB = botLeftTest->getBoundingBox();
    botMidBB = botMidTest->getBoundingBox();
    botRightBB = botRightTest->getBoundingBox();

    cTL = new m3d::Circle(240,60,20,*colorText);
    cTM = new m3d::Circle(300,60,20,*colorText);
    cTR = new m3d::Circle(360,60,20,*colorText);

    cML = new m3d::Circle(240,120,20,*colorText);
    cMM = new m3d::Circle(300,120,20,*colorText);
    cMR = new m3d::Circle(360,120,20,*colorText);

    cBL = new m3d::Circle(240,180,20,*colorText);
    cBM = new m3d::Circle(300,180,20,*colorText);
    cBR = new m3d::Circle(360,180,20,*colorText);

    cTLBB= cTL->getBoundingBox();
    cTMBB= cTM->getBoundingBox();
    cTRBB= cTR->getBoundingBox();

    cMLBB= cML->getBoundingBox();
    cMMBB= cMM->getBoundingBox();
    cMRBB= cMR->getBoundingBox();
    
    cBLBB= cBL->getBoundingBox();
    cBMBB= cBM->getBoundingBox();
    cBRBB= cBR->getBoundingBox();
    

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

    if (topLeftBB.intersects(cTLBB))
    {
        winPrompt->setPosition(20,20);
        screen->drawTop(*winPrompt);
    }
    if (topMidBB.intersects(cTMBB))
    {
        winPrompt->setPosition(20,30);
        screen->drawTop(*winPrompt);
    }
    if (topRightBB.intersects(cTRBB))
    {
        winPrompt->setPosition(20,40);
        screen->drawTop(*winPrompt);
    }
    if (midLeftBB.intersects(cMLBB))
    {
        winPrompt->setPosition(20,50);
        screen->drawTop(*winPrompt);
    }
    if (midMidBB.intersects(cMMBB))
    {
        winPrompt->setPosition(20,60);
        screen->drawTop(*winPrompt);
    }
    if (midRightBB.intersects(cMRBB))
    {
        winPrompt->setPosition(20,70);
        screen->drawTop(*winPrompt);
    }
    if (botLeftBB.intersects(cBLBB))
    {
        winPrompt->setPosition(20,80);
        screen->drawTop(*winPrompt);
    }
    if (botMidBB.intersects(cBMBB))
    {
        winPrompt->setPosition(20,90);
        screen->drawTop(*winPrompt);
    }
    if (botRightBB.intersects(cBRBB))
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
