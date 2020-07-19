#pragma once
#include <m3dia.hpp>
#include "../MenuItem.hpp"

class RectangleMenuItem : public m3d::Rectangle, public MenuItem
{
private:

public:
	RectangleMenuItem(int x, int y, int w, int h, m3d::Color color);

	//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
	~RectangleMenuItem();

	bool PointIntersection(int px, int py);
};