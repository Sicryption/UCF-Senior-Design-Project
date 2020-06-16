#include "minigameTemplateMenu.hpp"

MinigameTemplateMenu::MinigameTemplateMenu(m3d::Screen* screen) :
	Menu(screen)
{
	codeEditor = new m3dCI::CodeEditor(5, 5, (BOTTOMSCREEN_WIDTH * 0.75) - 10, BOTTOMSCREEN_HEIGHT - 10, 1);

	codeEditor->addCommand("Circle MyCircle");
	codeEditor->addCommand("Red");
	codeEditor->addCommand("Left 5");
	codeEditor->addCommand("Right 15");
}

void MinigameTemplateMenu::OnUpdate()
{
	if (util->IsConsoleDrawn())
		return;

	if(codeEditor != nullptr)
		scr->drawBottom(*codeEditor);
}

//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
MinigameTemplateMenu::~MinigameTemplateMenu()
{
	delete(codeEditor);
}