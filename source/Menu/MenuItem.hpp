#pragma once
#include <functional>

class MenuItem
{
protected:
	int layer;
	bool isActive = true;
	std::function<void(int, int)> OnHeldEnter = nullptr, OnHeld = nullptr, OnHeldLeave = nullptr, OnTouch = nullptr, OnRelease = nullptr, OnDrag = nullptr;
	std::function<void()> OnDragComplete = nullptr;
public:
	MenuItem(int player = 0)
	{
		layer = player;
	}

	virtual ~MenuItem() { }

	void SetOnHeld(std::function<void(int, int)> onHeld) { OnHeld = onHeld; };
	void SetOnHeldEnter(std::function<void(int, int)> onHeldEnter) { OnHeldEnter = onHeldEnter; };
	void SetOnHeldLeave(std::function<void(int, int)> onHeldLeave) { OnHeldLeave = onHeldLeave; };
	void SetOnTouch(std::function<void(int, int)> onTouch) { OnTouch = onTouch; };
	void SetOnRelease(std::function<void(int, int)> onRelease) { OnRelease = onRelease; };
	void SetOnDrag(std::function<void(int, int)> onDrag) { OnDrag = onDrag; };
	void SetOnDragComplete(std::function<void()> onDragComplete) { OnDragComplete = onDragComplete; };

	void CallOnHeld(int x, int y) { if (OnHeld != nullptr) OnHeld(x, y); }
	void CallOnHeldEnter(int x, int y) { if (OnHeldEnter != nullptr) OnHeldEnter(x, y); }
	void CallOnHeldLeave(int x, int y) { if (OnHeldLeave != nullptr) OnHeldLeave(x, y); }
	void CallOnTouch(int x, int y) { if (OnTouch != nullptr)  OnTouch(x, y); }
	void CallOnRelease(int x, int y) { if (OnRelease != nullptr) OnRelease(x, y); }
	void CallOnDrag(int x, int y) { if (OnDrag != nullptr) OnDrag(x, y); }
	void CallOnDragComplete() { if (OnDragComplete != nullptr) OnDragComplete(); }

	virtual void SetActive(bool state) { isActive = state; }
	bool GetActive() { return isActive; }

	virtual bool PointIntersection(int x, int y) { return false; };
};