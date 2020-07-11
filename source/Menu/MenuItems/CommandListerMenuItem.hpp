#pragma once
#include "../../m3diaLibCI/commandLister.hpp"
#include "../MenuItem.hpp"

class CommandListerMenuItem : public m3dCI::CommandLister, public MenuItem
{
private:
public:
	CommandListerMenuItem(Minigame* minigame);

	//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
	~CommandListerMenuItem();

	bool PointIntersection(int px, int py);
};