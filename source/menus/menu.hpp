#include "../util.hpp"
#include "../m3diaLibCI/text.hpp"

#include <m3dia.hpp>

enum class MenuState 
{ 
	MainMenu, 
	MinigameSelect,
	Testing
};

class Menu
{
	protected:
		Util* util;
		m3d::Screen* scr;
	public:
		Menu(Screen* screen);
		virtual ~Menu();
		
		virtual void OnUpdate() = 0;
		
		virtual void Destroy() = 0;
};