#include "PongScene.hpp"
#include "MinigameSelectScene.hpp"

Util* util = Util::getInstance();

PongScene::PongScene()
{
	
}

PongScene::~PongScene()
{

}

void PongScene::initialize(){
	Minigame::initialize();

	// initalize the background
	wallpaper = new SpriteMenuItem(*(ResourceManager::getSprite("pong1.png")));
	//  Initialize popup BG
	popup = new SpriteMenuItem(*(ResourceManager::getSprite("menu_popup.png")));
	popup->setPosition(80, 20);
	//wallpaper->setTexture(*texture);
	wallpaper->setCenter(0, 0);
	wallpaper->setScale(1, 1);


	//runnerID = addObject(runner);

	//setObjectName("runner", runnerID);

	// initialize game objects
	ball = new PongBall();
	ball->initialize();

	leftPaddle = new PongPaddle(20, 90);
	leftPaddle->initialize();
	//leftPaddle->setCenter(5, 95);

	rightPaddle = new PongPaddle(380, 90, ball);
	//rightPaddle = new PongPaddle(390, 90);
	rightPaddle->initialize();
	//rightPaddle->setCenter(5, 95);
}

void PongScene::draw(){
	Minigame::draw();

	m3d::Screen *screen = GameManager::getScreen();

	wallpaper->setPosition(0, 0);
	screen->drawTop(*wallpaper);

	ball->draw();
	ball->update();

	// player paddle moves up or down based on button press
	if (m3d::buttons::buttonDown(m3d::buttons::Button::Down)) {
		//moveTo(x, 1 * GameManager::getDeltaTime());
		leftPaddle->moveTo(0, 2);
	}

	if (m3d::buttons::buttonDown(m3d::buttons::Button::Up)) {
		//moveTo(x, -1 * GameManager::getDeltaTime());
		leftPaddle->moveTo(0, -2); //
	}


	leftPaddle->draw();

	//rightPaddle->draw();
	//rightPaddle->update();

	int halfLen = leftPaddle->getCenterY() - leftPaddle->getYPosition(), halfWidth = leftPaddle->getXPosition() - leftPaddle->getCenterX();

	util->PrintLine("demo");
	

	/*
	if (leftPaddle->getCenterY() - (halfLen) <= ball->getYPosition()
		&& leftPaddle->getCenterY() + (halfLen) >= ball->getYPosition()
		&& leftPaddle->getCenterX() - (halfWidth) <= ball->getXPosition()
		&& leftPaddle->getCenterX() + (halfWidth) >= ball->getXPosition())
	{
		ball->toggleXDir();
	}
	*/

	if (leftPaddle->getCenterY() - (halfLen) <= ball->getCenterY()
		&& leftPaddle->getCenterY() + (halfLen) >= ball->getCenterY()
		&& leftPaddle->getCenterX() - (halfWidth) <= ball->getCenterX()
		&& leftPaddle->getCenterX() + (halfWidth) >= ball->getCenterX())
	{
		ball->toggleXDir();
	}

	// switchs ball's direction on collision with the enemy paddle 
	// check the ball enters into the paddle's x and if the ball is within the scope of the paddle 
	/*
	if (leftPaddle->getCenterY() - (leftPaddle->getCenterY() - leftPaddle->getYPosition()) <= ball->getYPosition()
		&& leftPaddle->getCenterY() + (leftPaddle->getCenterY() - leftPaddle->getYPosition()) >= ball->getYPosition()
		&& leftPaddle->getCenterX() - (leftPaddle->getXPosition() - leftPaddle->getCenterX()) <= ball->getXPosition()
		&& leftPaddle->getCenterX() + (leftPaddle->getXPosition() - leftPaddle->getCenterX()) >= ball->getXPosition())
	{
		ball->toggleXDir();
	}
	*/

	
	/*
	if (leftPaddle->getCenterY() - (leftPaddle->getCenterY() - leftPaddle->getYPosition()) <= ball->getCenterY()
		&& leftPaddle->getCenterY() + (leftPaddle->getCenterY() - leftPaddle->getYPosition()) >= ball->getCenterY()
		&& leftPaddle->getCenterX() - (leftPaddle->getXPosition() - leftPaddle->getCenterX()) <= ball->getCenterX()
		&& leftPaddle->getCenterX() + (leftPaddle->getXPosition() - leftPaddle->getCenterX()) >= ball->getCenterX())

	{
		ball->toggleXDir();
	}
	*/


}
		
void PongScene::load(){ Minigame::load(); }; //any data files
        
void PongScene::unload(){ Minigame::unload(); };
        
void PongScene::update()
{
	Minigame::update();

	
};

void PongScene::SubmitMazeCode(std::vector<CommandObject*> luaCode)
{
	
  
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