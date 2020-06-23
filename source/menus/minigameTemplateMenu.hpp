#pragma once

#include "menu.hpp"

class MinigameTemplateMenu : public Menu
{
	private:
		m3dCI::Button *AddButton = nullptr,
			*RemoveButton = nullptr,
			*closeButton = nullptr;
		m3dCI::CodeEditor* codeEditor = nullptr;
		m3dCI::CommandLister* commandLister = nullptr;

		bool showCommandLister = false;
	public:
		MinigameTemplateMenu(m3d::Screen* screen);
		virtual ~MinigameTemplateMenu();

		void AddCommand(std::string command);

		void AddButton_OnClick();
		void DeleteButton_OnClick();
		void CloseButton_OnClick();
		
		void OnUpdate();
};