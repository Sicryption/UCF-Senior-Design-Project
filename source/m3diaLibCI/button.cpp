#include "button.hpp"

//Creates a Rectangle to take the form of a button
m3dCI::Button::Button(int x, int y, int w, int h, m3d::Color color)
: m3d::Shape()
{
	SetDefaults();
	
	rectangle = new m3d::Rectangle(x, y, w, h, color);
	buttonType = Rectangle;
}

//Creates a Circle to take the form of a button
m3dCI::Button::Button(int x, int y, int radius, m3d::Color color)
: m3d::Shape()
{
	SetDefaults();
	
	circle = new m3d::Circle(x, y, radius, color);
	buttonType = Circle;
}

//Determines which shape to draw when called via screen.drawTop
void m3dCI::Button::draw(m3d::RenderContext t_context)
{
	if(buttonType == Rectangle)
		return rectangle->draw(t_context);
	else if(buttonType == Circle)
		return circle->draw(t_context);
}

//Set the default values for any Button to null, then override them as seen fit
void m3dCI::Button::SetDefaults()
{
	rectangle = nullptr;
	circle = nullptr;
	OnTouch = nullptr;
	OnHeld = nullptr;
	OnRelease = nullptr;
}

//Determine if a point intersects the Button
bool m3dCI::Button::PointIntersects(int x, int y)
{
	if(buttonType == Rectangle)
		return getBoundingBox().intersects(m3d::BoundingBox(x, y, 1, 1));
	else if(buttonType == Circle)
	{
		//Circle bounding box is a box based at the center, but does not contain the bottom of the circle.
		//Therefore, a custom implementation was needed.
		
		int xDiff = getXPosition() + (getRadius()) - x;
		int yDiff = getYPosition() + (getRadius()) - y;
		
		if(pow(xDiff, 2) + pow(yDiff, 2) <= pow(getRadius(), 2))
		{
			return true;
		}
	}
		
	return false;
}
		
			
/*

	The following functions are all child functions of Rectangle/Circle objects which are used here.

*/	
void m3dCI::Button::setXPosition (int t_x)
{
	if(buttonType == Rectangle)
		rectangle->setXPosition(t_x);
	else if(buttonType == Circle)
		circle->setXPosition(t_x);
}

int m3dCI::Button::getXPosition ()
{
	if(buttonType == Rectangle)
		return rectangle->getXPosition();
	else if(buttonType == Circle)
		return circle->getXPosition();
		
	return -1;
}

void m3dCI::Button::setYPosition (int t_y)
{
	if(buttonType == Rectangle)
		rectangle->setYPosition(t_y);
	else if(buttonType == Circle)
		circle->setYPosition(t_y);
}

int m3dCI::Button::getYPosition ()
{
	if(buttonType == Rectangle)
		return rectangle->getYPosition();
	else if(buttonType == Circle)
		return circle->getYPosition();
		
	return -1;
}

void m3dCI::Button::setPosition (int t_x, int t_y)
{
	if(buttonType == Rectangle)
		rectangle->setPosition(t_x, t_y);
	else if(buttonType == Circle)
		circle->setPosition(t_x, t_y);
}

void m3dCI::Button::setRadius (int t_radius)
{
	if(buttonType == Circle)
		circle->setRadius(t_radius);
} 

void m3dCI::Button::setWidth (int t_width)
{
	if(buttonType == Rectangle)
		rectangle->setWidth(t_width);
}

int m3dCI::Button::getWidth ()
{
	if(buttonType == Rectangle)
		return rectangle->getWidth();
		
	return -1;
}

void m3dCI::Button::setHeight (int t_height)
{
	if(buttonType == Rectangle)
		rectangle->setHeight(t_height);
}

int m3dCI::Button::getHeight ()
{
	if(buttonType == Rectangle)
		return rectangle->getHeight();
	
	return -1;
}

int m3dCI::Button::getRadius ()
{
	if(buttonType == Circle)
		return circle->getRadius();
	
	return -1;
}

m3d::BoundingBox m3dCI::Button::getBoundingBox ()
{
	if(buttonType == Rectangle)
		return rectangle->getBoundingBox();
	else if(buttonType == Circle)
		return circle->getBoundingBox();
		
	return m3d::BoundingBox(0,0,0,0);
}

void m3dCI::Button::setColor (m3d::Color t_color)
{
	if(buttonType == Rectangle)
		rectangle->setColor(t_color);
	else if(buttonType == Circle)
		circle->setColor(t_color);
}

m3d::Color m3dCI::Button::getColor ()
{
	if(buttonType == Rectangle)
		return rectangle->getColor();
	else if(buttonType == Circle)
		return circle->getColor();
	
	return m3d::Color(0,0,0);
}