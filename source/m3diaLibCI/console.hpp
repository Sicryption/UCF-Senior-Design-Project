#ifndef CONSOLE_H
#define CONSOLE_H

#pragma once

#include <m3dia.hpp>
#include <string.h>
#include "text.hpp"

namespace m3dCI
{
	class Console : public m3d::Drawable
	{
		private:
			bool toggleState;
			m3dCI::Text consoleTextBox;
			m3d::Rectangle consoleBlackRectangle;
		public:
			Console(std::string defaultText);
			void ToggleState();
			void print(std::string text);
			void println(std::string text);
			void draw(m3d::RenderContext t_context);
			bool isDrawn();
	};
} 
#endif