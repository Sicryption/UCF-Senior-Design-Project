#pragma once

#include "menu.hpp"

class MinigameTemplateMenu : public Menu
{
	private:
		m3dCI::CodeEditor* codeEditor = nullptr;
	public:
		MinigameTemplateMenu(m3d::Screen* screen);
		virtual ~MinigameTemplateMenu();
		
		void OnUpdate();
};