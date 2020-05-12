#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h>

#include <m3dia.hpp>
#include "m3diaLibCI/console.hpp"
#include "m3diaLibCI/text.hpp"

#include "lua/lua.hpp"

#include "sandbox.h"

using namespace m3d;



int main(int argc, char* argv[])
{
    Applet app;
    Screen scr;
    m3dCI::Text exitText("Press Start and Select to Exit\nPress L and R to open/close Console.");
	exitText.setFontSize(0.5);
	exitText.setFontWeight(0.5);
	m3dCI::Console console("Press A or B to write some text.");
	
    // Create Sandbox
    LuaSandbox* sandbox = new LuaSandbox();
    

	// Main loop
    while (app.isRunning())
	{
		// Your code goes here
		if (buttonPressed(buttons::Button::Start)
			&& buttonPressed(buttons::Button::Select))
			app.exit();
			
		if (buttonPressed(buttons::Button::L)
			&& buttonPressed(buttons::Button::R))
			console.ToggleState();
				
		if(console.isDrawn())
		{
			//Console only actions
			if (buttonPressed(buttons::Button::A))
				console.print("Some Text.");
			
			if (buttonPressed(buttons::Button::B))
				console.println("New line!");
            

		}
		else
		{
			//Actions that require the console to not be shown
		}
		
		scr.drawTop(exitText, RenderContext::Mode::Flat);
		scr.drawTop(console, RenderContext::Mode::Flat);
		
		scr.render();
	}
	
	return 0;
}
