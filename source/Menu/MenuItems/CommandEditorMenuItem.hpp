#pragma once
#include "../../m3diaLibCI/commandEditor.hpp"
#include "../MenuItem.hpp"

class CommandEditorMenuItem : public m3dCI::CommandEditor, public MenuItem
{
private:
	void HandleClick(int x, int y);

public:
	CommandEditorMenuItem(CommandObject* command);

	//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
	~CommandEditorMenuItem();

	bool PointIntersection(int px, int py);
};