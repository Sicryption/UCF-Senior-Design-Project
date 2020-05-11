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
			Button(int x, int y, int w, int h, m3d::Color color, void (*function)(Button*));
			
			//The function which is called when the button is clicked.
			void (*OnClick)(Button*);
    };
}


#endif
