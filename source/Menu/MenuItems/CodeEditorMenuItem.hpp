#pragma once
#include "../../m3diaLibCI/codeEditor.hpp"
#include "../MenuItem.hpp"

class CodeEditorMenuItem : public m3dCI::CodeEditor, public MenuItem
{
private:
public:
	CodeEditorMenuItem(int px, int py, int p_borderWidth);

	//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
	~CodeEditorMenuItem();

	bool PointIntersection(int px, int py);

	void ShiftToTop();
	void ShiftToBottom();
};