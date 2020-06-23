#include "minigameTemplateMenu.hpp"

MinigameTemplateMenu::MinigameTemplateMenu(m3d::Screen* screen) :
	Menu(screen)
{
	int margin = 5;
	ResourceManager::loadSpritesheet("gfx/menuSprites");

	codeEditor = om->CreateCodeEditor(margin, (BOTTOMSCREEN_WIDTH * 0.75) - (margin * 2), 1);

	codeEditor->addCommand("Circle MyCircle");
	codeEditor->addCommand("Red");
	codeEditor->addCommand("Left 5");
	codeEditor->addCommand("Right 15");
	codeEditor->SetActive(true);

	int buttonWidth = BOTTOMSCREEN_WIDTH * 0.25 - (margin * 2);

	AddButton = om->CreateButton(BOTTOMSCREEN_WIDTH * 0.75 + margin, margin, buttonWidth, buttonWidth, m3d::Color(255,255,255), m3d::Color(0, 0, 0), 1);
	AddButton->SetText("ADD");
	AddButton->OnRelease = [this]() { this->AddButton_OnClick(); };
	
	RemoveButton = om->CreateButton(BOTTOMSCREEN_WIDTH * 0.75 + margin, margin + buttonWidth, buttonWidth, buttonWidth, m3d::Color(255, 255, 255), m3d::Color(0, 0, 0), 1);
	RemoveButton->SetText("DEL");
	RemoveButton->OnRelease = [this]() { this->DeleteButton_OnClick(); };

	closeButton = om->CreateButton(48 + BOTTOMSCREEN_WIDTH * 0.5, 0, ResourceManager::getSprite("tabClose.png"));
	closeButton->OnRelease = [this]() { this->CloseButton_OnClick(); };

	commandLister = om->CreateCommandLister();
}

void MinigameTemplateMenu::OnUpdate()
{
	if (util->IsConsoleDrawn())
		return;

	if (codeEditor != nullptr)
	{
		if(showCommandLister)
			scr->drawTop(*codeEditor);
		else
		{
			scr->drawBottom(*codeEditor);
			RemoveButton->SetEnabledState(!codeEditor->IsBlankCommandSelected());
		}
	}

	if(commandLister != nullptr && showCommandLister)
		scr->drawBottom(*commandLister);

	if (AddButton != nullptr)
		scr->drawBottom(*AddButton);

	if (RemoveButton != nullptr)
		scr->drawBottom(*RemoveButton);

	if (closeButton != nullptr && showCommandLister)
		scr->drawBottom(*closeButton);
}

//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
MinigameTemplateMenu::~MinigameTemplateMenu()
{
	om->DeleteCodeEditor(codeEditor);
	om->DeleteCommandLister(commandLister);
	om->DeleteButton(AddButton);
	om->DeleteButton(RemoveButton);
	om->DeleteButton(closeButton);
}

void MinigameTemplateMenu::AddButton_OnClick()
{
	showCommandLister = true;
	commandLister->SetActive(true);
	codeEditor->SetActive(false);
	AddButton->SetEnabledState(false);
	RemoveButton->SetEnabledState(false);

	codeEditor->ShiftToTop();
}

void MinigameTemplateMenu::DeleteButton_OnClick()
{
	codeEditor->removeCommand();
}

void MinigameTemplateMenu::CloseButton_OnClick()
{
	commandLister->SetActive(false);
	codeEditor->SetActive(true);
	codeEditor->ShiftToBottom();
	AddButton->SetEnabledState(true);
	RemoveButton->SetEnabledState(true);

	scr->clear();

	showCommandLister = false;
}

void MinigameTemplateMenu::AddCommand(std::string command)
{
	codeEditor->addCommand(command);
	commandLister->SetActive(false);
	codeEditor->SetActive(true);
	codeEditor->ShiftToBottom();
	AddButton->SetEnabledState(true);
	RemoveButton->SetEnabledState(true);

	scr->clear();

	showCommandLister = false;
}