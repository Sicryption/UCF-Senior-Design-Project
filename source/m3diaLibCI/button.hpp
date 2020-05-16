#ifndef BUTTONGZLO_H
#define BUTTONGZLO_H

#pragma once
#include <citro2d.h>
#include <string>

#include <3ds.h>
#include <m3dia.hpp>

namespace m3dCI 
{
    class Button: public m3d::Rectangle
	{
		public:
			//Creates a Rectangle to take the form of a button and sets the function to be called OnClick
			Button(int x, int y, int w, int h, m3d::Color color);
			
			//The function which is called when the touch event is touched over the button.
			// Called if a single touch is over the button and the touch happened on the same frame
			void (*OnTouch)(Button*);
			
			//The function which is called when the touch event is released over the button.
			// Called when a touch is released over a button.
			void (*OnRelease)(Button*);
			
			//The function which is called when the touch event is held over the button.
			// Called when a touch is over a button, but the initial touch did not happen on the frame being called
			void (*OnHeld)(Button*);
    };
}


#endif
