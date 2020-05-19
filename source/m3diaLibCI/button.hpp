#pragma once

#include <citro2d.h>
#include <string>
#include <3ds.h>
#include <m3dia.hpp>
#include <cmath>

namespace m3dCI 
{
	enum ButtonType { Rectangle, Circle };
	
    class Button: public m3d::Shape
	{
		private:
			ButtonType buttonType;
			
			m3d::Rectangle* rectangle;
			m3d::Circle* circle;
			
			void SetDefaults();
		public:
			//Creates a Rectangle to take the form of a button
			Button(int x, int y, int w, int h, m3d::Color color);
			
			//Creates a Circle to take the form of a button
			Button(int x, int y, int radius, m3d::Color color);
			
			//The function which is called when the touch event is touched over the button.
			// Called if a single touch is over the button and the touch happened on the same frame
			void (*OnTouch)(Button*);
			
			//The function which is called when the touch event is released over the button.
			// Called when a touch is released over a button.
			void (*OnRelease)(Button*);
			
			//The function which is called when the touch event is held over the button.
			// Called when a touch is over a button, but the initial touch did not happen on the frame being called
			void (*OnHeld)(Button*);
			
			//Check if a point intersects with the button
			bool PointIntersects(int x, int y);
			
			//How to draw the button object
			void draw(m3d::RenderContext t_context);
			
			
			
			/*
			
				The following functions are all child functions of Rectangle/Circle objects which are used here.
			
			*/
			void setXPosition (int t_x);			 
			int getXPosition ();			 
			void setYPosition (int t_y);			 
			int getYPosition ();			 
			void setPosition (int t_x, int t_y);
			void setRadius (int t_radius); 
			void setWidth (int t_width);
			int getWidth ();
			void setHeight (int t_height);
			int getHeight ();
			int getRadius ();			 
			m3d::BoundingBox getBoundingBox ();	 
			void setColor (m3d::Color t_color);			 
			m3d::Color getColor ();
	};
}