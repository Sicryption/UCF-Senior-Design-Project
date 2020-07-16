#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"
//#include "../scenes/PongScene.hpp"
#include "../gameObjects/pongBall.hpp"

class PongPaddle : public GameObject
{

private:
    m3d::Color *color;
    m3d::Rectangle *PongRec;
    m3d::BoundingBox *paddleBox;
	SpriteMenuItem *sprite;
	PongBall* ball; 
	int velo; 

public:
	PongPaddle(int _x, int _y)
	{
		x = _x;
		y = _y;
		xScale = 3.5;
		yScale = .5;
		angle = 0;
	}

	PongPaddle(int _x, int _y, PongBall *_ball)
	{
		x = _x;
		y = _y;
		xScale = 3.5;
		yScale = .5;
		angle = 0;
		ball = _ball; 
		velo = 1;
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
		int diff = getYPosition() - ball->getYPosition();

		// enemy paddle moves towards the ball based on its displacement
		if (diff > 0)
		{
			moveTo(0, -velo);
		}
		else if (diff < 0)
		{
			moveTo(0, velo);
		}
		
	
    }

    void draw() {
        m3d::Screen *screen = GameManager::getScreen();
        //screen->drawTop(*PongRec);
		sprite->setPosition(x, y);
		screen->drawTop(*sprite);
    }

    void moveTo(double _x, double _y) {
        //PongRec->setYPosition(y + (int)(_y + 0.5));
		y += _y;
		x += _x;

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
		
	}


	void destroy() { this->~PongPaddle(); }

	void Rotate(double deg) {};



};
