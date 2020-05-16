#pragma once

#include "text.hpp"

#include <m3dia.hpp>
#include <string.h>
#include <citro2d.h>

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