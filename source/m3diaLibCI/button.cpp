#include "button.hpp"
#include <m3dia.hpp>

//Creates a Rectangle to take the form of a button and sets the function to be called OnClick
m3dCI::Button::Button(int x, int y, int w, int h, m3d::Color color)
: m3d::Rectangle(x, y, w, h, color)
{
	OnTouch = nullptr;
	OnHeld = nullptr;
	OnRelease = nullptr;
}