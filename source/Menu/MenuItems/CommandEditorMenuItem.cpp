#include "CommandEditorMenuItem.hpp"

#include "../../commands/commands.h"

CommandEditorMenuItem::CommandEditorMenuItem(CommandObject* command)
	: CommandEditor(command), MenuItem()
{
	SetOnRelease([&](int x, int y) 
	{
		if (GetActive())
			HandleClick(x, y); 
	});
}

//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
CommandEditorMenuItem::~CommandEditorMenuItem()
{

}

bool CommandEditorMenuItem::PointIntersection(int px, int py)
{
	return true;
	if (px >= XStart && px <= XStart + CELL_WIDTH && py >= YStart && py <= YStart + (CELL_HEIGHT * (command->getParamNames().size() + 1)))
		return true;
}

void CommandEditorMenuItem::HandleClick(int x, int y)
{
	if (PointIntersection(x, y))
	{
		int selected = (y - YStart) / CELL_HEIGHT;

		if (selected > 0)
		{
			m3d::SoftwareKeyboard sk;

			sk.darkenTop(false);
			sk.allowBlank(false);
			sk.allowEmpty(false);
			sk.allowHome(false);
			sk.setInitialText(command->getParams()[selected - 1]);
			sk.display();

			if (sk.getLastButton() != m3d::SoftwareKeyboard::Button::Right)
			{
				Util::PrintLine("Keyboard Canceled");
				return;
			}
			else
			{
				command->setParam(selected - 1, sk.getLastInput());

				isComplete = true;
			}
		}
		else
		{

		}
	}
}