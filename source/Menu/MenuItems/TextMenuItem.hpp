#pragma once
#include "../../m3diaLibCI/text.hpp"
#include "../MenuItem.hpp"

class TextMenuItem : public m3dCI::Text, public MenuItem
{
private:

public:
	TextMenuItem(std::string str, m3d::Color color = m3d::Color(255, 255, 255));

	//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
	~TextMenuItem();

	bool PointIntersection(int px, int py);
};