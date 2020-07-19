#pragma once

#include <citro2d.h>
#include <string>
#include <3ds.h>
#include <m3dia.hpp>
#include <cmath>
#include <vector>
#include <m3dia.hpp>

class CommandObject;

namespace m3dCI 
{
    class CodeEditor: public m3d::Drawable
	{
		protected:
			m3d::Rectangle *borderRectangle,
				*innerRectangle;
			std::vector<CommandObject*> commands;

			CommandObject* currentSelectedCommand = nullptr;
			int x, xShift = 0, y, borderWidth, w, h;

			double scrollY = 0;
			double thisScrollChange = 0;
			
			void refreshCommandList();

			int GetSelectedCommandIndex();

			void SelectCommand(int index);

			bool isPointInside(int px, int py);
			void InternalSelectCommand(int px, int py);

			void InternalDoDrag(int u, int v);
			void InternalDragComplete();

		public:
			//Create the CodeEditor.
			/*
			 *  @param px X Coordinate
			 *  @param py Y Coordinate
			 *  @param pw Width of Code Editor
			 *  @param ph Height of Code Editor
			 *  @param p_borderWidth Width of Border
			 *  @returns a Code Editor drawable object
			*/
			CodeEditor(int px, int pw, int p_borderWidth);

			//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
			virtual ~CodeEditor();
			
			//need a way to insert at specified line
			void addCommand(CommandObject* command, int position = -1);
			void removeCommand(int position = -1);

			void replaceCommand(CommandObject* current, CommandObject* newCommand);

			void ClearCommands();

			bool canAdd();
			bool canEdit();
			bool canRemove();
			std::vector<CommandObject*> GetCommands();
			CommandObject* getSelectedObject();

			bool IsBlankCommandSelected();

			void draw(m3d::RenderContext t_context);

			void ShiftToTop();
			void ShiftToBottom();
	};
}