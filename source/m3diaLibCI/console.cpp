#include "console.hpp"

namespace m3dCI
{
	Console::Console(std::string defaultText):
		toggleState(false),
		consoleTextBox(defaultText),
		consoleBlackRectangle(0, 0, 1000, 1000, m3d::Color(50,100,200))//black console background needs to be as big as the screen size, 1000, 1000 is good enough for both screens
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
		std::string combinedText = consoleTextBox.getText() + text;

		int counter = 0;
		std::size_t foundSize;
		std::string substring = combinedText;

		do
		{
			foundSize = substring.find("\n");

			if (foundSize != std::string::npos)
			{
				std::size_t substringSize = substring.size();
				if (foundSize > substringSize)
					break;

				counter++;
				substring = substring.substr(foundSize + 1, substringSize);
			}
		} while (foundSize != std::string::npos);

		if (counter >= 10)
		{
			//only grab the last 10 new lines.
			int index = counter - 9;//from 0 -> 10

			counter = 0;
			substring = combinedText;
			do
			{
				foundSize = substring.find("\n");

				std::size_t substringSize = substring.size();

				if (counter == index)
				{
					combinedText = substring;
					break;
				}

				if (foundSize > substringSize)
				{
					combinedText = substring;
					break;
				}

				counter++;
				substring = substring.substr(foundSize + 1, substringSize);
			} while (foundSize != std::string::npos);
		}
		
		consoleTextBox.setText(combinedText);
	}
	
	void Console::println(std::string text)
	{
		Console::print("\n" + text);
	}
	
	bool Console::isDrawn()
	{
		return toggleState;
	}
}