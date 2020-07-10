#pragma once
#include <functional>

class MenuItem
{
protected:
	int x, y, layer;
	bool isActive = true;
	std::function<void()> OnHeld = nullptr, OnTouch = nullptr, OnRelease = nullptr;
public:
	MenuItem(int px, int py, int player)
	{
		x = px;
		y = py;
		layer = player;
	}

	virtual ~MenuItem() { }

	void SetOnHeld(std::function<void()> onHeld) { OnHeld = onHeld; };
	void SetOnTouch(std::function<void()> onTouch) { OnTouch = onTouch; };
	void SetOnRelease(std::function<void()> onRelease) { OnRelease = onRelease; };

	void CallOnHeld() { if(OnHeld != nullptr) OnHeld(); }
	void CallOnTouch() { if (OnTouch != nullptr)  OnTouch(); }
	void CallOnRelease() { if (OnRelease != nullptr) OnRelease(); }

	void SetActive(bool state) { isActive = state; }
	bool GetActive() { return isActive; }

	virtual m3d::BoundingBox getBoundingBox() { return m3d::BoundingBox(x, y, 0, 0); };
	virtual bool PointIntersection(int x, int y) { return false; };
};