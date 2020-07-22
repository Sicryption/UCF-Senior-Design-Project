#include "PongScene.hpp"
#include "MinigameSelectScene.hpp"

#define TUTORIAL_POPUP_COUNT 5

Util* util = Util::getInstance();

PongScene::PongScene()
{

}

PongScene::~PongScene()
{

}

void PongScene::initialize(){
	Minigame::initialize();

	// assign player and enemy points and points to win 
	points = { 0,0 };
	matchPoint = 1;
	
	// initalize the scene background
	wallpaper = new SpriteMenuItem(*(ResourceManager::getSprite("pong1.png")));
	wallpaper->setCenter(0, 0);
	wallpaper->setScale(1, 1);

	//  initialize the popup window 
	/*
	popup = new SpriteMenuItem(*(ResourceManager::getSprite("menu_popup.png")));
	popup->setPosition(80, 20);
	*/


	//  initialize the win popup window 
	wPopup = new SpriteMenuItem(*(ResourceManager::getSprite("win_popup.png")));
	wPopup->setPosition(80, 20);

	//  initialize the lose popup window 
	lPopup = new SpriteMenuItem(*(ResourceManager::getSprite("lose_popup.png")));
	lPopup->setPosition(80, 20);


	//  initialize the tutorial windows 
	for (int i = 0; i < TUTORIAL_POPUP_COUNT; i++)
	{
		tutorial[i] = new SpriteMenuItem(*(ResourceManager::getSprite("pong_tutorial_" + std::to_string(i + 1) + ".png")));
		tutorial[i]->setPosition(80, 20);
	}

	
	tutCount = 0;
	popup = tutorial[tutCount];

	// initialize the game objects and add them to the hash map
	ball = new PongBall();
	int ballID = addObject(ball);
	setObjectName("ball", ballID);

	ball->initialize();

	leftPaddle = new PongPaddle(20, 90);
	int paddleID = addObject(leftPaddle);
	setObjectName("player", paddleID);

	leftPaddle->initialize();

	rightPaddle = new PongPaddle(380, 90, ball);
	int enemyID = addObject(rightPaddle);
	setObjectName("enemy", enemyID);

	rightPaddle->initialize();

	
	currentState = PongState::TutorialMessage;
}

void PongScene::draw(){
	Minigame::draw();

	m3d::Screen *screen = GameManager::getScreen();

	wallpaper->setPosition(0, 0);
	screen->drawTop(*wallpaper);

	ball->draw();

	leftPaddle->draw();

	rightPaddle->draw();

	if (currentState == PongState::TutorialMessage)
	{
		screen->drawTop(*popup);
	}

	// display win screen
	if (currentState == PongState::Win)
	{
		screen->drawTop(*wPopup);
	}

	// display lose screen
	if (currentState == PongState::Lose)
	{
		screen->drawTop(*lPopup);
	}



}
		
void PongScene::load(){ Minigame::load(); }; //any data files
        
void PongScene::unload(){ Minigame::unload(); };
        
void PongScene::update()
{
	Minigame::update();

	switch(currentState)
	{
		case PongState::TutorialMessage:
			// player reads the tutorial 
			if (buttons::buttonPressed(buttons::A)) 
			{
				if (tutCount < TUTORIAL_POPUP_COUNT)
				{
					tutCount++;

					if(tutCount < TUTORIAL_POPUP_COUNT)
						popup = tutorial[tutCount];
				}
			}
			// the player submits their code
			if (buttons::buttonDown(buttons::Start) || tutCount >= TUTORIAL_POPUP_COUNT)
			{
				tutCount = 0;

				currentState = PongState::Requesting;

				std::vector<CommandObject*> startingCommands =
				{
					new WhileCommand("true", true, true),
					new SelectCommand("ball"),
					new GetYCommand("by"),
					new SelectCommand("player"),
					new SetYCommand("by"),
					new EndCommand(true)

				};

				SceneManager::RequestUserCode(startingCommands, [&](std::vector<CommandObject*> commands) { SubmitPongCode(commands); });
			}
		break;
		case PongState::Requesting:
			if (Input::btnReleased(m3d::buttons::B))
				SceneManager::setTransition(new MinigameSelectScene());
		break;
		case PongState::Win:
			if (Input::btnReleased(m3d::buttons::B))
				SceneManager::setTransition(new MinigameSelectScene());
		break;
		case PongState::Lose:
			if (Input::btnReleased(m3d::buttons::B)) // return to minigame select screen
				SceneManager::setTransition(new MinigameSelectScene());
			if (Input::btnReleased(m3d::buttons::A)) // restart the game 
				initialize();
		break;
		case PongState::Execute:

			// determine winner and loser
			if (points[0] == matchPoint)
			{
				currentState = PongState::Lose;
			}
			else if (points[1] == matchPoint)
			{
				currentState = PongState::Win;
			}

			BoundingBox ballAABB = ball->getAABB();

			// handle ball bouncing
			for (int i = 0; i < m_hashmap.size(); i++)
			{
				// We don't want the ball interacting with itself
				if (m_hashmap[i] == ball)
					continue;

				BoundingBox aabb = m_hashmap[i]->getAABB();

				// check if ball is inside object
				if (aabb.intersects(ballAABB))
				{
					//if so, bounce off

					//Determine which side of the ball hit the wall

					int pixelDifference = 3;

					//We can't take corners, and instead need to detect using a one pixel BB on each side of each corner.
					BoundingBox TL = BoundingBox(ballAABB.getX() + pixelDifference, ballAABB.getY(), 1, 1),
						TR = BoundingBox(ballAABB.getX() + ballAABB.getWidth() - pixelDifference, ballAABB.getY(), 1, 1),
						LT = BoundingBox(ballAABB.getX(), ballAABB.getY() + pixelDifference, 1, 1),
						LB = BoundingBox(ballAABB.getX(), ballAABB.getY() + ballAABB.getHeight() - pixelDifference, 1, 1),
						BL = BoundingBox(ballAABB.getX() + pixelDifference, ballAABB.getY() + ballAABB.getHeight(), 1, 1),
						BR = BoundingBox(ballAABB.getX() + ballAABB.getWidth() - pixelDifference, ballAABB.getY() + ballAABB.getHeight(), 1, 1),
						RT = BoundingBox(ballAABB.getX() + ballAABB.getWidth(), ballAABB.getY() + pixelDifference, 1, 1),
						RB = BoundingBox(ballAABB.getX() + ballAABB.getWidth(), ballAABB.getY() + ballAABB.getHeight() - pixelDifference, 1, 1);

					// set ball's direction based on where it collided
					if (aabb.intersects(TL) || aabb.intersects(TR))
						ball->SetDirection(0, 1);
					else if (aabb.intersects(BL) || aabb.intersects(BR))
						ball->SetDirection(0, -1);
					else if (aabb.intersects(LT) || aabb.intersects(LB))
						ball->SetDirection(1, 0);
					else if (aabb.intersects(RT) || aabb.intersects(RB))
						ball->SetDirection(-1, 0);

					if (m_hashmap[i] == rightPaddle)
						rightPaddle->ballBouncedOffPaddle();
				}
			}

			// ball goes out of x bounds, a goal has been scored
			if (ball->getXPosition() < 0 || ball->getXPosition() + ball->getWidth() > TOPSCREEN_WIDTH)
			{
				if (ball->getXPosition() < 0) // enemy scores
				{
					points[0]++;
				}
				else // player scores 
				{
					points[1]++;
				}

				ball->reset();
				rightPaddle->reset();
			}

			// ball goes out of y bounds, a collision with the wall occurs 
			if (ball->getYPosition() < 0 || ball->getYPosition() + ball->getHeight() >= TOPSCREEN_HEIGHT)
			{
				// Bounce off top or bottom wall
				ball->toggleYDir();
			}

			leftPaddle->update();
			rightPaddle->update();
			ball->update();
		break;
	}
}

// run user code 
void PongScene::SubmitPongCode(std::vector<CommandObject*> luaCode)
{
	Util::PrintLine("pong: queue commands");
	std::string str = CommandObject::ConvertBulk(luaCode);

	m_sandbox->executeStringQueued(str);

	currentState = PongState::Execute;
}

void PongScene::onEnter(){ Minigame::onEnter(); };
void PongScene::onExit() { Minigame::onExit(); };
bool PongScene::checkWinCond()
{
	
			
};
void PongScene::loadScene() { Minigame::loadScene(); };
void PongScene::loadWinScr() { Minigame::loadWinScr(); };
void PongScene::loadLoseScr() { Minigame::loadLoseScr(); };
void PongScene::requestUI() { Minigame::requestUI(); };
void PongScene::closeGame() { Minigame::closeGame(); };