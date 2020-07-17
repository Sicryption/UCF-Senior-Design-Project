#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"
//#include "../scenes/PongScene.hpp"
#include "../gameObjects/pongBall.hpp"

#include <stdio.h>
#include <stdlib.h>

class PongPaddle : public GameObject
{

private:
    m3d::Color *color;
    m3d::Rectangle *PongRec;
    m3d::BoundingBox *paddleBox;
	SpriteMenuItem *sprite;
	PongBall* ball = nullptr; 
	int velo; 

	int chanceToFail = 0;
	bool purposelyFail = false;

	int startX, startY;

public:
	PongPaddle(int _x, int _y)
	{
		x = _x;
		y = _y;
		startX = _x;
		startY = _y;
		xScale = 0.5;
		yScale = 2;
		angle = 0;

		velo = 3;
	}

	PongPaddle(int _x, int _y, PongBall *_ball)
	{
		x = _x;
		y = _y;
		startX = _x;
		startY = _y;
		xScale = 0.5;
		yScale = 2;
		angle = 0;

		velo = 3;

		ball = _ball;
	}
	

    void initialize() {
        //color = new m3d::Color(0,100,0);
        //PongRec = new m3d::Rectangle((int)x,(int)y,50,10,*color);
        //paddlebox = PongRec->getBoundingBox();
		
		sprite = new SpriteMenuItem(*(ResourceManager::getSprite("paddle.png")));
		sprite->setScale(xScale, yScale);
		sprite->setPosition(x, y);
    }

    void update() {
		if (ball == nullptr)
		{
			// player paddle moves up or down based on button press
			if (m3d::buttons::buttonDown(m3d::buttons::Button::Down)) {
				//moveTo(x, 1 * GameManager::getDeltaTime());
				moveTo(0, velo);
			}

			if (m3d::buttons::buttonDown(m3d::buttons::Button::Up)) {
				//moveTo(x, -1 * GameManager::getDeltaTime());
				moveTo(0, -velo); //
			}
		}
		else
		{
			int diff = (getYPosition() + (sprite->GetHeight() / 2)) - (ball->getYPosition() + (ball->getHeight() / 2));

			// enemy paddle moves towards the ball based on its displacement
			if (diff > 0)
				moveTo(0, purposelyFail ? velo: -velo);
			else if (diff < 0)
				moveTo(0, purposelyFail ? -velo : velo);
		}
    }

	void ballBouncedOffPaddle()
	{
		chanceToFail += 10;

		int random = rand() % 100;

		purposelyFail = random < chanceToFail;
	}

    void draw() {
        m3d::Screen *screen = GameManager::getScreen();
        //screen->drawTop(*PongRec);
		sprite->setPosition(x, y);
		screen->drawTop(*sprite);
    }

    void moveTo(double _x, double _y) {
		y += _y;
		x += _x;

		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if (x > TOPSCREEN_WIDTH)
			x = TOPSCREEN_WIDTH;
		if (y + sprite->GetHeight() > TOPSCREEN_HEIGHT)
			y = TOPSCREEN_HEIGHT - sprite->GetHeight();
    }

	int getXPosition() {
		return sprite->getXPosition();
	}

	int getYPosition() {
		return sprite->getYPosition();
	}

	int getCenterX() {
		return sprite->getCenterX();
	}

	int getCenterY() {
		return sprite->getCenterY();
	}

	void setCenter(int t_x, int t_y) {
		sprite->setCenter(t_x, t_y);
	}

	float getXScale() {
		return sprite->getXScale();
	}


	float getYScale() {
		return sprite->getYScale();
	}

	void reset()
	{
		x = startX;
		y = startY;

		chanceToFail = 0;
		purposelyFail = false;
	}


	void destroy() { this->~PongPaddle(); }

	void Rotate(double deg) {};

	BoundingBox getAABB()
	{
		return sprite->getBoundingBox();
	}
};
