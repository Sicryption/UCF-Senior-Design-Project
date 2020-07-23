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
     
    wallpaper= new SpriteMenuItem(*(ResourceManager::getSprite("TTT_BG.png")));
    menu->AddItem(wallpaper);

	wallpaper->setCenter(0,0);
	wallpaper->setScale(1,1);
       
    tutorial[0] = new SpriteMenuItem(*(ResourceManager::getSprite("TTT_Tutorial1.png")));
    menu->AddItem(tutorial[0]);
    tutorial[1] = new SpriteMenuItem(*(ResourceManager::getSprite("TTT_Tutorial2.png")));
    menu->AddItem(tutorial[1]);
    tutorial[2] = new SpriteMenuItem(*(ResourceManager::getSprite("TTT_Tutorial3.png")));
    menu->AddItem(tutorial[2]);
    tutCount = 0;

    popup = tutorial[tutCount];
    popup->setPosition(80,20);

	currentState = TTTState::TutorialMessage;
}

void TicTacToeScene::draw() {
    Minigame::draw();

    m3d::Screen *screen = GameManager::getScreen();

    screen->drawTop(*wallpaper);

    if(currentState == TTTState::TutorialMessage)
    {
        screen->drawTop(*popup,m3d::RenderContext::Mode::Flat,2);
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

            AddButton->SetActive(false);
            RemoveButton->SetActive(false);
            EditButton->SetActive(false);
            submitButton->SetActive(false);

            if (m3d::buttons::buttonPressed(m3d::buttons::A))
            {
                if (tutCount < 3)
                {
                    tutCount++;
                }

                if (tutCount < 3)
                {
                    popup = tutorial[tutCount];
                    popup->setPosition(80,20);
                }    
            }

            if (m3d::buttons::buttonDown(m3d::buttons::Start) || tutCount >= 3)
            {
                tutCount = 0;

                currentState = TTTState::Requesting;

                codeEditor->SetActive(true);
            }
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
