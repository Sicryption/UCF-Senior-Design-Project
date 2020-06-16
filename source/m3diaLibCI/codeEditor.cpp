#include "codeEditor.hpp"

namespace m3dCI
{
	#define TOPSCREEN_WIDTH 400
	#define BOTTOMSCREEN_WIDTH 320
	#define TOPSCREEN_HEIGHT 240
	#define BOTTOMSCREEN_HEIGHT 240

	CodeEditor::CodeEditor(int px, int py, int pw, int ph, int p_borderWidth)
		: m3d::Drawable()
	{
		x = px;
		y = py;
		w = pw;
		h = ph;
		borderWidth = p_borderWidth;
		cellsTall = ph / CELL_HEIGHT;

		borderRectangle = new m3d::Rectangle(px, py, pw, ph, m3d::Color(0, 0, 0));
		innerRectangle = new m3d::Rectangle(px + p_borderWidth, py + p_borderWidth, pw - (p_borderWidth * 2), ph - (p_borderWidth * 2), m3d::Color(255, 255, 255));
	}

	CodeEditor::~CodeEditor()
	{
		delete(borderRectangle);
		delete(innerRectangle);

		for (unsigned int i = 0; i < commands.size(); i++)
		{
			delete(commands[i]);
		}
	}

	void CodeEditor::draw(m3d::RenderContext t_context)
	{
		if(borderRectangle != nullptr)
			borderRectangle->draw(t_context);

		if (innerRectangle != nullptr)
			innerRectangle->draw(t_context);

		for (unsigned int i = 0; (i < commands.size()) && (CELL_HEIGHT * i < BOTTOMSCREEN_HEIGHT); i++)
		{
			commands[i]->draw(t_context);
		}
	}

	void CodeEditor::addCommand(std::string command, int position)
	{
		m3dCI::CommandObject* obj = new m3dCI::CommandObject(x, y + CELL_HEIGHT * commands.size(), w, CELL_HEIGHT, command, false);

		if (position < 0)
			commands.push_back(obj);
		else
			commands.insert(commands.begin() + position, obj);
	}
}
