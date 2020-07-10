#pragma once

#include "sprite.hpp"
#include "text.hpp"
#include "button.hpp"
#include "commandListerItem.hpp"
#include "../resources.h"

#include <citro2d.h>
#include <string>
#include <3ds.h>
#include <m3dia.hpp>
#include <cmath>
#include <vector>

#define TOPSCREEN_WIDTH 400
#define BOTTOMSCREEN_WIDTH 320
#define TOPSCREEN_HEIGHT 240
#define BOTTOMSCREEN_HEIGHT 240

#define NUM_TABS 5
#define NUM_COMMANDS_PER_TAB 8

#define SHAPE_INDEX 0
#define COLOR_INDEX 1
#define OBJECT_MANIPULATION 2
#define VAR_STATEMENTS 3
#define CONTROL_STATEMENTS 4

class Minigame;
class CommandObject;

using namespace std;

namespace m3dCI 
{
    class CommandLister : public m3d::Drawable
	{
		private:
			Minigame* minigame;

			pair<string, function<void()>> listOfCommandsByTab[NUM_TABS][NUM_COMMANDS_PER_TAB];

			m3d::Rectangle *backgroundRectangle = nullptr;
			std::vector<m3dCI::Sprite*> tabs;
			std::vector<std::vector<commandListerItem*>> commands;

			int currentlySelectedTab = -1;
			commandListerItem* currentSelectedCommand = nullptr;

			int x, y, w, h;

			std::string getTabSpriteStringID(int index, bool selected);
			m3dCI::Sprite* getTabSprite(int index, bool selected);

			void CreateTabCommandObjects(int index);

			void SelectTab(int tabIndex);
		protected:
			int getCurrentlySelectedTab();
			void SelectTab(int px, int py);
			void SelectCommandObject(int px, int py);

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
			CommandLister(Minigame* minigame);

			//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
			virtual ~CommandLister();

			void draw(m3d::RenderContext t_context);
	};
}