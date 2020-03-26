#include <citro2d.h>
#include "console.hpp"

namespace GZLO
{
	Console::Console(std::string defaultText):
		toggleState(false),
		consoleTextBox(defaultText),
		consoleBlackRectangle(0, 0, 1000, 1000, m3d::Color(0,0,0))//black console background needs to be as big as the screen size, 1000, 1000 is good enough for both screens
	{
		consoleTextBox.setFontSize(0.5);
		consoleTextBox.setFontWeight(0.5);
	}

	void Console::ToggleState()
	{
		toggleState = !toggleState;
	}
		
	void Console::draw(m3d::RenderContext t_context)
	{
		if(toggleState)
		{
			consoleBlackRectangle.draw(t_context);
			consoleTextBox.draw(t_context);
		}
	}
	
	void Console::print(std::string text)
	{
		consoleTextBox.appendText(text);
	}
	
	void Console::println(std::string text)
	{
		consoleTextBox.appendText("\n" + text);
	}
}