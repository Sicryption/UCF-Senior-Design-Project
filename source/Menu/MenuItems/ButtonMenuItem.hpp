#pragma once
#include "../../m3diaLibCI/sprite.hpp"
#include "../../m3diaLibCI/text.hpp"
#include "../MenuItem.hpp"
#include "../../m3diaLibCI/button.hpp"

class ButtonMenuItem : public m3dCI::Button, public MenuItem
{
public:
	//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
	~ButtonMenuItem();

	//Creates a Rectangle to take the form of a button
	ButtonMenuItem(int px, int py, int pw, int ph, m3d::Color p_innerColor, m3d::Color p_borderColor, int p_borderWidth);

	//Creates a Circle to take the form of a button
	ButtonMenuItem(int px, int py, int pr, m3d::Color p_innerColor, m3d::Color p_borderColor, int p_borderWidth);

	ButtonMenuItem(int px, int py, m3d::Texture& t_texture);
	ButtonMenuItem(int px, int py, m3dCI::Sprite* sprite);

	bool PointIntersection(int px, int py);

	void SetActive(bool state);
};