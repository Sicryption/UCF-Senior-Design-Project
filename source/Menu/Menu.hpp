#pragma once
#include <vector>
#include <algorithm>
#include "../inputManager.hpp"

#include "MenuItem.hpp"
#include "MenuItems/ButtonMenuItem.hpp"
#include "../util.hpp"

class Menu
{
private:
	std::vector<MenuItem*> menuItems;
	bool draggedLastFrame = false;
	int lastFrameTouchX = -1, lastFrameTouchY = -1;
public:
	Menu();
	~Menu();
	MenuItem* AddItem(MenuItem* item);
	bool ContainsItem(MenuItem* item);
	void RemoveItem(MenuItem* item);
	void OnUpdate();
};
