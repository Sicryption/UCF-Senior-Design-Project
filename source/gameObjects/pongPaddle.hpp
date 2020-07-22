#include "../gameObjects/gameObject.hpp"
#include "../gameManager.hpp"
#include "../resources.h"
//#include "../scenes/PongScene.hpp"
#include "../gameObjects/pongBall.hpp"

#include <stdio.h>
#include <stdlib.h>

class PongPaddle : public GameObject
{
	/**
		@brief A custom game object used for Pong.
	**/
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
	/**
	* @brief A custom constructor for setting the player paddle's position, scale, angle, and velocity.
	*/
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

	/**
	* @brief A custom constructor for setting the enemy paddle's velocity, position, angle, scale and ball.
	* 
	*/
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
	
	/**
	* @brief Set the paddle's sprite's position and scale.
	*/
    void initialize() {
 	
		sprite = new SpriteMenuItem(*(ResourceManager::getSprite("paddle.png")));
		sprite->setScale(xScale, yScale);
		sprite->setPosition(x, y);
    }

	/**
	* @brief Determine the paddle's velocity.
	*/
    void update() {
		if (ball == nullptr)
		{
			// player paddle moves up or down based on button press (for testing purposes)
			if (m3d::buttons::buttonDown(m3d::buttons::Button::Down)) {
				moveTo(0, velo);
			}

			if (m3d::buttons::buttonDown(m3d::buttons::Button::Up)) {
				moveTo(0, -velo); //
			}
		}
		else
		{
			// calculate displacement between enemy paddle and ball 
			int diff = (getYPosition() + (sprite->GetHeight() / 2)) - (ball->getYPosition() + (ball->getHeight() / 2));

			// enemy paddle moves towards the ball based on its displacement
			if (diff > 0)
				moveTo(0, purposelyFail ? velo: -velo);
			else if (diff < 0)
				moveTo(0, purposelyFail ? -velo : velo);
		}
    }

	/**
	* @brief Calculate the enemy paddle's chance to fail each time the the ball hits its paddle.
	*/
	void ballBouncedOffPaddle()
	{
		chanceToFail += 10;

		int random = rand() % 100;

		purposelyFail = random < chanceToFail;
	}

	/**
	* @brief Display the paddle to the screen using its sprite.
	*/
    void draw() {
        m3d::Screen *screen = GameManager::getScreen();
		sprite->setPosition(x, y);
		screen->drawTop(*sprite);
    }

	/**
	* @brief Adds an offset to the paddle's current position and
	* prevents the paddle from going out of bounds.
	* @param _x The x offset
	* @param _y The y offset
	*/
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

	/**
	* @brief Returns the top right x position of the paddle.
	* @return The top right x position
	*/
	int getXPosition() {
		return sprite->getXPosition();
	}

	/**
	* @brief Returns the top right y position of the paddle.
	* @return The top right y position
	*/
	int getYPosition() {
		return sprite->getYPosition();
	}

	/**
	* @brief Returns the center x position of the paddle.
	* @return The center x position
	*/
	int getCenterX() {
		return sprite->getCenterX();
	}

	/**
	* @brief Returns the center y position of the paddle.
	* @return The y position
	*/
	int getCenterY() {
		return sprite->getCenterY();
	}

	/**
	* @brief Sets the center x and y positions of the paddle.
	* @param t_x The x position
	* @param t_y The y position
	*/
	void setCenter(int t_x, int t_y) {
		sprite->setCenter(t_x, t_y);
	}


	/**
	* @brief Place the paddle in its original position when a goal is scored and
	* and reset the enemy paddle's chance to fail. 
	*/
	void reset()
	{
		x = startX;
		y = startY;

		chanceToFail = 0;
		purposelyFail = false;
	}

	/**
	*  @brief Calls the destructor.
	*/
	void destroy() { this->~PongPaddle(); }

	/**
	* @brief Rotates the paddle to a given degree (unimplemented).
	* @param deg The degree
	*/
	void Rotate(double deg) {};

	/**
	* @brief Returns paddle's bounding box.
	* @return The bounding box
	*/
	BoundingBox getAABB()
	{
		return sprite->getBoundingBox();
	}

	void setPosition(double t_x, double t_y)
	{
		if (t_x < 0)
			t_x = 0;
		if (t_y < 0)
			t_y = 0;
		if (t_x > TOPSCREEN_WIDTH)
			t_x = TOPSCREEN_WIDTH;
		if (t_y + sprite->GetHeight() > TOPSCREEN_HEIGHT)
			t_y = TOPSCREEN_HEIGHT - sprite->GetHeight();

		x = t_x;
		y = t_y;
	}
};
