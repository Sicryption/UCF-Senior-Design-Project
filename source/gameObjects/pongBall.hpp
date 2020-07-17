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
		speed = 1.5;
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

		// ball goes out of x bounds, a goal has been scored
		if (x <= 0 || x >= 380)
		{
			//toggleXDir();
			reset();
		}

		// ball goes out of y bounds, a collision with the wall occurs 
		if (y >= 240 || y <= 0)
		{
			toggleYDir();
		}
    };

	// reset ball's position when a goal is scored 
	void reset()
	{
		x = 180;
		y = 110;
		//PongBall();
		//initialize();

	}

    void draw()
    {
        m3d::Screen *screen = GameManager::getScreen();

		sprite->setPosition(x, y);
        screen->drawTop(*sprite);


    }

	void setPosition(int t_x, int t_y) {
		sprite->setPosition(t_x, t_y);
	}

	int getXPosition() {
		return sprite->getXPosition();
	}

	int getYPosition() {
		return sprite->getYPosition();
	}

	void setCenter(int t_x, int t_y) {
		sprite->setCenter(t_x, t_y);
	}

	int getCenterX() {
		return sprite->getCenterX();
	}

	int getCenterY() {
		return sprite->getCenterY();
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
  
};
