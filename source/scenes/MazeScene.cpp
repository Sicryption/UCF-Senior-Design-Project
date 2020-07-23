#include "MazeScene.hpp"
#include "MinigameSelectScene.hpp"

MazeScene::MazeScene()
{
    //array traversers
    x = 1.0;
	y = 0.0;
}

MazeScene::~MazeScene()
{

}

void MazeScene::initialize(){
	Minigame::initialize();

//loads and gets maze texture
	//texture = new m3dCI::Sprite(*(ResourceManager::getSprite("wall.png")));
    //sprite* spr = new m3d::Sprite();

//initialize playable character
    runner = new TerminalObject(wallHolder);

	runnerID = addObject(runner);
    runner->initialize();
	setObjectName("runner", runnerID);
	//addObject(runner);

//Load text and bottom screen background color
	colorRec = new m3d::Color(150,150,150);
	colorText = new m3d::Color(0,0,0);
	mazeState = 1;

//initializes text and bottom screen background
	winScreen = new RectangleMenuItem(0,0,320,240,*colorRec);
	menu->AddItem(winScreen);
	timePrompt = new TextMenuItem("You Win!",*colorText);
	menu->AddItem(timePrompt);
	timePrompt->setPosition(90,30);
	timePrompt->setFontSize(.5);
	timePrompt->setFontWeight(.5);
	timePrompt->setPosition(160,120);
			
	
	wallpapers[0] = new SpriteMenuItem(*(ResourceManager::getSprite("maze1.png")));
	menu->AddItem(wallpapers[0]);
	wallpapers[1] = new SpriteMenuItem(*(ResourceManager::getSprite("maze2.png")));
	menu->AddItem(wallpapers[1]);
	wallpapers[2] = new SpriteMenuItem(*(ResourceManager::getSprite("maze3.png")));
	menu->AddItem(wallpapers[2]);
	current = wallpapers[0];
	//  Initialize popup BG
    wPopup = new SpriteMenuItem(*(ResourceManager::getSprite("win_popup.png")));
	menu->AddItem(wPopup);
	wPopup->setPosition(80,20);
	//wallpaper->setTexture(*texture);
	current->setCenter(0,0);
	current->setScale(1,1);
	//tutorial
	tutorial[0] = new SpriteMenuItem(*(ResourceManager::getSprite("maze_tutorial_1.png")));
	menu->AddItem(tutorial[0]);
	tutorial[1] = new SpriteMenuItem(*(ResourceManager::getSprite("maze_tutorial_2.png")));
	menu->AddItem(tutorial[1]);
	tutorial[2] = new SpriteMenuItem(*(ResourceManager::getSprite("maze_tutorial_3.png")));
	menu->AddItem(tutorial[2]);
	tutorial[3] = new SpriteMenuItem(*(ResourceManager::getSprite("maze_tutorial_4.png")));
	menu->AddItem(tutorial[3]);
	tutorial[4] = new SpriteMenuItem(*(ResourceManager::getSprite("maze_tutorial_5.png")));
	menu->AddItem(tutorial[4]);
	tutCount = 0;
	popup = tutorial[tutCount++];
	popup->setPosition(80,20);

	currentState = MazeState::TutorialMessage;

	lPopup = new SpriteMenuItem(*(ResourceManager::getSprite("lose_popup.png")));
	menu->AddItem(lPopup);
	lPopup->setPosition(80, 20);
	timer = 15.00;
	timerS = std::to_string(timer);
	timerS.resize(5);
	timerP = new TextMenuItem(timerS);
    timerP->setFontSize(0.75f);
	timerP->setFontWeight(0.75f);
	timerP->getWidth();
	timerP->setPosition(200-((timerP->getWidth())/2),0);
}

void MazeScene::transistion(){
	currentState = MazeState::Requesting;
	if(mazeState == 1)
	{
		timer = 15.00;
		std::vector<CommandObject*> startingCommands =
					{
						new SelectCommand("runner",true,true),
						new RightCommand("18"),
						new DownCommand("5"),
						new LeftCommand("18"),
						new DownCommand("5"),
						new RightCommand("18"),
						new DownCommand("5"),
						new LeftCommand("18"),
						new DownCommand("5"),
						new RightCommand("18")
					};
		SceneManager::RequestUserCode(startingCommands, [&](std::vector<CommandObject*> commands) { SubmitMazeCode(commands); });
		current = wallpapers[0];
		runner->setposition(20,20,wallHolder);
	}
	if(mazeState == 2)
	{
		timer = 10.00;
		std::vector<CommandObject*> startingCommands =
		{
			new SelectCommand("runner",true,true),
			new RightCommand("5"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
			new UpCommand("1"),
			new RightCommand("1"),
		};
		SceneManager::RequestUserCode(startingCommands, [&](std::vector<CommandObject*> commands) { SubmitMazeCode(commands); });
		current = wallpapers[1];
		runner->setposition(20,180,wallHolderToo);
	}
	if(mazeState == 3)
	{
		timer = 20.00;
		std::vector<CommandObject*> startingCommands =
		{
			new SelectCommand("runner",true,true),
			new LeftCommand("18"),
			new UpCommand("18"),
			new RightCommand("18"),
			new DownCommand("18"),
			new LeftCommand("18"),
			new UpCommand("18"),
			new RightCommand("18"),
			new DownCommand("18"),
			new LeftCommand("18"),
		};
		SceneManager::RequestUserCode(startingCommands, [&](std::vector<CommandObject*> commands) { SubmitMazeCode(commands); });
		current = wallpapers[2];
		runner->setposition(360,200,wallHolderThree);
	}
	timerS = std::to_string(timer);
	timerS.resize(5);
	timerP->setText(timerS);
	timerP->setPosition(200-((timerP->getWidth())/2),0);
};

void MazeScene::draw(){

	m3d::Screen * screen = GameManager::getScreen();

	current->setPosition(0,0);
    screen->drawTop(*current);
	screen->drawTop(*timerP, m3d::RenderContext::Mode::Flat, 4);

    if(currentState == MazeState::TutorialMessage)
    {   
        screen->drawTop(*popup, m3d::RenderContext::Mode::Flat, 2);
		//screen->drawTop(*prompt);
		//use m3dci for prompt
    }

	if(currentState == MazeState::Win)
    {   
        screen->drawTop(*wPopup, m3d::RenderContext::Mode::Flat, 2);
		//screen->drawTop(*winPrompt);
		//use m3dci for prompt
    }

	if(currentState == MazeState::Lose)
    {   
        screen->drawTop(*lPopup, m3d::RenderContext::Mode::Flat, 2);
    }

	Minigame::draw();
    runner->draw();

}
		
void MazeScene::load(){ Minigame::load(); }; //any data files

void MazeScene::unload(){ Minigame::unload(); };

void MazeScene::onExecutionBegin()
{
	//isExecuting = true;
}

void MazeScene::onExecutionEnd()
{

}

void MazeScene::update()
{
	Minigame::update();

	switch (currentState)
	{
		case MazeState::TutorialMessage:
			isExecuting = true;

			if (buttons::buttonPressed(buttons::A) || buttons::buttonDown(buttons::Start)){
				if(tutCount >= 5 || buttons::buttonDown(buttons::Start))
				{
					currentState = MazeState::Requesting;

					std::vector<CommandObject*> startingCommands =
					{
						new SelectCommand("runner",true,true),
						new RightCommand("18"),
						new DownCommand("5"),
						new LeftCommand("18"),
						new DownCommand("5"),
						new RightCommand("18"),
						new DownCommand("5"),
						new LeftCommand("18"),
						new DownCommand("5"),
						new RightCommand("18")
					};

					SceneManager::RequestUserCode(startingCommands, [&](std::vector<CommandObject*> commands) { SubmitMazeCode(commands); });
					tutCount = 0;
					break;
				}
				popup = tutorial[tutCount++];
				popup->setPosition(80,20);
			}

			//Disable all buttons during tutorial
			break;
		case MazeState::Execute:
			isExecuting = true;

			timer -= GameManager::getDeltaTime();	
			if(timer <= 0)
				timer = 0.00;
			timerS = std::to_string(timer);
			if(timer < 10)
				timerS.resize(4);
			else
			{
				timerS.resize(5);
				timerP->setPosition(200-((timerP->getWidth())/2),0);
			}
			timerP->setText(timerS);

			
			if(checkWinCond() == 1)
			{
				if(mazeState == 3)
				{
					currentState = MazeState::Win;
					m_sandbox->setThreadState(THREAD_CLEAR);
					break;
				}
				currentState = MazeState::Transistion;
				m_sandbox->setThreadState(THREAD_CLEAR);
				mazeState++;
				break;
			}
			else if (timer == 0 && checkWinCond() == 0)
			{
				currentState = MazeState::Lose;
				m_sandbox->setThreadState(THREAD_CLEAR);
			}
			break;
		case MazeState::Win:
			if (buttons::buttonPressed(buttons::A))
				SceneManager::setTransition(new MinigameSelectScene());
			};
			break;
		case MazeState::Lose:
			if (Input::btnReleased(m3d::buttons::B)) // return to minigame select screen
                SceneManager::setTransition(new MinigameSelectScene());
			if (Input::btnReleased(m3d::buttons::A)) // restart the game 
			{
				currentState = MazeState::Transistion;
				isExecuting = false;
			}
			break;
		case MazeState::Transistion:
			isExecuting = false;
			transistion();
			break;
		case MazeState::Requesting:
			isExecuting = false;

			if (Input::btnReleased(m3d::buttons::B))
				SceneManager::setTransition(new MinigameSelectScene());
			break;
	}

	Util::PrintLine(std::to_string(currentState));
};

void MazeScene::SubmitMazeCode(std::vector<CommandObject*> luaCode)
{	
	#ifdef DEBUG_MINIGAME
    Util::PrintLine("Maze: queue commands");
    #endif
    std::string str = CommandObject::ConvertBulk(luaCode);

    /*
        Encapsulate code into a function. then call the function.
    */
    stringstream fn;
    fn << "userCode = function()" << str << " end\n" << "\n";
    m_sandbox->executeStringQueued(fn.str()); // if this returns false theres an error in the usercode
    m_sandbox->executeStringQueued("userCode()\n");

    #ifdef DEBUG_MINIGAME
    Util::PrintLine("Maze: done");
    #endif
	currentState = MazeState::Execute;
}

void MazeScene::onEnter(){ Minigame::onEnter(); };
void MazeScene::onExit() { Minigame::onExit(); };
bool MazeScene::checkWinCond()
{
	switch (mazeState)
	{
	case 1:
		winX = 18;
		winY = 9;
		break;

	case 2:
		winX = 17;
		winY = 1;
		break;

	case 3:
		winX = 5;
		winY = 6;
		break;
	
	default:
		break;
	}
	if((runner->getX()/20) == winX && (runner->getY()/20) == winY)
	{
		return 1;
	}
	else
	{
		return 0;
	}
			
};
void MazeScene::loadScene() { Minigame::loadScene(); };
void MazeScene::loadWinScr() { Minigame::loadWinScr(); };
void MazeScene::loadLoseScr() { Minigame::loadLoseScr(); };
void MazeScene::requestUI() { Minigame::requestUI(); };
void MazeScene::closeGame() { Minigame::closeGame(); };