#include "TicTacToeScene.hpp"
#include "MinigameSelectScene.hpp"

TicTacToeScene::TicTacToeScene() //: Minigame()
{

}

TicTacToeScene::~TicTacToeScene() 
{

}

/**
 *  @brief
 * 
 * 
 */
void TicTacToeScene::initialize() {
    Minigame::initialize();

    colorRec = new m3d::Color(150,150,150);
	colorText = new m3d::Color(0,0,0);

    //  Initialize Detectors
    for (int i = 0; i < TTT_NUM_CELLS; i++)
    {
        int row = (i % TTT_NUM_ROWS);
        int col = (i / TTT_NUM_ROWS);
        m_detectors[i] = new BoundingBox(
                                            TTT_X + (TTT_CELL_SIZE * row), 
                                            TTT_Y + (TTT_CELL_SIZE * col), 
                                            TTT_DETECTOR_SIZE, 
                                            TTT_DETECTOR_SIZE
                                        );
        m_board[i] = BoardState::VACANT;
    }
       

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

    screen->drawTop(*wallpaper);
    
}

void TicTacToeScene::load(){Minigame::load();};

void TicTacToeScene::unload(){Minigame::unload();};

void TicTacToeScene::update()
{
    Minigame::update();
    switch (currentState)
    {
        case TutorialMessage:
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

void TicTacToeScene::updateBoard()
{

}

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
