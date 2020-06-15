#pragma once

#include "sprite.hpp"
#include "text.hpp"
#include "commandObject.hpp"

#include <citro2d.h>
#include <string>
#include <3ds.h>
#include <m3dia.hpp>
#include <cmath>
#include <vector>

namespace m3dCI 
{
    class CodeEditor: public m3d::Drawable
	{
		private:

			m3d::Rectangle *borderRectangle,
				*innerRectangle;
			std::vector<CommandObject> commands;

			int x, y, borderWidth, w, h;
			
			void refreshCommandList();
		public:
			//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
			virtual ~CodeEditor();

			//Create the CodeEditor.
			/*
			 *  @param px X Coordinate
			 *  @param py Y Coordinate
			 *  @param pw Width of Code Editor
			 *  @param ph Height of Code Editor
			 *  @param p_borderWidth Width of Border
			 *  @returns a Code Editor drawable object
			*/
			CodeEditor(int px, int py, int pw, int ph, int p_borderWidth);
			
			void addCommand(CommandObject co);
			void addCommands(std::vector<CommandObject> commands);

			void selectCommand(CommandObject co);
			void removeCommand(CommandObject co);

			void draw(m3d::RenderContext t_context);
	};
}