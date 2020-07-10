#include "Menu.hpp"

Menu::Menu()
{

}

Menu::~Menu()
{
	for (unsigned int i = 0; i < menuItems.size(); i++)
	{
		if (menuItems[i] == nullptr)
			continue;

		Util::PrintLine("Destroying object");
		delete(menuItems[i]);
	}
}

void Menu::OnUpdate()
{
	int touchedThisFrame = Input::btn(m3d::buttons::Touch),
		touchReleasedThisFrame = Input::btnReleased(m3d::buttons::Touch),
		touchx = m3d::touch::getXPosition(),
		touchy = m3d::touch::getYPosition();

	std::vector<MenuItem*> menuItemsClone(menuItems);

	for (unsigned int i = 0; i < menuItemsClone.size(); i++)
	{
		if (menuItemsClone[i] == nullptr || !menuItemsClone[i]->GetActive())
			continue;

		MenuItem* currentItem = menuItemsClone[i];

		//Check for touch event on Button
		if (touchedThisFrame && currentItem->PointIntersection(touchx, touchy))
			currentItem->CallOnTouch();
		else if (touchReleasedThisFrame && currentItem->PointIntersection(lastFrameTouchX, lastFrameTouchY))
			currentItem->CallOnRelease();
		else if (touchReleasedThisFrame && currentItem->PointIntersection(touchx, touchy))
			currentItem->CallOnHeld();
	}

	lastFrameTouchX = touchx;
	lastFrameTouchY = touchy;

	draggedLastFrame = Input::isTouchDragging();
}

MenuItem* Menu::AddItem(MenuItem* item)
{
	if(item != nullptr)
		menuItems.push_back(item);

	return item;
}

bool Menu::ContainsItem(MenuItem* item)
{
	for (unsigned int i = 0; i < menuItems.size(); i++)
		if (menuItems[i] == item)
			return true;

	return false;
}

void Menu::RemoveItem(MenuItem* item)
{
	if (item != nullptr)
		menuItems.erase(std::remove(menuItems.begin(), menuItems.end(), item), menuItems.end());
}