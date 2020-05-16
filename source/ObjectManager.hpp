#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#pragma once

#include <m3dia.hpp>
#include <vector>
#include "m3diaLibCI/button.hpp"
#include "util.hpp"

using namespace m3d;

class ObjectManager
{
	private:
		//The active Screen object
		Screen* scr;
		//The Utility manager
		Util* util;
		int lastFrameTouchX, lastFrameTouchY;
		//Array of all active buttons
		std::vector<m3dCI::Button*> arr;
		
		/*
			This Class is a singleton. 
			Meaning, only one instance of this class may ever exist.
			This allows for all classes to access this object through the use of this instance value.
			An initial instantiation must occur with proper vaules passed into getInstance
			All further attempts to accesss this class can use dummy values for all parameters of getInstance
		*/
		static ObjectManager *instance;
		ObjectManager(Screen* screen);
	public:
		static ObjectManager* getInstance(Screen* screen);
		
		//The function which is called on every game frame.
		void OnUpdate();
		
		//Button creation. Adds button to array of active buttons.
		m3dCI::Button* CreateButton(int x, int y, int w, int h, m3d::Color color);
};
#endif