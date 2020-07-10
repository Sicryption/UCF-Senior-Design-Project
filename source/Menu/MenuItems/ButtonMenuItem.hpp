#pragma once
#include "../../m3diaLibCI/sprite.hpp"
#include "../../m3diaLibCI/text.hpp"
#include "../MenuItem.hpp"



class RectangleMenuItem : public m3d::Drawable, public MenuItem
{
public:
	m3d::Rectangle* rect;
	RectangleMenuItem(int x, int y, int w, int h, m3d::Color color) : MenuItem(x, y, 0)
	{
		rect = new m3d::Rectangle(x, y, w, h, color);
	}

	void draw(m3d::RenderContext t_context)
	{
		rect->draw(t_context);
	}
};


class ButtonMenuItem : public m3d::Drawable, public MenuItem
{
	enum ButtonType { Rectangle, Circle, SpriteObject };

private:
	ButtonType buttonType;

	m3d::Rectangle* innerRectangle = nullptr;
	m3d::Rectangle* outerRectangle = nullptr;
	m3d::Circle* innerCircle = nullptr;
	m3d::Circle* outerCircle = nullptr;

	m3dCI::Sprite* sprite = nullptr;

	m3dCI::Text* text = nullptr;

	m3d::Color innerColor, outerColor, *disabledColor = nullptr;

	int borderWidth, w, h, r;

	bool enabled = true;

	void UpdateShape();
public:
	//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
	~ButtonMenuItem();

	//Creates a Rectangle to take the form of a button
	ButtonMenuItem(int px, int py, int pw, int ph, m3d::Color p_innerColor, m3d::Color p_borderColor, int p_borderWidth);

	//Creates a Circle to take the form of a button
	ButtonMenuItem(int px, int py, int pr, m3d::Color p_innerColor, m3d::Color p_borderColor, int p_borderWidth);

	ButtonMenuItem(int px, int py, m3d::Texture& t_texture);
	ButtonMenuItem(int px, int py, m3dCI::Sprite* sprite);

	void draw(m3d::RenderContext t_context);
	bool PointIntersection(int px, int py);

	void SetText(std::string txt);
	void SetTextColor(m3d::Color color);

	void setXPosition(int t_x);
	int getXPosition();
	void setYPosition(int t_y);
	int getYPosition();
	void setPosition(int t_x, int t_y);
	void setRadius(int t_radius);
	int getRadius();
	void setWidth(int t_width);
	int getWidth();
	void setHeight(int t_height);
	int getHeight();
	m3d::BoundingBox getBoundingBox();
	void setInnerColor(m3d::Color t_color);
	void setBorderColor(m3d::Color t_color);
	m3d::Color getInnerColor();
	m3d::Color getBorderColor();
	void setScale(float x, float y);
};