#pragma once
#include "../../m3diaLibCI/sprite.hpp"
#include "../MenuItem.hpp"

class SpriteMenuItem : public m3dCI::Sprite, public MenuItem
{
private:

public:
	SpriteMenuItem();
	SpriteMenuItem(const std::string& t_spriteSheet, int t_imageId);
	SpriteMenuItem(Sprite& sprite);

	//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
	~SpriteMenuItem();

	bool PointIntersection(int px, int py);
};