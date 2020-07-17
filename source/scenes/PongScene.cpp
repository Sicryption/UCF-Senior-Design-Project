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
	
	// initialize popup 
	popup = new SpriteMenuItem(*(ResourceManager::getSprite("menu_popup.png")));
	popup->setPosition(80, 20);

	wallpaper->setCenter(0, 0);
	wallpaper->setScale(1, 1);

	// initialize game objects
	ball = new PongBall();
	ball->initialize();

	leftPaddle = new PongPaddle(20, 90);
	leftPaddle->initialize();
	//leftPaddle->setCenter(10, 135); // 20, 135
	//leftPaddle->setPosition(0, 0);

	rightPaddle = new PongPaddle(380, 90, ball);
	rightPaddle->initialize();
	//rightPaddle->setCenter(5, 95);
}

// TODO:
// - keep track of game score
// - integrate api commands with update() and submit pong code()
// - add win and lose conditions
// - reset game objects

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

	//int halfLen = leftPaddle->getCenterY() - leftPaddle->getYPosition(), halfWidth = leftPaddle->getXPosition() - leftPaddle->getCenterX();

	util->PrintLine("demo");

	if (leftPaddle->getCenterY() - (leftPaddle->getCenterY() - leftPaddle->getYPosition()) <= ball->getCenterY()
		&& leftPaddle->getCenterY() + (leftPaddle->getCenterY() - leftPaddle->getYPosition()) >= ball->getCenterY()
		&& leftPaddle->getCenterX() - (leftPaddle->getXPosition() - leftPaddle->getCenterX()) <= ball->getCenterX()
		&& leftPaddle->getCenterX() + (leftPaddle->getXPosition() - leftPaddle->getCenterX()) >= ball->getCenterX())

	{
		ball->toggleXDir();
	}

	

	/*
	if (leftPaddle->getCenterY() - (halfLen) <= ball->getYPosition()
		&& leftPaddle->getCenterY() + (halfLen) >= ball->getYPosition()
		&& leftPaddle->getCenterX() - (halfWidth) <= ball->getXPosition()
		&& leftPaddle->getCenterX() + (halfWidth) >= ball->getXPosition())
	{
		ball->toggleXDir();
	}
	*/

	/*
	if (leftPaddle->getCenterY() - (halfLen) <= ball->getCenterY()
		&& leftPaddle->getCenterY() + (halfLen) >= ball->getCenterY()
		&& leftPaddle->getCenterX() - (halfWidth) <= ball->getCenterX()
		&& leftPaddle->getCenterX() + (halfWidth) >= ball->getCenterX())
	{
		ball->toggleXDir();
	}
	*/

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
	

	
	
	


}
		
void PongScene::load(){ Minigame::load(); }; //any data files
        
void PongScene::unload(){ Minigame::unload(); };
        
void PongScene::update()
{
	Minigame::update();

	
};

void PongScene::SubmitPongCode(std::vector<CommandObject*> luaCode)
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