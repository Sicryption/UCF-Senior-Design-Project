#include "../gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"


class PongBall : public GameObject
{

private:
	SpriteMenuItem *sprite;
	int dirX, dirY, speed; 
	

public:
	PongBall()
    {
        x = 180;
        y = 110;
        xScale = 1;
        yScale = 1;
        angle = 0;
		speed = 2;
		dirX = -1;
		dirY = 1; 
    }

    ~PongBall()
    {

    }

    void initialize()
    {
        sprite = new SpriteMenuItem(*(ResourceManager::getSprite("ball.png")));
        sprite->setScale(xScale,yScale);
        sprite->setPosition(x,y);
    }

    void update() {

		moveTo(speed * dirX, speed * dirY);

    };

	// reset ball's position when a goal is scored 
	void reset()
	{
		x = 180;
		y = 110;
	}

    void draw()
    {
        m3d::Screen *screen = GameManager::getScreen();

		sprite->setPosition(x, y);
        screen->drawTop(*sprite);


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


    void destroy(){ this->~PongBall(); }
    void moveTo(double _x,double _y)
    {
		y += _y;
		x += _x;
  
    };
    void Rotate(double deg){};

	void toggleXDir()
	{
		dirX *= -1;
	}

	void toggleYDir()
	{
		dirY *= -1;
	}

	void SetDirection(int directionX, int directionY)
	{
		if (directionX != 0)
		{
			dirX = directionX;
		}
		if (directionY != 0)
		{
			dirY = directionY;
		}
	}

	BoundingBox getAABB()
	{
		return sprite->getBoundingBox();
	}

	int getWidth()
	{
		return sprite->GetWidth();
	}

	int getHeight()
	{
		return sprite->GetHeight();
	}
};
