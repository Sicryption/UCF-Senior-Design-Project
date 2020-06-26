#pragma once

#include "menu.hpp"

class MinigameTemplateMenu : public Menu
{
	private:
		m3dCI::Button *AddButton = nullptr,
			*RemoveButton = nullptr,
			*closeButton = nullptr,
			*submitButton = nullptr;
		m3dCI::CodeEditor* codeEditor = nullptr;
		m3dCI::CommandLister* commandLister = nullptr;

		std::function<void(std::vector<CommandObject*>)> submitFunction = nullptr;

		bool showCommandLister = false;
	public:
		MinigameTemplateMenu(m3d::Screen* screen);
		virtual ~MinigameTemplateMenu();

		void AddCommand(CommandObject* command);
		void ClearCommands();

		void SetSubmitFunction(std::function<void(std::vector<CommandObject*>)> callbackFunction);

		void AddButton_OnClick();
		void DeleteButton_OnClick();
		void SubmitButton_OnClick();
		void CloseButton_OnClick();
		
		void OnUpdate();
};