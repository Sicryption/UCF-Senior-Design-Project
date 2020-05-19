#pragma once

#include "m3diaLibCI/console.hpp"

#include <m3dia.hpp>

using namespace m3d;

class Util
{
	private:
	
	//Default console in which all Util.Prints will print ot to
	m3dCI::Console* console;
	
	//The active Applet object
	Applet* app;
	//The active screen object
	Screen* scr;
	
	/*
		This Class is a singleton. 
		Meaning, only one instance of this class may ever exist.
		This allows for all classes to access this object through the use of this instance value.
		An initial instantiation must occur with proper vaules passed into getInstance
		All further attempts to accesss this class can use dummy values for all parameters of getInstance
	*/
	static Util *instance;
	Util(Screen* screen, Applet* applet);
	
	public:
	
	//The function which is called on every game frame.
	void OnUpdate();
	
	static Util* createInstance(Screen* screen, Applet* applet);
	static Util* getInstance();
	
	//Print statements to write to the primary console.
	void PrintLine(std::string text);
	void Print(std::string text);
	
	//Function to check the current Console drawn state
	bool IsConsoleDrawn();
};