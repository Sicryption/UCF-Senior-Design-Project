#include "menu.hpp"

class MainMenu : public Menu
{
	private:
		m3dCI::Text* StartupText;
	public:
		MainMenu(m3d::Screen* screen);
		~MainMenu();
		
		void OnUpdate();
		
		void Destroy();
};